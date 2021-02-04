#pragma once

#include "../Common.h"
#include "../structure/BuildOrderElement.h"
#include "../structure/BuildingPlacement.h"

namespace WorkerManager {
  void Initialize();
  void WorkerManager( std::vector<int> dResources,
    std::multimap<BWAPI::UnitType, int> dArmyMap,
    std::queue<BuildOrderElement>& buildOrderListPtr );
};