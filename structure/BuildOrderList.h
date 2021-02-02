#pragma once

#include "../Common.h"
#include "BuildOrderElement.h"

namespace BuildOrderList {
  std::multimap<int, BuildOrderElement> chooseBuildOrder( 
    BWAPI::Race enemyRace ); 

  void initializeBuildOrder( std::queue<BuildOrderElement>& buildOrderList,
    BWAPI::Race enemyRace );

  void addToBuildOrder( std::queue<BuildOrderElement>& buildOrderList,
    BWAPI::UnitType uT, BWAPI::TechType tT, int supply );

  void initOneFactFE( std::queue<BuildOrderElement>& );
}