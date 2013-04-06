
#ifndef _PKT_CAPTURE_H
#define _PKT_CAPTURE_H

#include "pkt_global.h"
#include "pkt_task.h"

class pkt_capture : public pkt_task
{
    public:
        pkt_capture() : pkt_task (1)
        {
        }
        ~pkt_capture () {}
        virtual int run (void* data);

    public:
};

#endif //_PKT_CAPTURE_H
