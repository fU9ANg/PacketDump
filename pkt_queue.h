
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : Queue of task of threads
 */

#ifndef _PKT_QUEUE_H
#define _PKT_QUEUE_H

#include "pkt_global.h"

template<typename TYPE>
class pkt_queue
{
    public:
        pkt_queue (void)
        {
            pthread_mutex_init (&mutex, NULL);
            pthread_cond_init (&cond, NULL);
        }

        ~pkt_queue (void)
        {
            pthread_mutex_destroy (&mutex);
            pthread_cond_destroy (&cond);
        }

        bool push (TYPE t)
        {
            pthread_mutex_lock (&mutex);
            if (q_queue.empty())
            {
                q_queue.push (t);
                pthread_mutex_unlock (&mutex);
                pthread_cond_signal (&cond);
            }
            else
            {
                q_queue.push (t);
                pthread_mutex_unlock (&mutex);
            }

            return (true);
        }

        bool pop (TYPE& pt, unsigned int timeout)
        {
            struct timespec t;
            t.tv_sec = time(NULL)+timeout;
            t.tv_nsec = 0;
            pthread_mutex_lock (&mutex);
            while (q_queue.empty())
            {
                if (pthread_cond_timedwait (&cond, &mutex, &t) != 0)
                {
                    pthread_mutex_unlock (&mutex);
                    return (false);
                }
            }

            pt = q_queue.front ();
            q_queue.pop ();
            pthread_mutex_unlock (&mutex);

            cout << "get task by thread, pid=" << pthread_self () << endl;
            return (true);
        }

        unsigned int count (void)
        {
            pthread_mutex_lock (&mutex);
            unsigned int i = q_queue.size();
            pthread_mutex_unlock (&mutex);

            return (i);
        }

    private:
        pthread_mutex_t mutex;
        pthread_cond_t cond;
        std::queue<TYPE> q_queue;
};

#endif //_PKT_QUEUE_H
