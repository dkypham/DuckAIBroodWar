#include "DuckAIModule.h"
#include <iostream>

using namespace BWAPI;
using namespace Filter;


std::multimap<BWAPI::UnitType, int> dArmyMap;
std::multimap<BWAPI::UnitType, int> dStructMap;

std::vector<int> dResources( 7 );

std::queue<BuildOrderElement> buildOrderListPtr;
std::list<int> mapVariables;
std::vector<std::pair<BWAPI::TilePosition, BWAPI::TilePosition>> noBuildZones;

void DuckAIModule::onStart() {
  Broodwar->setLocalSpeed( 10 );

  // TODO: Implement beginning worker logic (find optimal mineral spread)
  WorkerManager::Initialize();

  // Initialize initial build order
  BuildOrderList::initializeBuildOrder( buildOrderListPtr,
    Broodwar->enemy()->getRace() );

  // Determine mineral setup (above, right, below, left)
  Map::initializeMapInfo( mapVariables, noBuildZones );

  // Populate dArmyMap and dStructMap
  UnitIDMap::initializeUnitIDMaps( dArmyMap, dStructMap );

  Resources::initializeResources( dResources );


}

void DuckAIModule::onFrame() {
  Broodwar->drawTextScreen( 390, 3, "FPS: %d", Broodwar->getFPS() );

  Resources::updateResources( dResources, dArmyMap );
  WorkerManager::WorkerManager( dResources, dArmyMap, buildOrderListPtr );

  MapDraw::drawMapInfo( noBuildZones );
  UIDraw::drawUIInfo( dArmyMap, dStructMap, dResources, buildOrderListPtr );

}

void DuckAIModule::onUnitCreate( BWAPI::Unit unit ) {
  switch (UnitIDMap::unitFlagSwitch( unit )) {
  case 1: // structure
    UnitIDMap::addToUnitIDMap( dStructMap, unit );
    UnitIDMap::updateBuildOrderList( buildOrderListPtr, unit->getType() );
    break;
  case 2: // unit
    UnitIDMap::addToUnitIDMap( dArmyMap, unit );
    break;
  }
}

void DuckAIModule::onUnitDestroy( BWAPI::Unit unit ) {
}

void DuckAIModule::onUnitMorph( BWAPI::Unit unit ) {
  switch (UnitIDMap::unitFlagSwitch( unit )) {
  case 1: // structure
    UnitIDMap::updateBuildOrderList( buildOrderListPtr, unit->getType() );
    break;
  }
}

void DuckAIModule::onUnitComplete( BWAPI::Unit unit ) {
  switch (UnitIDMap::unitFlagSwitch( unit )) {
  case 1: // structure
    if (unit->getType() == BWAPI::UnitTypes::Terran_Refinery) {
      auto itr1 = dArmyMap.lower_bound( BWAPI::UnitTypes::Terran_SCV );
      itr1++;
      auto itr2 = itr1;
      itr2++;
      itr2++;
      itr2++;
      while (itr1 != itr2) {
        if (itr1->first == BWAPI::UnitTypes::Terran_SCV) {
          Broodwar->getUnit( itr1->second )->gather( unit );
        }
        itr1++;
      }
    }
    break;
  case 2: // unit
    break;
  }

}
