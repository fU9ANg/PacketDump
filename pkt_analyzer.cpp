
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : The protocol analysis task
 */

#include "pkt_analyzer.h"
#include "pkt_memman.h"
#include "pkt_queue.h"
#include "pkt_common.h"

int pkt_analyzer::run (void* data)
{
    while (true)
    {
#if 0
        pkt_buf* buf;
        if (PKTCOMMON->capture_queue.pop (buf, 2) == false)
        {
            // TODO: analysis
            continue;
        }
#endif
        cout << "analyzer.run: " << pthread_self() << "......" << endl;
        sleep (3);
    }

    return (0);
}
