#include <windows.h>

// Funcao de callback: aqui chegam os eventos (fechar, clicar, etc.)
LRESULT CALLBACK ProcedimentoJanela(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0); // Encerra o loop quando o usuario fecha a janela
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char NOME_CLASSE[] = "ClasseJanelaBasica";

    // 1. Registrar a classe da janela no sistema operacional
    WNDCLASS wc = {0};
    wc.lpfnWndProc   = ProcedimentoJanela;
    wc.hInstance     = hInstance;
    wc.lpszClassName = NOME_CLASSE;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    // 2. Pedir ao Windows para criar a janela física
    HWND hwnd = CreateWindowEx(
        0,
        NOME_CLASSE,
        "Minha Primeira Janela Nativa",
        WS_OVERLAPPEDWINDOW, // Botoes de fechar, minimizar, maximizar e borda padrão
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, // Posicao X, Y, Largura, Altura
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    // 3. Exibir a janela na tela
    ShowWindow(hwnd, nCmdShow);

    // 4. Loop de mensagens: fica ouvindo o Windows enviar cliques e teclas
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}