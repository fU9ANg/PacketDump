
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : Common class contain memory manager and capture queue
 */

#include "pkt_common.h"

class pkt_common* pkt_common::static_instance = NULL;

class pkt_common* pkt_common::instance()
{
    if (static_instance == NULL)
        static_instance = new pkt_common();

    return (static_instance);
}

pkt_common::pkt_common()
{
}

pkt_common::~pkt_common()
{
}
