#include "DuckAIModule.h"
#include <iostream>

using namespace BWAPI;
using namespace Filter;

void DuckAIModule::onStart() {
  Broodwar->setLocalSpeed(15);

  WorkerManager::Initialize();

}

void DuckAIModule::onFrame() {
  Broodwar->drawTextScreen(200, 0, "FPS: %d", Broodwar->getFPS());

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
