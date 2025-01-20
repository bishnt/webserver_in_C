#ifndef server_h
#define server_h

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>


struct server
{
    int domain;
    int service;
    int protocol;
    u_long interfce;
    int port;
    int backlog;

    SOCKET socket;

    struct sockaddr_in address;

    void(*launch)(void);
};

struct server server_constructor(int domain, int service, int protocol, u_long interfce, int port, int backlog, void(*launch)(void));

#endif /*server_h*/