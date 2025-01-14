#include "program.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Data Visualization Tool"

Program::Program()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);
    camera = { 0 };
    camera.target = {0,0};
    camera.zoom = 1.0f;
    running = true;
}

void Program::close()
{
    CloseWindow();
}

void Program::loop()
{
    while (running)
    {   
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) // For testing purposes
            running = false;
        
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);

        // Camera controls
        if(IsKeyDown(KEY_W)) camera.target.y -= 5;
        if(IsKeyDown(KEY_A)) camera.target.x -= 5;
        if(IsKeyDown(KEY_S)) camera.target.y += 5;
        if(IsKeyDown(KEY_D)) camera.target.x += 5;

        if(IsKeyDown(KEY_LEFT_CONTROL)) camera.zoom -= 0.01f;
        if(IsKeyDown(KEY_SPACE)) camera.zoom += 0.01f;

        if(IsKeyPressed(KEY_R)) {
            camera.target = {0,0};
            camera.zoom = 1.0f;
        }
        
        // Window boundaries
        Vector2 boundX = {20.0f, SCREEN_WIDTH - 20.0f};   // Start and end bounds for X-axis
        Vector2 boundY = {25.0f, SCREEN_HEIGHT - 25.0f};  // Start and end bounds for Y-axis

        // Draw bars
        int barAmount = 100;                           // Amount of bars in list
        int barWidth = int(std::round(boundX.y/barAmount));    // Bar width based on X-axis boundary
        Color clr;
        for(int i = 0; i < barAmount; i++) {
            if(i % 2 == 0) clr = RAYWHITE;
            else clr = LIGHTGRAY;
            int barHeight = (i+1);
            DrawRectangle((i * barWidth) + int(boundX.x), SCREEN_HEIGHT - barHeight, barWidth, barHeight, clr);
        }

        EndMode2D();
        EndDrawing();
    }
}