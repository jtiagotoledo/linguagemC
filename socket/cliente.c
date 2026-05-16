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
    servidor_endereco.sin_addr.s_addr = inet_addr("192.168.15.6"); 
    memset(&(servidor_endereco.sin_zero), '\0', 8);

    printf("Tentando se conectar ao servidor...\n");
    if (connect(cliente_socket, (struct sockaddr *)&servidor_endereco, sizeof(servidor_endereco)) == SOCKET_ERROR) {
        printf("Nao foi possivel conectar. O servidor esta rodando?\n");
        closesocket(cliente_socket);
        WSACleanup();
        return 1;
    }

    printf("Conectado com sucesso!\n");

    char mensagem_usuario[1024]; 
    memset(mensagem_usuario, '\0', 1024); 

    printf("Digite a mensagem que deseja enviar: ");
    
    fgets(mensagem_usuario, 1024, stdin); 

    int bytes_enviados = send(cliente_socket, mensagem_usuario, strlen(mensagem_usuario), 0);

    if (bytes_enviados == SOCKET_ERROR) {
        printf("Falha ao enviar os dados.\n");
    } else {
        printf("Mensagem personalizada disparada com sucesso!\n");
    }

    closesocket(cliente_socket);
    WSACleanup();

    return 0;
}