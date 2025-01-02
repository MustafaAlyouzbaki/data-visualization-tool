#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Lebron James"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    Texture2D texture = LoadTexture(ASSETS_PATH"/test.png"); // Check README.md for how this works

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        int barAmount = 100;
        int barWidth = SCREEN_WIDTH/barAmount;
        for(int i = 0; i < barAmount; i++) {
            int barHeight = (i+1)*5;
            DrawRectangle(i * barWidth, SCREEN_HEIGHT - barHeight, barWidth, barHeight, RAYWHITE);
        }

        /*const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        DrawTexture(texture, texture_x, texture_y, WHITE);

        const char* text = "YOU ARE MY SUNSHINE";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, SCREEN_HEIGHT / 2 + texture.height / 2, 20, BLACK);*/
        EndDrawing();
    }

    CloseWindow();

    return 0;
}