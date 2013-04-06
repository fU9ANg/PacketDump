
#include "pkt_global.h"
#include "pkt_lock.h"
#include "pkt_queue.h"
#include "pkt_logger.h"
#include "pkt_task.h"
#include "pkt_memman.h"
#include "pkt_pool.h"
#include "pkt_common.h"

int main()
{
#if 1
    LOG->out ("askdjfksjdf");
    LOG->clear ();

    LOG->out ("11111111111");
    LOG->out ("2222222222");
#endif
    LOG->out ("dkfdkfj");

    LOG->error ("%s, %d", "abc", 10);
    LOG->warning (FMT"%f, %u", FFL, 120012.f, 19);
}
#if 0
void sig1 (int sig)
{
    printf ("get exit signal\n");
    raise (SIGKILL);
    return;
}

int main (int argc, char** argv)
{
    signal (SIGINT,  SIG_IGN);
    signal (SIGPIPE, SIG_IGN);
    signal (SIGQUIT, SIG_IGN);
    signal (SIGTERM, sig1);

    d2ThreadPool* threadPool = new d2ThreadPool(100);
    threadPool->runAll ();
    d2EvLoopTask *   evLoopTask = new d2EvLoopTask ("127.0.0.1", 2300);
    d2FTPTask *      ftpTask    = new d2FTPTask ();
    d2SendTask *      sendTask    = new d2SendTask ();
    threadPool->joinTask (evLoopTask);
    threadPool->joinTask (ftpTask);
    threadPool->joinTask (sendTask);


    threadPool->reSize ((unsigned int)3);

    while (true)
    {
        cout << "<<<<<<< main loop >>>>>>>" << endl;
        sleep (3);
    }
    threadPool->killAll ();
    return (0);
}
#endif
