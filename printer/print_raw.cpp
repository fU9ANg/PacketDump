
#include "handle_analyzer.h"

//DLT_RAW
void handle_analyzer::print_raw(pkt_buf* buf)
{
#if 0
    unsigned int length = (struct pcap_pkthdr*) \
        ((char*)buf->data() + sizeof (PACKET_HEAD))->len;
    unsigned char* bp = (char*)buf->data() + \
        sizeof (PACKET_HEAD) + sizeof (struct pcap_pkthdr);

    //TODO:
    struct ip* ip, hdr;

    ip = (struct ip*) bp;

    if (length < 4) {
        (void) printf ("truncated-ip %d", length);
        return;
    }

    memcpy (&hdr, (char*)ip, 4);
    switch (IP_V(&hdr)) {
    case 4:
        ip_print (bp, length);
        return;
    case 6:
        ip6_print (bp, length);
        return;
    default:
        (void) printf ("unknown ip %d", IP_V(&hdr));
        return;
    }
#endif
}
