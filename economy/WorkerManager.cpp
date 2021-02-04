#include "WorkerManager.h"

namespace WorkerManager {
  void Initialize() {

  }

  void WorkerManager( std::vector<int> dResources,
    std::multimap<BWAPI::UnitType, int> dArmyMap,
    std::queue<BuildOrderElement>& buildOrderListPtr ) {
    // first handle the build order
    // check if BOlist meets supply
    if (buildOrderListPtr.front().BOsupply <= dResources[6]) {
      // need to build, take first SCV from dArmyMap
        BWAPI::Unit builder = BWAPI::Broodwar->getUnit(
          dArmyMap.find( BWAPI::UnitTypes::Terran_SCV )->second );
        
        // check if builder is moving to construct or is already constructing
        if ( !builder->isConstructing() ) {
          // issue build order
          BWAPI::Broodwar << "Attempting to build " << \
            buildOrderListPtr.front().BOuT << std::endl;
          builder->build( buildOrderListPtr.front().BOuT,
            BuildingPlacement::naiveBuild( builder, buildOrderListPtr.front().BOuT ) );
        }
    }

    // iterate through all of Duck's units
    for (auto &u : BWAPI::Broodwar->self()->getUnits()) {
      // Worker: gather closest resource
      if (u->getType().isWorker()) {
        if (u->isIdle()) {
          u->gather( u->getClosestUnit( BWAPI::Filter::IsMineralField ||
            BWAPI::Filter::IsRefinery ) );
        }
      }
      // Command Center: train workers if not already training, have enough
      // minerals.
      else if (u->getType() == BWAPI::UnitTypes::Terran_Command_Center) {
        if (!u->isTraining() && BWAPI::Broodwar->self()->minerals() >
          BWAPI::UnitTypes::Terran_SCV.mineralPrice()) {
          u->train( BWAPI::UnitTypes::Terran_SCV );
        }
      }
    }
  }
}