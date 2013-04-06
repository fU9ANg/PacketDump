
#include "pkt_lock.h"

pkt_lock::pkt_lock (void)
{
    pthread_mutex_init (&mutex, NULL);
}

pkt_lock::~pkt_lock (void)
{
    pthread_mutex_destroy (&mutex);
}

void pkt_lock::lock (void)
{
    pthread_mutex_lock (&mutex);
}

void pkt_lock::unlock (void)
{
    pthread_mutex_unlock (&mutex);
}

pkt_guard::~pkt_guard (void)
{
    lock.unlock ();
}
