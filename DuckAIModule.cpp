#include "DuckAIModule.h"
#include <iostream>

using namespace BWAPI;
using namespace Filter;

std::queue<BuildOrderElement> buildOrderListPtr;
std::list<int> mapVariables;
std::vector<std::tuple<BWAPI::TilePosition, BWAPI::TilePosition>> noBuildZones;

void DuckAIModule::onStart() {
  Broodwar->setLocalSpeed( 15 );

  WorkerManager::Initialize();

  BuildOrderList::initializeBuildOrder( buildOrderListPtr,
    Broodwar->enemy()->getRace() );

  Map::initializeMapInfo( mapVariables , noBuildZones );

  // FOR TESTING: Print out build order
  //while (!buildOrderListPtr.empty()) {
  //  Broodwar << buildOrderListPtr.front().BOuT << " at supply: " <<
  //    buildOrderListPtr.front().BOsupply << std::endl;
  //  buildOrderListPtr.pop();
  //}
}

void DuckAIModule::onFrame() {
  Broodwar->drawTextScreen( 390, 3, "FPS: %d", Broodwar->getFPS() );

  WorkerManager::WorkerManager();

  BWAPI::TilePosition topLeftTP = std::get<0>( noBuildZones.front() );
  BWAPI::TilePosition botRightTP = std::get<1>( noBuildZones.front() );
  
  BWAPI::Position topLeftPos = BWAPI::Position( topLeftTP.x *32, topLeftTP.y *32);
  BWAPI::Position botRightPos = BWAPI::Position( botRightTP.x *32, botRightTP.y *32);

  Broodwar->drawBoxMap( topLeftPos, botRightPos, BWAPI::Colors::Red );

  /*Broodwar << topLeftPos.x << " , " << topLeftPos.y << std::endl;
  Broodwar << botRightPos.x << " , " << botRightPos.y << std::endl;*/

  //for (auto &u : BWAPI::Broodwar->self()->getUnits()) {
  //  // Command Center: train workers if not already training, have enough
  //  // minerals.
  //  if (u->getType() == BWAPI::UnitTypes::Terran_Command_Center) {
  //    Broodwar << u->getPosition().x << " , " << u->getPosition().y << std::endl;
  //  }
  //}


}

void DuckAIModule::onUnitCreate( BWAPI::Unit unit ) {

}

void DuckAIModule::onUnitDestroy( BWAPI::Unit unit ) {
}

void DuckAIModule::onUnitMorph( BWAPI::Unit unit ) {

}


void DuckAIModule::onUnitComplete( BWAPI::Unit unit ) {

}
