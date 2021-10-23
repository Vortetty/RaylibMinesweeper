#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_RICONS
#define RAYSCENES_IMPLEMENTATION
#define SUPPORT_FILEFORMAT_PNG
#include "raylib.h"
#include "raygui.h"
#include "rayscenes.hpp"
#undef RAYGUI_IMPLEMENTATION

#define FOR_VECTOR( type, vect, ... ) \
  for( std::vector<type>::iterator i=vect.begin(); i!=vect.end(); ++i ) { \
    __VA_ARGS__ \
  }

#include <string>
#include <filesystem>
#include <iostream>
 
namespace fs = std::filesystem;

fs::path exePath = fs::read_symlink("/proc/self/exe");
fs::path assetPath = exePath.remove_filename() / "assets";

bool tiles[10][10] = {
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false}
};

int main(int argc, char* argv[]) {
    InitWindow(320, 320, "Minesweeper");
    std::cout << "EXE path: " << exePath << std::endl;
    std::cout << "Asset path: " << assetPath << std::endl;

    Texture flag = LoadTexture((assetPath / "flag.png").c_str());
    Vector2 cursorPos = {0, 0};

    create_rsm()
    register_rayscene(title, "titleScreen", 
        DrawFPS(10, 10);
    )
    set_active_scene("titleScreen")

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            cursorPos = GetMousePosition();
            if (cursorPos.x < 0 || cursorPos.y < 0 || cursorPos.x > GetScreenWidth() || cursorPos.y > GetScreenHeight()) {
                continue;
            }
            int x = cursorPos.x / 32;
            int y = cursorPos.y / 32;
            tiles[x][y] = !tiles[x][y];
        }

        BeginDrawing();

        ClearBackground(BLACK);

        run_active_scenes()

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
