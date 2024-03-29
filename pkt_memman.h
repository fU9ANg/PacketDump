
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : The memory manager
 */

#ifndef _PKT_MEMMAN_H
#define _PKT_MEMMAN_H

#include "pkt_global.h"
#include "pkt_lock.h"

class pkt_buf
{
    public:
        pkt_buf (unsigned int size = BUFFSIZE);
        ~pkt_buf ();

        void* data ();
        void  clear ();
        unsigned int get_size (void);
        void set_size (unsigned int size);

    private:
        void* ptr;
        unsigned int size;
};

template<typename T>
class pkt_memman
{
    typedef std::queue<T*> queue_bufs;

    public:
        pkt_memman (unsigned int count = BUFFNUMB)
        {
            pkt_guard guard (lock);
            this->count = count;
            for (unsigned int i=0; i<this->count; i++)
            {
                T* t = new T;
                bufs.push (t);
            }
        }

        ~pkt_memman (void)
        {
            pkt_guard guard (lock);
            for (unsigned int i=0; i<this->count; i++)
            {
                T* t = bufs.front();
                bufs.pop();
                delete t;
            }
        }

        T* malloc (void)
        {
            pkt_guard guard (lock);
            if (bufs.empty())
                return NULL;

            T* t = bufs.front();
            bufs.pop();
            return t;
        }

        bool free (T* t)
        {
            pkt_guard guard (lock);
            if (t == NULL)
                return false;

            bufs.push (t);
            return true;
        }

        unsigned int get_count (void)
        {
            pkt_guard guard (lock);
            return count;
        }

        unsigned int get_usedcount (void)
        {
            pkt_guard guard (lock);
            return (count - bufs.size());
        }
    private:
        queue_bufs bufs;
        unsigned int count;
        pkt_lock lock;
};

#endif //_PKT_MEMMAN_H
