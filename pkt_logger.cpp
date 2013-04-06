
/*
 * pkt_logger.cpp
 */

#include "pkt_logger.h"

pkt_logger* pkt_logger::static_logger;

pkt_logger* pkt_logger::instance(const string& filename)
{
    if (static_logger == NULL)
        static_logger = new pkt_logger(filename);

    return (static_logger);
}

void pkt_logger::set_logfile (const string& filename)
{
    //pkt_guard guard (lock);
    if (!filename.empty())
    {
        this->filename = filename;
    }
    if (f != NULL)
    {
        fclose (f);
        open_file (filename);
    }
}

void pkt_logger::clear (void)
{
    if (f != NULL)
    {
        fclose (f);
    }

    if ((f = fopen (this->filename.c_str(), "wt+")) == NULL)
    {
        fprintf (stderr, "don't opening log file: %s\n", filename.c_str());
        return;
    }
    fprintf(f, "%s\n", "PacketDump-Logfile:");
}

void pkt_logger::print (const string& str, const char* file, const char* func, unsigned int line)
{
    //pkt_guard guard (lock);
    if (this->f != NULL)
    {
        fprintf (f, "%s:%s(%d)\nLOG:'%s'\n", \
            file, \
            func, \
            line, \
            str.c_str());
    }
}

pkt_logger::~pkt_logger (void)
{
    if (f != NULL)
        fclose (f);
}

void pkt_logger::open_file (const string& filename)
{
    //pkt_guard guard (lock);
    f = fopen (filename.c_str(), "at+");
    if (f == NULL) {
        fprintf (stderr, "don't open log file: %s\n", filename.c_str());
        abort ();
    }
}
pkt_logger::pkt_logger (const string& filename)
{
    //pkt_guard guard (lock);
    this->filename = filename;
    open_file (this->filename);
}
