
#include "pkt_capture.h"
#include "pkt_memman.h"
#include "pkt_queue.h"
#include "pkt_common.h"

int pkt_capture::run (void* data)
{
    // TODO:

    while (true)
    {
        pkt_buf* buf;
        if (PKTCOMMON->capture_queue.pop (buf, 2) == false)
        {
            continue;
        }
    }

    return (0);
}
