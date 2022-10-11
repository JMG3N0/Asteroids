#include "raylib.h"
#include <cmath>

int main()
{

    const int screenWidth = 1024;
    const int screenHeight = 768;


    InitWindow(screenWidth, screenHeight, "samurai movement");

    
    Texture2D player = LoadTexture("resources/player_frame_1.png");        // Texture loading
   

    Vector2 position = { 350.0f, 280.0f };
    Rectangle sourceRec = { 0.0f, 0.0f, (float)player.width , (float)player.height };
    Rectangle destRec = { screenWidth / 2.0f, screenHeight / 2.0f, player.width  * 4.0f, player.height * 4.0f };
    Vector2 origin = { (float)player.width , (float)player.height };
    int currentFrame = 0;
    float rotation = 0;
   
    int framesCounter = 0;
    

    SetTargetFPS(60);               
    while (!WindowShouldClose())    
    {

        Vector2 MousePos = { GetMouseX() , GetMouseY() };
        

       // origin.y++;

        Vector2 PlayerPos = origin;

       // Vector2 vector = {(MousePos.x - PlayerPos.x),(MousePos.y - PlayerPos.y)};

       // float angle = atan((MousePos.y - PlayerPos.y) / (MousePos.x - PlayerPos.x));
        float angle = atan((GetMouseY() - origin.y) / (GetMouseX() - origin.x));

        if ((GetMouseX() - origin.x) > 0)
        {
            if ((GetMouseY() - origin.y) < 0 )
            {
                angle += 360;// (360 * PI / 180);
            }
        }
        if ((GetMouseX() - origin.x) < 0)
        {
            angle += 180;//(180 * PI / 180);
        }

        angle = angle * 180 / PI;

        rotation = angle;

        //position.y+=2;

        BeginDrawing();

        ClearBackground(GRAY);

       
        DrawTexturePro(player, sourceRec, destRec, origin, (float)rotation, WHITE);

       // DrawText(TextFormat("Angle: ", angle), screenWidth - 200, screenHeight - 20, 10, GRAY);
      DrawText(TextFormat("MousePosX: %08i", GetMouseX()), 200, 80, 20, RED);
     //  DrawText(TextFormat("MousePosY: %08i", MousePos.y), 200, 60, 20, RED);
       

        EndDrawing();
       
    }

    UnloadTexture(player);       

    CloseWindow();               
   

    return 0;
}