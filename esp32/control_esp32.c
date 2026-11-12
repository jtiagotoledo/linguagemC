#include <windows.h>
#include <stdio.h>
#include <conio.h> // Necessário para _getch()

int main() {
    // 1. Abrir a conexão com a porta serial do ESP32 (COM4)
    HANDLE hSerial = CreateFileW(
        L"\\\\.\\COM4",                     
        GENERIC_READ | GENERIC_WRITE,  
        0,                                 
        NULL,                              
        OPEN_EXISTING,                     
        0,                                 
        NULL
    );

    if (hSerial == INVALID_HANDLE_VALUE) {
        printf("Erro: Nao foi possivel abrir a porta COM. Verifique a conexao e a porta.\n");
        return 1;
    }
    printf("Sucesso! Conectado ao ESP32.\n");

    // 2. Configurar a velocidade da porta (Baud Rate 115200)
    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        printf("Erro ao ler o estado da porta.\n");
        CloseHandle(hSerial);
        return 1;
    }

    dcbSerialParams.BaudRate = CBR_115200;
    dcbSerialParams.ByteSize = 8;            
    dcbSerialParams.StopBits = ONESTOPBIT; 
    dcbSerialParams.Parity   = NOPARITY;   

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        printf("Erro ao configurar a velocidade da porta.\n");
        CloseHandle(hSerial);
        return 1;
    }

    char comando = 0;
    DWORD bytesEnviados = 0;

    printf("\nControle do ESP32 (Pressione H para Ligar, L para Desligar, ESC para sair):\n");
    
    // 3. Loop infinito que lê a tecla na hora (sem precisar de Enter)
    while (1) {
        comando = _getch(); // Captura a tecla instantaneamente

        // Se apertar ESC (código ASCII 27), sai do programa
        if (comando == 27) {
            break;
        }

        // Normaliza para maiúscula
        if (comando == 'h') comando = 'H';
        if (comando == 'l') comando = 'L';

        if (comando == 'H' || comando == 'L') {
            BOOL resultado = WriteFile(
                hSerial,           
                &comando,          
                1,                 
                &bytesEnviados,    
                NULL
            );

            if (resultado) {
                printf(" -> Comando '%c' enviado com sucesso!\n", comando);
            } else {
                printf(" -> Erro ao enviar dados.\n");
            }
        } else {
            printf(" -> Tecla '%c' ignorada (Use H ou L).\n", comando);
        }
    }

    printf("\nPrograma encerrado pelo usuario.\n");

    // 4. Fechar o handle para liberar a porta USB
    CloseHandle(hSerial);
    printf("Conexao fechada.\n");

    return 0;
}