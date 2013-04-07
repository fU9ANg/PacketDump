
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
        pkt_buf* buf = NULL;
        if (PKTCOMMON->capture_queue.pop (buf, 2) == false)
        {
            continue;
        }

        PACKET_HEAD* head = (PACKET_HEAD*) buf->data();
        if (head != NULL)
        {
            cout << "analyzer: network type=" << head->nType << endl;
            handler_t handler = handle_analyzer::get_handler (head->nType);
            if (handler == NULL)
            {
                cout << "ERROR: the function pointer is null, nType=" \
                     << head->nType << endl;
                continue;
            }
            handler (buf);
        }
#else
        cout << "analyzer.run: " << pthread_self() << "......" << endl;
        sleep (3);
#endif
    }

    return (0);
}
