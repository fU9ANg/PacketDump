
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : Abstract thread task
 */

#ifndef _PKT_TASK_H
#define _PKT_TASK_H

#include "pkt_global.h"

class pkt_task
{
    public:
        pkt_task (unsigned int e = 1) : exit(e) {}
        virtual ~pkt_task (void) {};
        virtual int run (void* data) = 0;
        unsigned int is_exit (void) { return exit; }

    private:
        unsigned int exit;
};

#endif //_PKT_TASK_H
