#include "DuckAIModule.h"
#include <iostream>

using namespace BWAPI;
using namespace Filter;

/* Current Data Structures
 * dArmyMap: multimap with unittype (non structs) keys and int ID values
 * dStructMap: multimap with unittype (structs) keys and int ID values
 * dResources: vector of defined resources
 *   dResources[kActMinIndex] = Actual mineral amount
 *   dResources[kEffMinIndex] = Effective mineral amount
 *   dResources[kActGasnIndex] = Actual gas amount
 *   dResources[kEffGasIndex] = Effective gas amount
 *   dResources[kActSupIndex] = Actual available supply amount
 *   dResources[kEffSupIndex] = Effective available supply amount
 *   dResources[kSupUseIndex] = Actual supply used
 * buildOrderList: queue with build order using BuildOrderElements
 * noBuildZones: every pair is the topright and botright of a no build zone
*/
std::multimap<BWAPI::UnitType, int> dArmyMap;
std::multimap<BWAPI::UnitType, int> dStructMap;
std::vector<int> dResources(Resources::kResourcesSize);
std::queue<BuildOrderElement> buildOrderList;
std::vector<std::pair<BWAPI::TilePosition, BWAPI::TilePosition>> noBuildZones;
std::vector<std::pair<BWAPI::TilePosition, BWAPI::TilePosition>> buildZones;

// TODO: organize variables below this
std::list<int> mapVariables;

void DuckAIModule::onStart() {
  // Set game speed
  Broodwar->setLocalSpeed(10);

  // TODO: implement intial worker logic (finding closest resources, 
  // assigning roles
  WorkerManager::Initialize();

  // BuildOrderList initialize: determine build order
  BuildOrderList::initializeBuildOrder(buildOrderList,
                                       Broodwar->enemy()->getRace());

  // Map initialize: find initial no build zone based on mineral line, gas
  // and starting CC
  Map::initializeMapInfo(dStructMap, mapVariables, noBuildZones, buildZones);

  // UnitIDMap initialize: fill dArmyMap and dStructMap with the starting units
  UnitIDMap::initializeUnitIDMaps(dArmyMap, dStructMap);

  // Resources initialize: fill dResources with initial resource values
  Resources::initializeResources(dResources);
}

void DuckAIModule::onFrame() {
  Resources::updateResources(dResources, dArmyMap);
  WorkerManager::WorkerManager(dResources, dArmyMap, buildOrderList);

  MapDraw::drawMapInfo(noBuildZones);
  UIDraw::drawUIInfo(dArmyMap, dStructMap, dResources, buildOrderList);

}

void DuckAIModule::onUnitCreate(BWAPI::Unit unit) {
  switch (UnitIDMap::unitFlagSwitch(unit)) {
  case 1: // structure
    UnitIDMap::addToUnitIDMap(dStructMap, unit);
    UnitIDMap::updateBuildOrderList(buildOrderList, unit->getType());
    break;
  case 2: // unit
    UnitIDMap::addToUnitIDMap(dArmyMap, unit);
    break;
  }
}

void DuckAIModule::onUnitDestroy(BWAPI::Unit unit) {
}

void DuckAIModule::onUnitMorph(BWAPI::Unit unit) {
  switch (UnitIDMap::unitFlagSwitch(unit)) {
  case 1: // structure
    UnitIDMap::updateBuildOrderList(buildOrderList, unit->getType());
    break;
  }
}

void DuckAIModule::onUnitComplete(BWAPI::Unit unit) {
  switch (UnitIDMap::unitFlagSwitch(unit)) {
  case 1: // structure
    if (unit->getType() == BWAPI::UnitTypes::Terran_Refinery) {
      auto itr1 = dArmyMap.lower_bound(BWAPI::UnitTypes::Terran_SCV);
      itr1++;
      auto itr2 = itr1;
      itr2++;
      itr2++;
      itr2++;
      while (itr1 != itr2) {
        if (itr1->first == BWAPI::UnitTypes::Terran_SCV) {
          Broodwar->getUnit(itr1->second)->gather(unit);
        }
        itr1++;
      }
    }
    break;
  case 2: // unit
    break;
  }

}
