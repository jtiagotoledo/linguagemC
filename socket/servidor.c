#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Falha ao inicializar o Winsock. Erro: %d\n", WSAGetLastError());
        return 1;
    }

    SOCKET servidor_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (servidor_socket == INVALID_SOCKET)
    {
        printf("Erro ao criar o socket. Erro: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    struct sockaddr_in endereco;
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(8080);
    endereco.sin_addr.s_addr = INADDR_ANY;

    memset(&(endereco.sin_zero), '\0', 8);

    if (bind(servidor_socket, (struct sockaddr *)&endereco, sizeof(endereco)) == SOCKET_ERROR)
    {
        printf("Erro no bind. Erro: %d\n", WSAGetLastError());
        closesocket(servidor_socket);
        WSACleanup();
        return 1;
    }

    if (listen(servidor_socket, 3) == SOCKET_ERROR)
    {
        printf("Erro no listen. Erro: %d\n", WSAGetLastError());
        closesocket(servidor_socket);
        WSACleanup();
        return 1;
    }

    printf("Servidor TCP rodando no Windows e escutando na porta 8080...\n");

    while(1) {
        struct sockaddr_in cliente_endereco;
        int c_tamanho = sizeof(cliente_endereco);
        
        SOCKET cliente_socket = accept(servidor_socket, (struct sockaddr *)&cliente_endereco, &c_tamanho); 
        
        if (cliente_socket != INVALID_SOCKET) {
            printf("\n[Cliente conectado!]\n");

            char buffer[1024]; 
            
            while(1) {
                memset(buffer, '\0', 1024); 

                int bytes_recebidos = recv(cliente_socket, buffer, 1024, 0); 

                if (bytes_recebidos > 0) {
                    printf("Cliente diz: %s", buffer); 
                } 
                else {
                    printf("[Cliente se desconectou]\n");
                    break; 
                }
            }

            closesocket(cliente_socket); 
        }
    }

    closesocket(servidor_socket);
    WSACleanup();

    return 0;
}