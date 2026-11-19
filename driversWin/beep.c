#include <windows.h>
#include <winioctl.h>
#include <stdio.h>

typedef struct {
    DWORD Frequencia;
    DWORD Duracao;
} BEEP_PARAMETROS;

#define IOCTL_BEEP_SET CTL_CODE(FILE_DEVICE_BEEP, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)

int main() {
    DefineDosDeviceA(DDD_RAW_TARGET_PATH, "Beep", "\\Device\\Beep");

    HANDLE hDriver = CreateFileA(
        "\\\\.\\Beep",
        GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (hDriver == INVALID_HANDLE_VALUE) {
        printf("Erro ao abrir o driver. Codigo: %lu\n", GetLastError());
        DefineDosDeviceA(DDD_REMOVE_DEFINITION, "Beep", NULL);
        return 1;
    }

    BEEP_PARAMETROS params = { 800, 500 };
    DWORD bytesRetornados = 0;

    if (DeviceIoControl(hDriver, IOCTL_BEEP_SET, &params, sizeof(params), NULL, 0, &bytesRetornados, NULL)) {
        printf("Comando enviado com sucesso para \\Device\\Beep!\n");
        Sleep(500);
    } else {
        printf("Erro no DeviceIoControl. Codigo: %lu\n", GetLastError());
    }

    CloseHandle(hDriver);
    DefineDosDeviceA(DDD_REMOVE_DEFINITION, "Beep", NULL);
    return 0;
}