#ifndef ROUTER_H
#define ROUTER_H

#include<stdio.h>

#include "http.h"

void route_request(int client_fd, HttpRequest* req);

void handle_root(int client_fd);
void handle_random_api(int client_fd);

#endif