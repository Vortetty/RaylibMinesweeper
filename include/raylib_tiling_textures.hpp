#include "raylib.h"
#include <cstdint>
#include <unordered_map>

// Tile 17 for the base texture
void drawTextureFromTiledTexture(Texture tiledTexture, int tileIndex, Vector2 tilePos) {
    if (tileIndex == 17) {
        DrawTextureRec(tiledTexture, {4*32.0f, 0.0f, 32.0f, 32.0f}, {tilePos.x*32, tilePos.y*32}, WHITE);
    } else {
        int x = tileIndex / 4;
        int y = tileIndex % 4;

        DrawTextureRec(tiledTexture, {x*32.0f, y*32.0f, 32.0f, 32.0f}, {tilePos.x*32, tilePos.y*32}, WHITE);
    }
}

struct circlingTiles {
    uint8_t top_left=0,    top=0,    top_right=0,
            left=0,        center=0, right=0,
            bottom_left=0, bottom=0, bottom_right=0;
};
uint8_t getProperTileIndex(circlingTiles t) {
    return t.top_left*8 | t.top_right*4 | t.bottom_left*2 | t.bottom_right;
}
