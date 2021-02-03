#include "TileComparator.h"

namespace TileComparator {
  // find the most top left tilepostion
  BWAPI::TilePosition findTopLeft( BWAPI::TilePosition first, 
    BWAPI::TilePosition second ) {
    int topLeftX = first.x;
    int topLeftY = first.y;
    if (second.x < topLeftX) topLeftX = second.x;
    if (second.y < topLeftY) topLeftY = second.y;

    return BWAPI::TilePosition( topLeftX, topLeftY );
  };

  // find the most bottom right tileposition, taking into account the
  // size of the unit
  BWAPI::TilePosition findBotRight( BWAPI::TilePosition first, 
    BWAPI::TilePosition second,
    BWAPI::UnitType uT ) {
    int botRightX = first.x;
    int botRightY = first.y;
    if (second.x + uT.tileWidth() > botRightX) 
      botRightX = second.x + uT.tileWidth();
    if (second.y + uT.tileHeight() > botRightY) 
      botRightY = second.y + uT.tileHeight();

    return BWAPI::TilePosition( botRightX, botRightY );
  }

  BWAPI::Position TPtoPos( BWAPI::TilePosition TP ) {
    return BWAPI::Position( TP.x * 32, TP.y * 32 );
  }

  bool isIntersectingTP( std::tuple<BWAPI::TilePosition,
    BWAPI::TilePosition> firstZone, std::tuple<BWAPI::TilePosition,
    BWAPI::TilePosition> secondZone ) {
    BWAPI::TilePosition firstZoneTopLeft = firstZone-
  }
}