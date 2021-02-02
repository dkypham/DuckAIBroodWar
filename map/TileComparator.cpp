#include "TileComparator.h"

namespace TileComparator {
  BWAPI::TilePosition findTopLeft( BWAPI::TilePosition first, BWAPI::TilePosition second ) {
    int topLeftX = first.x;
    int topLeftY = first.y;

    if (second.x < topLeftX) topLeftX = second.x;
    if (second.y < topLeftY) topLeftY = second.y;

    return BWAPI::TilePosition( topLeftX, topLeftY );
  };

  BWAPI::TilePosition findBotRight( BWAPI::TilePosition first, BWAPI::TilePosition second,
    BWAPI::UnitType uT ) {
    int botRightX = first.x;
    int botRightY = first.y;

    if (second.x + uT.tileWidth() > botRightX) botRightX = second.x + uT.tileWidth();
    if (second.y + uT.tileHeight() > botRightY) botRightY = second.y + uT.tileHeight();

    return BWAPI::TilePosition( botRightX, botRightY );
  }
}