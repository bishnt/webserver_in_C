#include "router.h"
#include "http.h"
#include "file_server.h"

#include <string.h>
#include <unistd.h>

#define API_PATH "/api/random" //change this to change the path to be handled

void route_request(int client_fd, HttpRequest* req) {

    if(strcmp(req->method, "GET") == 0)
    {
        if (strcmp(req->path, "/") == 0)
        {
            handle_root(client_fd);
        }
        else if(strcmp(req->path, API_PATH) == 0){
            handle_random_api(client_fd);
        }
        else
        {
            serve_file(client_fd, req->path); // serves the file present in public
        }

    }
    else{
        const char* not_allowed = 
            "HTTP/1.1 405 Method Not Allowed\r\n"
            "Content-Length: 23\r\n"
            "Content-Type: text/plain\r\n"
            "\r\n"
            "405 Method Not Allowed";

        write(client_fd, not_allowed, strlen(not_allowed));
    }

}

void handle_root(int client_fd) {
    const char* response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Length: 12\r\n"
        "Content-Type: text/plain\r\n"
        "\r\n"
        "Hello World!";
    write(client_fd, response, strlen(response));
}

void handle_random_api(int client_fd) {
    const char* json_response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Length: 22\r\n"
        "Content-Type: application/json\r\n"
        "\r\n"
        "{\"message\":\"Hi there\"}";
    write(client_fd, json_response, strlen(json_response));
}