
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : Thread Pool
 */

#include "pkt_pool.h"

bool pool::init_threads ()
{
    for (unsigned int i=0; i<thread_count; i++)
    {
        pthread_t pid = 0;
        pthread_create (&pid, 0, pool::function, this);
        cout << "pthread_id: " << pid << endl;
        threads.push_back (pid);
    }
    return true;
}
bool pool::run ()
{
    return (init_threads());
}
bool pool::join (pkt_task* t)
{
    pkt_guard guard (lock);
    return (tasks.push (t));
}
int pool::kill_all (void)
{
    pkt_guard guard (lock);
    while (threads.size() != 0)
    {
        pthread_kill (threads.front(), SIGOUTTHREAD);
        threads.pop_front();
    }
    return (0);
}
bool pool::stop_all (void)
{
    is_exit = true;
    while (get_thread_count() != 0)
    {
        usleep (100);
    }
    return true;
}
void pool::out_handler (int sig)
{
    printf ("[%ld] thread exit\n", pthread_self ());
    pthread_exit (NULL);
    return;
}

int pool::get_thread_count()
{
    pkt_guard guard (lock);
    return threads.size();
}
int pool::get_task_count ()
{
    pkt_guard guard (lock);
    return tasks.count();
}
void* pool::function (void* data)
{
    (void) signal (SIGOUTTHREAD, pool::out_handler);
    pool* p = static_cast<pool*> (data);
    pkt_task* t = NULL;
    while (!p->is_exit)
    {
        if (p->tasks.pop (t, 2) == true && t)
        {
            t->run (NULL);
            if (t->is_exit ())
            {
                delete t;
                t = NULL;
            }
        }
        else
        {
            pkt_guard* pguard = new pkt_guard (p->lock);
            if (p->thread_count < p->threads.size())
            {
                p->threads.remove (pthread_self());
                delete pguard;
                return NULL;
            }
            delete pguard;
        }
    }
    pkt_guard guard (p->lock);
    p->threads.remove (pthread_self ());
    return NULL;
}

bool pool::reset_size (unsigned int num)
{
    pkt_guard guard (lock);
    unsigned int c = num - thread_count;
    if (c > 0)
    {
        for (unsigned int i =0; i< c; i++)
        {
            pthread_t pid = 0;
            pthread_create (&pid, 0, pool::function, this);
            threads.push_back (pid);
        }
    }
    thread_count = num;
    return true;
}
