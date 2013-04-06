
#include "pkt_memman.h"

pkt_buf::pkt_buf (unsigned int size)
{
    this->size = size;
    ptr = malloc (size);
}

pkt_buf::~pkt_buf ()
{
    if (ptr)
    {
        free (ptr);
        ptr = NULL;
    }
}

void* pkt_buf::data ()
{
    if (ptr)
        return ptr;
    return NULL;
}

void  pkt_buf::clear ()
{
    if (ptr)
        (void) memset (ptr, 0x00, size);
}

unsigned int pkt_buf::get_size (void)
{
    return size;
}

void pkt_buf::set_size (unsigned int siz)
{
    void* tmp = NULL;
    if (siz > 0)
    {
        void *temp = malloc (siz);
        (void) memset (temp, 0x00, siz);
        (void) memcpy (temp, ptr, size<siz?size:siz);

        tmp = ptr;

        ptr = temp;
        free (tmp);
    }
}
