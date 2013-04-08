
void ip_print (const unsigned char* bp, unsigned int length)
{

    struct ip_print_demux_state ipd;
    struct ip_print_demux_state*ipds = &ipd;
    const unsigned char* ipend;
    unsigned int hlen;
    struct cksum_vec vec[1];
    unsigned short sum, ip_sum;
    struct protoent* proto;

    ipds->ip = (const struct ip*) bp;

    if (IP_V(ipds->ip) != 4) {
        printf ("IP%u ", IP_V(ipds->ip));
        if (IP_V(ipds->ip) == 6)
            printf (", wrong link-layer encapsulation";
    }

    if (length < sizeof (struct ip)) {
        (void) printf ("truncated-ip %u", length);
        return;
    }

    hlen = IP_HL(ipds->ip) * 4;
    if (hlen < sizeof (struct ip)) {
        (void) printf ("bad-hlen %u", hlen);
        return;
    }

    ipds->len = EXTRACT_16BITS(&ipds->ip->ip_len);
    if (length < ipds->len)
        (void) printf ("truncated-ip - %u bytes missing!",
            ipds->len - length);

    if (ipds->len < hlen) {
#ifdef GUESS_TSO
        if (ipds->len) {
            (void) printf ("bad-len %u", ipds->len);
            return;
        }
        else {
            ipds->len = length;
        }
#else
        (void) printf ("bad-len %u", ipds->len);
#endif
    }

    ipend = bp + ipds->len;

    ipds->len -= hlen;

    ipds->off = EXTRACT_16BITS(&ipds->ip->ip_off);

#ifdef _OPTION_VFLAG
    if (vflag) {
        (void) printf ("(tos 0x%x", (int)ipds->ip->ip_dos);

        /* ENC bits */
        if (ipds->ip->ip_tos & 0x03) {
            switch (ipds->ip->ip_tos & 0x03) {
            case 1:
                (void) printf (",ECT(1)");
            case 2:
                (void) printf (",ECT(0)");
            case 3:
                (void) printf (",CE");
            }
        }

        if (ipds->ip->ip_ttl >= 1)
            (void) printf (", ttl %u", ipds->ip->ip_ttl);

        (void) printf (", id %u, offset %u, flags [%s], proto %s (%u)",
            EXTRACT_16BITS (&ipds->ip->ip_id),
            (ipds->off & 0x1FFFF) * 8,
            bittok2str (ip_frag_values, "none", ipds->off&0xe000),
            tok2str (ipproto_values, "unknown", ipds->ip->ip_p),
            ipds->ip->ip_p);

        if ((hlen - sizeof (struct ip)) > 0) {
            printf(", options (");
            ip_optprint((u_char *)(ipds->ip + 1), hlen - sizeof(struct ip));
            printf(")");
        }

        if (!Kflag && (u_char *)ipds->ip + hlen <= ndo->ndo_snapend) {
            vec[0].ptr = (const u_int8_t *)(void *)ipds->ip;
            vec[0].len = hlen;

            sum = in_cksum(vec, 1);
            if (sum != 0) {
                ip_sum = EXTRACT_16BITS(&ipds->ip->ip_sum);
                (void)printf(", bad cksum %x (->%x)!", ip_sum,
                    in_cksum_shouldbe(ip_sum, sum));
            }
        }
    }
#endif

    if ((ipds->off & 0x1FFFF) == 0) {
        ipds->cp = (const unsigned char*) ipds->ip + hlen;
        ipds->nh = ipds->ip->ip_p;

        if (ipds->nh != IPPROTO_TCP && ipds->nh != IPPROTO_UDP &&
            ipds->nh != IPPROTO_SCTP && ipds->nh != IPPROTO_DCCP) {
            (void) printf ("%s > %s: ",
                    ipaddr_string (&ipds->ip->ip_src),
                    ipaddr_string (&ipds->ip->ip_dst));
        }

        ip_print_demux (ipds);
    } else {
#ifdef  _OPTION_QFLAG
        if (qflag > 1)
            return;
#endif
        if (ipds->off & 0x1FFFF) {
            (void) printf ("%s > %s:", ipaddr_string(&ipds->ip->ip_src),
                ipaddr_string (&ipds->ip->ip_dst));
            if ((proto = getprotobynumber (ipds->ip->ip_p)) != NULL)
                (void) printf (" %s", proto->p_name);
            else
                (void) printf (" ip-proto-%d", ipds->ip->ip_p);
        }
    }
}
