
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : The pcap (libpcap) task
 */

#include "pkt_logger.h"
#include "pkt_pcap.h"
#include "pkt_memman.h"
#include "pkt_queue.h"
#include "pkt_common.h"

void pkt_pcap::callback (u_char* useless, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    cout << "pkt_pcap callback: " << pthread_self() << " caplen:" << pkthdr->caplen << " len:" << pkthdr->len << endl;
    
#if 0
    pkt_buf* buf = PKTCOMMON->memories.malloc ();
    if (buf == NULL)
    {
        printf ("out of memory\n");
        return;
    }
    if (pkthdr->caplen != pkthdr->len)
    {
        LOG->warning (FMT"%s", FFL, "WARNING: capture length not equal packet' length");
    }

    (void) memcpy ((u_char*) buf->data(), (u_char*) pkthdr, sizeof (struct pcap_pkthdr));
    (void) memcpy ((u_char*) buf->data() + sizeof (struct pcap_pkthdr), packet, \
                    pkthdr->len);
    PKTCOMMON->capture_queue.push (buf);
#endif
}

bool pkt_pcap::lookupdev (void)
{
    dev = pcap_lookupdev (errbuf);
    if (!dev)
    {
        printf ("ERROR: pcap_lookupdev(): %s\n", errbuf);
        return false;
    }

    return true;
}

bool pkt_pcap::open_live (void)
{
    descr = pcap_open_live (dev, BUFSIZ, 0, -1, errbuf);
    if (!descr)
    {
        printf ("ERROR: pcap_open_live(): %s\n", errbuf);
        return false;
    }
    return true;
}

int pkt_pcap::run (void* data)
{
    pcap_loop (descr, -1, pkt_pcap::callback, NULL);
    pcap_close (descr);
    return (0);
}
