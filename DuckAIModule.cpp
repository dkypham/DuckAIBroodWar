#include "DuckAIModule.h"
#include <iostream>

using namespace BWAPI;
using namespace Filter;


std::multimap<BWAPI::UnitType, int> dArmyMap;
std::multimap<BWAPI::UnitType, int> dStructMap;

std::vector<int> dResources(7);

std::queue<BuildOrderElement> buildOrderListPtr;
std::list<int> mapVariables;
std::vector<std::tuple<BWAPI::TilePosition, BWAPI::TilePosition>> noBuildZones;

void DuckAIModule::onStart() {
  Broodwar->setLocalSpeed( 15 );

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

  WorkerManager::WorkerManager();
  MapDraw::drawMapInfo( noBuildZones );
  UIDraw::drawUIInfo( dArmyMap, dStructMap , dResources );

  Resources::updateEffectiveResources( dResources, dArmyMap );
}

void DuckAIModule::onUnitCreate( BWAPI::Unit unit ) {
  switch (UnitIDMap::unitFlagSwitch( unit )) {
  case 1: // structure
    UnitIDMap::addToUnitIDMap( dStructMap, unit );
    break;
  case 2: // unit
    UnitIDMap::addToUnitIDMap( dArmyMap, unit );
  }
}

void DuckAIModule::onUnitDestroy( BWAPI::Unit unit ) {
}

void DuckAIModule::onUnitMorph( BWAPI::Unit unit ) {

}

void DuckAIModule::onUnitComplete( BWAPI::Unit unit ) {

}
