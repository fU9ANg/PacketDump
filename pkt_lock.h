
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : Lock and guard for threads
 */

#include "pkt_global.h"

#ifndef _PKT_LOCK_H
#define _PKT_LOCK_H

class pkt_lock
{
    public:
        pkt_lock (void);
        ~pkt_lock (void);

        void lock (void);
        void unlock (void);

    private:
        pkt_lock (const pkt_lock&);
        const pkt_lock& operator= (const pkt_lock&);
        pthread_mutex_t mutex;
};

class pkt_guard
{
    public:
        explicit pkt_guard (class pkt_lock& l) : lock (l) { lock.lock (); }
        ~pkt_guard (void);

    private:
        pkt_guard (const class pkt_guard&);
        const pkt_guard& operator= (const pkt_guard&);
        class pkt_lock& lock;
};

#endif //_PKT_LOCK_H
