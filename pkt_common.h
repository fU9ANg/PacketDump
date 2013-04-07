
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : Common class contain memory manager and capture queue
 */

#ifndef _PKT_COMMON_H
#define _PKT_COMMON_H

#include "pkt_global.h"
#include "pkt_queue.h"
#include "pkt_memman.h"

class pkt_common
{
    public:
        static class pkt_common* instance();
        ~pkt_common();

    public:
        pkt_memman<pkt_buf> memories;
        pkt_queue<pkt_buf*> capture_queue;

    private:
        pkt_common ();
        static class pkt_common* static_instance;
};

#define PKTCOMMON pkt_common::instance()

#endif //_PKT_COMMON_H
