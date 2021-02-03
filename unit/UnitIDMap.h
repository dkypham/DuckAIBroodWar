#pragma once
#include "../Common.h"

namespace UnitIDMap {
  void initializeUnitIDMaps( std::multimap<BWAPI::UnitType, int>& dArmyMap,
    std::multimap<BWAPI::UnitType, int>& dStructMap );
  std::pair<BWAPI::UnitType, int> makeUnitIDMapPair( BWAPI::UnitType uT,
    int uID );
  int unitFlagSwitch( BWAPI::Unit dUnit );

  void addToUnitIDMap( std::multimap<BWAPI::UnitType, int>& IDMap,
    BWAPI::Unit dUnit );
};