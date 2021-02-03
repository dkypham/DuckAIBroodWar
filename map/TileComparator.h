#pragma once
#include "../Common.h"

namespace TileComparator {
  BWAPI::TilePosition findTopLeft( BWAPI::TilePosition first, 
    BWAPI::TilePosition second );
  BWAPI::TilePosition findBotRight( BWAPI::TilePosition first, 
    BWAPI::TilePosition second, BWAPI::UnitType uT );
  BWAPI::Position TPtoPos( BWAPI::TilePosition TP );
  bool isIntersectingTP( std::tuple<BWAPI::TilePosition,
    BWAPI::TilePosition> firstZone, std::tuple<BWAPI::TilePosition,
    BWAPI::TilePosition> secondZone );
}