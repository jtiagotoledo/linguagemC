#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Falha ao inicializar o Winsock.\n");
        return 1;
    }

    SOCKET cliente_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (cliente_socket == INVALID_SOCKET) {
        printf("Erro ao criar o socket.\n");
        WSACleanup();
        return 1;
    }

    struct sockaddr_in servidor_endereco;
    servidor_endereco.sin_family = AF_INET;
    servidor_endereco.sin_port = htons(8080);
    servidor_endereco.sin_addr.s_addr = inet_addr("192.168.1.1"); 
    memset(&(servidor_endereco.sin_zero), '\0', 8);

    printf("Tentando se conectar ao servidor...\n");
    if (connect(cliente_socket, (struct sockaddr *)&servidor_endereco, sizeof(servidor_endereco)) == SOCKET_ERROR) {
        printf("Nao foi possivel conectar. O servidor esta rodando?\n");
        closesocket(cliente_socket);
        WSACleanup();
        return 1;
    }

    printf("Conectado com sucesso!\n");

    char *mensagem = "Ola Servidor! Mensagem enviada via codigo C puro.";
    
    int bytes_enviados = send(cliente_socket, mensagem, strlen(mensagem), 0);

    if (bytes_enviados == SOCKET_ERROR) {
        printf("Falha ao enviar os dados.\n");
    } else {
        printf("Mensagem de %d bytes disparada com sucesso pela rede!\n", bytes_enviados);
    }

    closesocket(cliente_socket);
    WSACleanup();

    return 0;
}