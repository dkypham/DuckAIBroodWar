#include "DuckAIModule.h"
#include <iostream>

using namespace BWAPI;
using namespace Filter;

std::queue<BuildOrderElement> buildOrderListPtr;

void DuckAIModule::onStart() {
  Broodwar->setLocalSpeed( 15 );

  WorkerManager::Initialize();

  BuildOrderList::initializeBuildOrder( buildOrderListPtr,
    Broodwar->enemy()->getRace() );
  
  // FOR TESTING: Print out build order
  //while (!buildOrderListPtr.empty()) {
  //  Broodwar << buildOrderListPtr.front().BOuT << " at supply: " <<
  //    buildOrderListPtr.front().BOsupply << std::endl;
  //  buildOrderListPtr.pop();
  //}
}

void DuckAIModule::onFrame() {
  Broodwar->drawTextScreen(390, 3, "FPS: %d", Broodwar->getFPS());

  WorkerManager::WorkerManager();
}

void DuckAIModule::onUnitCreate(BWAPI::Unit unit) {

}

void DuckAIModule::onUnitDestroy(BWAPI::Unit unit) {
}

void DuckAIModule::onUnitMorph(BWAPI::Unit unit) {

}


void DuckAIModule::onUnitComplete(BWAPI::Unit unit) {

}
