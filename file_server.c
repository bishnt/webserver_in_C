#include "file_server.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

void serve_file(int client_fd, const char *path) {
    // Prefix the path with the directory
    char full_path[512];
    snprintf(full_path, sizeof(full_path), "./public%s", path);

    // Open the file
    int file_fd = open(full_path, O_RDONLY);
    if (file_fd == -1) {
        const char *not_found =
            "HTTP/1.1 404 Not Found\r\n"
            "Content-Length: 13\r\n"
            "Content-Type: text/plain\r\n"
            "\r\n"
            "404 Not Found";
        write(client_fd, not_found, strlen(not_found));
        return;
    }

    // Get the file size
    struct stat file_stat;
    fstat(file_fd, &file_stat);
    int file_size = file_stat.st_size;

    // Allocate buffer and read file contents
    char *file_buffer = malloc(file_size);
    read(file_fd, file_buffer, file_size);

    // Send HTTP headers
    char header[256];
    snprintf(header, sizeof(header),
             "HTTP/1.1 200 OK\r\n"
             "Content-Length: %d\r\n"
             "Content-Type: text/html\r\n"
             "\r\n", file_size);

    write(client_fd, header, strlen(header));
    write(client_fd, file_buffer, file_size);

    // Cleanup
    close(file_fd);
    free(file_buffer);
}
