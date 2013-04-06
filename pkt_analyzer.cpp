
#include "pkt_analyzer.h"
#include "pkt_memman.h"
#include "pkt_queue.h"
#include "pkt_common.h"

int pkt_analyzer::run (void* data)
{
    while (true)
    {
        pkt_buf* buf;
        if (PKTCOMMON->capture_queue.pop (buf, 2) == false)
        {
            // TODO: analysis
            continue;
        }
    }

    return (0);
}
