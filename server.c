#include "server.h"
#include<stdio.h>
#include<stdlib.h>

struct server server_constructor(int domain, int service, int protocol, u_long interfce, int port, int backlog, void(*launch)(void))
{
    struct server Server;

    Server.domain=domain;
    Server.service=service;
    Server.protocol=protocol;
    Server.interfce=interfce;
    Server.port=port;
    Server.backlog=backlog;

    Server.address.sin_family = domain;
    Server.address.sin_port = htons(port);
    Server.address.sin_addr.s_addr = htonl(interfce);

    Server.socket = socket(domain, service, protocol);

    if(Server.socket==0)
    {
        perror("failed to connect socket \n");
        exit(1);
    }

   if(bind(Server.socket, (struct sockaddr *)&Server.address,
   sizeof(Server.address))<0)
   {
    perror("failed to bind socket...\n");
    exit(1);
   }

   listen(Server.socket, Server.backlog);

    return Server;
};  