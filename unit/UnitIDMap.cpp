#include "UnitIDMap.h"

namespace UnitIDMap {
  void initializeUnitIDMaps(std::multimap<BWAPI::UnitType, int>& dArmyMap,
                            std::multimap<BWAPI::UnitType, int>& dStructMap) {
    for (auto &u : BWAPI::Broodwar->self()->getUnits()) {
      if (u->getType().isWorker()) {
        dArmyMap.insert(makeUnitIDMapPair(u->getType(), u->getID()));
      }
      if (u->getType().isBuilding()) {
        dStructMap.insert(makeUnitIDMapPair(u->getType(), u->getID()));
      }
    }
  }

  std::pair<BWAPI::UnitType, int> makeUnitIDMapPair(BWAPI::UnitType uT,
                                                    int uID) {
    return std::pair< BWAPI::UnitType, int>(uT, uID);
  }

  int unitFlagSwitch(BWAPI::Unit dUnit) {
    if (dUnit->getType().isBuilding()) {
      return 1;
    }
    else {
      return 2;
    }
    // TODO: Implement error case
  }

  void addToUnitIDMap(std::multimap<BWAPI::UnitType, int>& IDMap,
                      BWAPI::Unit dUnit) {
    IDMap.insert(makeUnitIDMapPair(dUnit->getType(), dUnit->getID()));
  }

  void updateBuildOrderList(std::queue<BuildOrderElement>& buildOrderListPtr,
                            BWAPI::UnitType uT) {
    if (buildOrderListPtr.front().BOuT == uT) {
      buildOrderListPtr.pop();
    }
  }

  std::pair<IDMapItr, IDMapItr> getIDItr(
    std::multimap<BWAPI::UnitType, int>& IDMap,
    BWAPI::UnitType uT) {
    return IDMap.equal_range(uT);
  }

  int getFirstUnitID(std::multimap<BWAPI::UnitType, int>& IDMap,
                           BWAPI::UnitType uT) {
    std::pair<UnitIDMap::IDMapItr, UnitIDMap::IDMapItr> IDStructItr =
      UnitIDMap::getIDItr(IDMap, uT);
    return (IDStructItr.first)->second;
  }

  BWAPI::Unit getUnitFromID(int uID) {
    return BWAPI::Broodwar->getUnit(uID);
  }
}