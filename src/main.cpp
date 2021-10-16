#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_RICONS
#define GUI_TEXTBOX_EXTENDED_IMPLEMENTATION
#define SUPPORT_FILEFORMAT_BMP
#define SUPPORT_FILEFORMAT_PNG
#define SUPPORT_FILEFORMAT_TGA
#define SUPPORT_FILEFORMAT_JPG
#define SUPPORT_FILEFORMAT_GIF
#define SUPPORT_FILEFORMAT_PSD
#define SUPPORT_FILEFORMAT_PIC
#define SUPPORT_FILEFORMAT_HDR
#define SUPPORT_FILEFORMAT_DDS
#define SUPPORT_FILEFORMAT_PKM
#define SUPPORT_FILEFORMAT_KTX
#define SUPPORT_FILEFORMAT_PVR
#define SUPPORT_FILEFORMAT_ASTC
#include "raylib.h"
#include "raygui.h"
#include "gui_textbox_extended.h"
#undef RAYGUI_IMPLEMENTATION

#include <string>

int main(int argc, char* argv[]) {
    InitWindow(160, 160, "Raylib example");

    Font f = GetFontDefault();
    f.baseSize = 10;
    GuiSetFont(f);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GRAY);

        GuiDrawIcon(RICON_CUBE, {0, 0}, 10, {DARKGRAY});
        std::string text = "Hello user!\nFPS: " + std::to_string(GetFPS());
        Vector2 size = MeasureTextEx(guiFont, text.c_str(), 20.0, 2.0);
        DrawText(text.c_str(), 160/2-size.x/2, 160/2-size.y/2, 20.0, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
