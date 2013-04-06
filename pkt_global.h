
/*
 * pkt_global.h
 */

#ifndef _PKT_GLOBAL_H
#define _PKT_GLOBAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <pthread.h>
#include <list>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <queue>
#include <pthread.h>
#include <list>
#include <signal.h>
#include <fcntl.h>

using namespace std;

#define SIGOUTTHREAD 0x11
#define BUFFSIZE    2048
#define BUFFNUMB    1024

#endif //_PKT_GLOBAL_H
