#include "raylib.h"

int main(){
    InitWindow(400,400,"Meu jogo");
    SetTargetFPS(60);

    float posX=0;
    float posY=0;
    float velocidade = 4.0f;

    while(!WindowShouldClose() ){
        if(IsKeyDown(KEY_DOWN)) posY -=velocidade;
        if(IsKeyDown(KEY_UP)) posY +=velocidade;
        if(IsKeyDown(KEY_LEFT)) posX -=velocidade;
        if(IsKeyDown(KEY_RIGHT)) posX +=velocidade;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle((int)posX,(int)posY,40,40,BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}