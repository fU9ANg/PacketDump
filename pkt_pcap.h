
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : The pcap (libpcap) task
 */

#ifndef _PKT_PCAP_H
#define _PKT_PCAP_H

#include <pcap.h>
#include "pkt_global.h"
#include "pkt_task.h"

class pkt_pcap : public pkt_task
{
    public:
        pkt_pcap() : pkt_task (1)
        {
            lookupdev();
            open_live();
        }
        ~pkt_pcap () {}
        virtual int run (void* data);

    public:
        static void callback (u_char* useless, const struct pcap_pkthdr* pkthdr, const u_char* packet);

        // grab a device to peak into ...
        bool lookupdev (void);

        // open device for reading ...
        bool open_live (void);

    private:
        char*   dev;
        char    errbuf[PCAP_ERRBUF_SIZE];
        pcap_t* descr;
};

#endif //_PKT_PCAP_H
