#pragma once

#include "../Common.h"
#include "TileComparator.h"

namespace Map {
  void initializeMapInfo( std::list<int>& mapVariables,
    std::vector<std::pair<BWAPI::TilePosition,
    BWAPI::TilePosition>>&noBuildZones );
  int findMineralSetup();
  void initializeNoBuildZone( std::vector<std::pair<BWAPI::TilePosition, 
    BWAPI::TilePosition>>& noBuildZones );
}