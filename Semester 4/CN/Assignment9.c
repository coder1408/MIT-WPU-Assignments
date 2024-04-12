#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to convert a string to lowercase
void toLower(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
}

int main()
{
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == 0)
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

    printf("UDP Server waiting for incoming connections on port %d...\n", PORT);

    // Receive message from client
    socklen_t addr_len = sizeof(client_addr);
    if (recvfrom(server_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len) < 0)
    {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    printf("Received string from client: %s\n", buffer);

    // Convert received string to lowercase
    toLower(buffer);

    // Send lowercase string back to client
    if (sendto(server_socket, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0)
    {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    printf("Lowercase string sent to client: %s\n", buffer);

    // Close the socket
    close(server_socket);

    return 0;
}
