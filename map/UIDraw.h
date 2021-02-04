#pragma once

#include "../Common.h"
#include "../structure/BuildOrderElement.h"

namespace UIDraw {
  void drawUIInfo( std::multimap<BWAPI::UnitType, int> dArmyMap,
    std::multimap<BWAPI::UnitType, int> dStructMap , 
    std::vector<int> dResources,
    std::queue<BuildOrderElement>& buildOrderListPtr );
};