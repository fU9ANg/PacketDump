
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : PacketDump (packet dump)
 */

#include "pkt_global.h"
#include "pkt_lock.h"
#include "pkt_queue.h"
#include "pkt_logger.h"
#include "pkt_task.h"
#include "pkt_memman.h"
#include "pkt_pool.h"
#include "pkt_common.h"
#include "pkt_pcap.h"
#include "pkt_analyzer.h"

#if 0
int main()
{
    LOG->out ("askdjfksjdf");
    LOG->clear ();

    LOG->out ("11111111111");
    LOG->out ("2222222222");
    LOG->out ("dkfdkfj");

    LOG->error ("%s, %d", "abc", 10);
    LOG->warning (FMT"%f, %u", FFL, 120012.f, 19);
}
#endif
void sig_handler (int sig)
{
    printf ("got exit signal\n");
    raise (SIGKILL);
    return;
}

int main (int argc, char** argv)
{
    signal (SIGINT , SIG_IGN);
    signal (SIGPIPE, SIG_IGN);
    signal (SIGQUIT, SIG_IGN);
    signal (SIGTERM, sig_handler);

    pool* p = new pool(1);
    p->run();

    pkt_pcap* pcap_task = new pkt_pcap();
    pkt_analyzer* analyzer_task = new pkt_analyzer();

    p->join (pcap_task);
    p->join (analyzer_task);

    p->reset_size (2);
    while (1)
    {
        sleep (3);
        cout << "------- main loop -------\n";
    }
    p->stop_all();
    p->kill_all();
    delete p;

    return (0);
}
