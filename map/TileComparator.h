#pragma once
#include "../Common.h"

namespace TileComparator {
  BWAPI::TilePosition findTopLeft( BWAPI::TilePosition first, 
    BWAPI::TilePosition second );
  BWAPI::TilePosition findBotRight( BWAPI::TilePosition first, 
    BWAPI::TilePosition second, BWAPI::UnitType uT );
}