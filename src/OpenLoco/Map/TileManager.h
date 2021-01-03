#pragma once

#include "../Core/Span.hpp"
#include "Tile.h"
#include <cstdint>
#include <tuple>

namespace OpenLoco::Map::TileManager
{
    enum MapSelectFlag : uint16_t
    {
        enable = (1 << 0),
        enableConstruct = (1 << 1)
    };

    constexpr size_t maxElements = 0x6C000;

    void initialise();
    stdx::span<tile_element> getElements();
    void setElements(stdx::span<tile_element> elements);
    tile_element* getElementsEnd();
    tile_element** getElementIndex();
    tile get(TilePos2 pos);
    tile get(Pos2 pos);
    tile get(coord_t x, coord_t y);
    TileHeight getHeight(const Pos2& pos);
    void updateTilePointers();
    void reorganise();
    Pos2 screenGetMapXY(int16_t x, int16_t y);
    uint16_t setMapSelectionTiles(int16_t x, int16_t y);
    Pos3 screenPosToMapPos(int16_t x, int16_t y);
    uint16_t setMapSelectionSingleTile(int16_t x, int16_t y, bool setQuadrant = false);
    void mapInvalidateSelectionRect();
    void mapInvalidateTileFull(Map::Pos2 pos);
    void mapInvalidateMapSelectionTiles();
    void resetSurfaceClearance();
    void createAnimation(uint8_t type, coord_t x, coord_t y, tile_coord_t baseZ);
    void registerHooks();
}
