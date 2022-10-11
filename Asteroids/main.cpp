#include "raylib.h"
#include <cmath>

int main()
{

    const int screenWidth = 1024;
    const int screenHeight = 768;


    InitWindow(screenWidth, screenHeight, "samurai movement");

    
    Texture2D player = LoadTexture("resources/player_frame_1.png");        // Texture loading
   

    Vector2 position = { 350.0f, 280.0f };
    Rectangle frameRec = { 0.0f, 0.0f, (float)player.width , (float)player.height };
    int currentFrame = 0;
   
   
    int framesCounter = 0;
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

       // DrawTexture(player, 15, 40, WHITE);
       

        DrawTextureRec(player, frameRec, position, WHITE);  // Draw part of the texture

        Vector2 MousePos = GetMousePosition();
        Vector2 PlayerPresentPos = position;

        Vector2 vector = {(MousePos.x- PlayerPresentPos.x),(MousePos.y - PlayerPresentPos.y)};

        float angle = atan(vector.y/vector.x);
        

        EndDrawing();
       
    }

    UnloadTexture(player);       

    CloseWindow();               
   

    return 0;
}