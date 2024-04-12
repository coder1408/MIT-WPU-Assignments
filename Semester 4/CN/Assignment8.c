#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");

    // Accept an incoming connection
    socklen_t addr_len = sizeof(client_addr);
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Communication loop
    while (1)
    {
        // Receive message from client
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0)
        {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }
        printf("Client: %s\n", buffer);

        // Send message to client
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (send(client_socket, buffer, strlen(buffer), 0) < 0)
        {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
    }

    // Close the sockets
    close(server_socket);
    close(client_socket);

    return 0;
}
