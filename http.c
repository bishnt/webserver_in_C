#include "http.h"
#include "router.h"

#include<stdio.h>
#include<string.h>
#include<unistd.h>

void parse_request(char*raw, HttpRequest* req){

      // Get the first line of the request
      char *line = strtok(raw, "\r\n");

      if (line == NULL) return;
  
      // Tokenization process
      char *method = strtok(line, " ");
      char *path = strtok(NULL, " ");
  
      if (method) strncpy(req->method, method, sizeof(req->method) - 1);
      if (path) strncpy(req->path, path, sizeof(req->path) - 1);
}

void handle_request(int client_fd) {
    char buffer[4096]; //the request sent by client is reads into this buffer
    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) -1);
    buffer[bytes_read] = '\0'; //add a terminator in the buffer to make it a valid string

    HttpRequest req; //included datatype in http.h
    parse_request(buffer, &req);

    route_request(client_fd, &req); ////defined in router.c
}