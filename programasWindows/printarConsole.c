#include <windows.h>

int main(){
    HANDLE driver = CreateFileA("\\\\.\\CON", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

    DWORD enviados;
    WriteFile(driver,"A\n",1000,&enviados,NULL);

    CloseHandle(driver);
    return 0;
}