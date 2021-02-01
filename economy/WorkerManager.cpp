#include "WorkerManager.h"

namespace WorkerManager {
  void Initialize() {

  }

  void WorkerManager() {
    // iterate through all of Duck's units
    for (auto &u : BWAPI::Broodwar->self()->getUnits()) {
      // Worker: gather closest resource
      if (u->getType().isWorker()) {
        if (u->isIdle()) {
          u->gather(u->getClosestUnit(BWAPI::Filter::IsMineralField ||
            BWAPI::Filter::IsRefinery));
        }
      }
      // Command Center: train workers if not already training, have enough
      // minerals.
      else if (u->getType() == BWAPI::UnitTypes::Terran_Command_Center) {
        if ( !u->isTraining() && BWAPI::Broodwar->self()->minerals() > 
          BWAPI::UnitTypes::Terran_SCV.mineralPrice() ) {
          u->train(BWAPI::UnitTypes::Terran_SCV);
        }
      }
    }
  }
}