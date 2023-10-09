#include <stdio.h>       // Provides printf for output
#include <string.h>      // Provides strlen for string length calculation
#include <unistd.h>      // Provides close for closing file descriptors
#include <sys/socket.h>  // Provides socket, bind, listen, accept, and send functions for socket programming
#include <netinet/in.h>  // Provides sockaddr_in structure for socket addresses

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0); // Create socket (address family IPv4, socket type TCP, protocol TCP)
    struct sockaddr_in a = {.sin_family = AF_INET, .sin_port = htons(8080)}; // Define address structure (IPv4, port 8080)

    bind(s, (struct sockaddr *)&a, sizeof(a)); // Bind socket (socket, address, address length)
    listen(s, 1); // Start listening for client connections (socket, max 1 connection in queue)

    int c = accept(s, NULL, NULL); // Accepts connection (socket, address, length)
    char *r = "HTTP/1.1 200 OK\nContent-Length: 18\n\nWe Live!"; // Define HTTP response string
    send(c, r, strlen(r), 0); // Send response (socket, data, data length, flags)

    close(c); // Close client socket
    close(s); // Close server socket
}