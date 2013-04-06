
#include "pkt_pcap.h"
#include "pkt_memman.h"
#include "pkt_queue.h"
#include "pkt_common.h"

void pkt_pcap::callback (u_char* useless, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    pkt_buf* buf = PKTCOMMON->memories.malloc ();
    if (buf == NULL)
    {
        printf ("out of memory\n");
        return;
    }
    (void) memcpy ((u_char*) buf->data(), (u_char*) pkthdr, sizeof (struct pcap_pkthdr));
    (void) memcpy ((u_char*) buf->data() + sizeof (struct pcap_pkthdr), packet, \
                    1); // pkthdr->len;
    PKTCOMMON->capture_queue.push (buf);
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
