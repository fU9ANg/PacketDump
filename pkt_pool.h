
#ifndef _PKT_POOL_H
#define _PKT_POOL_H

#include "pkt_global.h"
#include "pkt_lock.h"
#include "pkt_memman.h"
#include "pkt_task.h"
#include "pkt_queue.h"

class pool
{
    typedef std::list<pthread_t> list_thread;
    typedef pkt_queue<pkt_task*> queue_task;

    public:
        pool (unsigned int num) : thread_count(num)
        {
            is_exit = false;
        }
        ~pool ()
        {
        }

        bool init_threads ();
        bool run ();
        bool join (pkt_task* t);
        int kill_all (void);
        bool stop_all (void);
        static void out_handler (int sig);

        int get_thread_count();
        int get_task_count ();
        static void* function (void* data);

        bool reset_size (unsigned int num);

    private:
        list_thread threads;
        queue_task  tasks;
        unsigned int thread_count;
        pkt_lock lock;
        bool        is_exit;
};

#endif //_PKT_POOL_H
