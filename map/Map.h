#pragma once

#include "../Common.h"
#include "../unit/UnitIDMap.h"
#include "TileComparator.h"

namespace Map {
  void initializeMapInfo(std::multimap<BWAPI::UnitType, int> dStructMap,
                         std::list<int>& mapVariables,
                         std::vector<std::pair<BWAPI::TilePosition,
                         BWAPI::TilePosition>>&noBuildZones,
                         std::vector<std::pair<BWAPI::TilePosition,
                         BWAPI::TilePosition>>&buildZones);
  int findMineralSetup(std::multimap<BWAPI::UnitType, int> dStructMap);
  void initializeNoBuildZones(std::vector<std::pair<BWAPI::TilePosition,
                             BWAPI::TilePosition>>&noBuildZones);
  void initializeBuildZones(std::multimap<BWAPI::UnitType, int> dStructMap, 
                            std::list<int>& mapVariables,
                            std::vector<std::pair<BWAPI::TilePosition,
                            BWAPI::TilePosition>>&noBuildZones,
                            std::vector<std::pair<BWAPI::TilePosition,
                            BWAPI::TilePosition>>&buildZones);
}