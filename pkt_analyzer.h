
#ifndef _PKT_ANALYZER_H
#define _PKT_ANALYZER_H

#include "pkt_global.h"
#include "pkt_task.h"

class pkt_analyzer : public pkt_task
{
    public:
        pkt_analyzer() : pkt_task (1)
        {
        }
        ~pkt_analyzer () {}
        virtual int run (void* data);

    public:
};

#endif //_PKT_ANALYZER_H
