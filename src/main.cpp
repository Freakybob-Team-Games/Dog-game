#include "raylib.h"

int main() {
    const int screen_width = 800;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "greg");
    Image icon = LoadImage("src/stupid_egg_dog.ico");
    SetWindowIcon(icon);
    SetTargetFPS(60);
    Texture2D myImage = LoadTexture("src/stupid_egg_dog.png");
    int originalImageY = GetScreenHeight() / 2 - myImage.height / 2;
    int originalImageX = GetScreenWidth() / 2 - myImage.width / 2;
    while(!WindowShouldClose()) {
        int ImageY = GetScreenWidth() / 2 - myImage.width / 2;
        int ImageX = GetScreenHeight() / 2 - myImage.height / 2;
        if (IsKeyDown(KEY_RIGHT)) {
            myImage.width++;
        }
        else if (IsKeyDown(KEY_LEFT)) {
            myImage.width--;
        }
        else if (IsKeyDown(KEY_UP)) {
            myImage.height++;
        }
        else if (IsKeyDown(KEY_DOWN)) {
            myImage.height--;
        }
        if (IsKeyPressed(KEY_E)) {
            ImageX = originalImageX;
            ImageY = originalImageY;
            myImage.width = LoadTexture("src/stupid_egg_dog.png").width; 
            myImage.height = LoadTexture("src/stupid_egg_dog.png").height;
    }
        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("Stretch the dog wait WHAT", 80, 200, 50, GREEN);
        DrawTexture(myImage, ImageY, ImageX, WHITE);
        DrawText("Press 'e' to reset image greg", 80, 240, 30, GREEN);
        EndDrawing();
    }
    UnloadTexture(myImage);
    UnloadImage(icon);
    CloseWindow();
}
