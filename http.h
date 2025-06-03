#ifndef HTTP_H
#define HTTP_H

#include<stdio.h>

typedef struct { 
    char method[10]; // GET, POST
    char path[1024]; //The URL
} HttpRequest;

void handle_request(int client_fd);
void parse_request(const char*raw, HttpRequest* req);

#endif