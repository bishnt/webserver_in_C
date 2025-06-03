//Entry point: sets up socket, accepts request
#include<stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

typedef struct sockadrr_in{
    sa_family_t family;
    in_port_t port;
    struct in_addr sin_addr;
    unsigned char sin_zero[8];
};

int main(){
    int server_fd; //server file descriptor
    struct sockadrr_in sockaddress;

    //initialize socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET for IPv6, SOCK_STREAM for TCP, 0 for default protocol

    if(server_fd == -1){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    else{
    printf("Socket created successfully \n");
    }

    memset(&sockaddress, 0, sizeof(sockaddress)); //blocks the memory location
    //defining the socket
    sockaddress.family = AF_INET;
    sockaddress.port = htons(8000);
    sockaddress.sin_addr.s_addr = INADDR_ANY;

    //associate socket with local info
    bind(server_fd, (struct sockadrr_in*)&sockaddress, sizeof(sockaddress));

    //make the socket listen to the port

    //listens to server_fd with upto 5 clients in queue
    if(listen(server_fd, 5) == -1) {
        perror("Listen Failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    else{
        printf("listening to the port");
    }

    close(server_fd);
    return 0;
}