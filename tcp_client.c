#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(8080);

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == 0) {
        printf("Connected to the server.\n");

        char buffer[1024];
        recv(clientSocket, buffer, sizeof(buffer), 0);
        printf("Server says: %s\n", buffer);

        close(clientSocket);
    } else {
        perror("Connection failed");
    }

    return 0;
}
