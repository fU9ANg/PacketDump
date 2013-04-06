
/*
 * pkt_logger.h
 */

#ifndef _PKT_LOGGER_H
#define _PKT_LOGGER_H

#include "pkt_global.h"
#include "pkt_lock.h"

class pkt_logger
{
#define out(s) print (s, __FILE__, __FUNCTION__, __LINE__)

    public:
        static pkt_logger* instance(const string& filename = "PacketDump_L0g");

        void set_logfile (const string& filename);
        void clear (void);
        void print (const string& str, const char* file, const char* func, unsigned int line);
        ~pkt_logger (void);

    private:
        pkt_logger (const string& filename);
        void open_file (const string& filename);

    public:
        FILE* f;
        
    private:
        static pkt_logger* static_logger;
        string filename;
        pkt_lock lock;
};

#define LOG pkt_logger::instance()

#endif //_PKT_LOGGER_H
