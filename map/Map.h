#pragma once

#include "../Common.h"
#include "TileComparator.h"

namespace Map {
  void initializeMapInfo(std::multimap<BWAPI::UnitType, int> dStructMap,
                         std::list<int>& mapVariables,
                         std::vector<std::pair<BWAPI::TilePosition,
                         BWAPI::TilePosition>>&noBuildZones,
                         std::vector<std::pair<BWAPI::TilePosition,
                         BWAPI::TilePosition>>&buildZones);
  int findMineralSetup();
  void initializeNoBuildZones(std::vector<std::pair<BWAPI::TilePosition,
                             BWAPI::TilePosition>>&noBuildZones);
  void initializeBuildZones(std::multimap<BWAPI::UnitType, int> dStructMap, 
                            std::list<int>& mapVariables,
                            std::vector<std::pair<BWAPI::TilePosition,
                            BWAPI::TilePosition>>&noBuildZones,
                            std::vector<std::pair<BWAPI::TilePosition,
                            BWAPI::TilePosition>>&buildZones);
}