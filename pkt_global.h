
/*
 * This part of PacketDump
 *
 * Author: fU9ANg
 * E-mail: bb.newlife@gmail.com
 * Descr : Global header file, variable and macro. etc.
 */

#ifndef _PKT_GLOBAL_H
#define _PKT_GLOBAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
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
#include <sys/select.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <queue>
#include <pthread.h>
#include <list>
#include <map>
#include <signal.h>
#include <fcntl.h>
#include <pcap/bpf.h>

using namespace std;

#define SIGOUTTHREAD 0x11
#define BUFFSIZE    2048
#define BUFFNUMB    1024

#endif //_PKT_GLOBAL_H
