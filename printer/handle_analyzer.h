
#ifndef _HANDLE_ANALYZER_H
#define _HANDLE_ANALYZER_H

#include "pkt_global.h"
#include "pkt_memman.h"

typedef void (*handler_t)(pkt_buf*);
typedef std::map<int, handler_t> HANDLERMAP;

class handle_analyzer
{
    public:
        #define ANALYZERHANDLE(name, handle) static void handle (pkt_buf* buf)
        #include "PROTOCOLHANDLER"
        #undef ANALYZERHANDLE

    public:
        static handler_t get_handler (int type)
        {
            HANDLERMAP::iterator it = handle_analyzer::handlermap.find(type);
            if (it != handle_analyzer::handlermap.end())
                return it->second;

            return NULL;
        }

        static void init_handlers (void)
        {
            #define ANALYZERHANDLE(name, handle) \
                handle_analyzer::set_handler (name, &handle_analyzer::handle)
            #include "PROTOCOLHANDLER"
            #undef ANALYZERHANDLE
        }

        static void set_handler (int type, handler_t handler)
        {
            if (handler != NULL)
                handle_analyzer::handlermap.insert (std::pair<int, handler_t>(type, handler));
        }

    private:
        static HANDLERMAP  handlermap;
};

#endif //_HANDLE_ANALYZER_H
