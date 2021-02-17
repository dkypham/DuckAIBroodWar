#pragma once
#include "../Common.h"
#include "../structure/BuildOrderElement.h"

namespace UnitIDMap {
  void initializeUnitIDMaps(std::multimap<BWAPI::UnitType, int>& dArmyMap,
                            std::multimap<BWAPI::UnitType, int>& dStructMap);
  std::pair<BWAPI::UnitType, int> makeUnitIDMapPair(BWAPI::UnitType uT,
                                                    int uID);
  int unitFlagSwitch(BWAPI::Unit dUnit);
  void addToUnitIDMap(std::multimap<BWAPI::UnitType, int>& IDMap,
                      BWAPI::Unit dUnit);
  void updateBuildOrderList(std::queue<BuildOrderElement>& buildOrderListPtr,
                            BWAPI::UnitType uT);
  typedef std::multimap<BWAPI::UnitType, int>::iterator IDMapItr;
  std::pair<IDMapItr, IDMapItr> getIDItr(
    std::multimap<BWAPI::UnitType, int>& IDMap,
    BWAPI::UnitType uT);
  int getFirstUnitID(std::multimap<BWAPI::UnitType, int>& IDMap,
                     BWAPI::UnitType uT);
  BWAPI::Unit getUnitFromID(int uID);
};