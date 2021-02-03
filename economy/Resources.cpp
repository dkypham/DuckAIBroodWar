#include "Resources.h"

namespace Resources {
// dResources[0] = Actual mineral amount
// dResources[1] = Effective mineral amount
// dResources[2] = Actual gas amount
// dResources[3] = Effective gas amount
// dResources[4] = Actual available supply amount
// dResources[5] = Effective available supplya mount
// dResources[6] = Actual supply used

  void initializeResources( std::vector<int> dResources ) {
    dResources[0] = BWAPI::Broodwar->self()->minerals();
    dResources[1] = BWAPI::Broodwar->self()->minerals();
    dResources[2] = BWAPI::Broodwar->self()->gas();
    dResources[3] = BWAPI::Broodwar->self()->gas();
    dResources[4] = BWAPI::Broodwar->self()->supplyTotal();
    dResources[5] = BWAPI::Broodwar->self()->supplyTotal();
    dResources[6] = BWAPI::Broodwar->self()->supplyUsed();
  }

  void updateResources( std::vector<int> dResources ) {
    dResources[0] = BWAPI::Broodwar->self()->minerals();
    dResources[1] = BWAPI::Broodwar->self()->minerals();
    dResources[2] = BWAPI::Broodwar->self()->gas();
    dResources[3] = BWAPI::Broodwar->self()->gas();
    dResources[4] = BWAPI::Broodwar->self()->supplyTotal();
    dResources[5] = BWAPI::Broodwar->self()->supplyTotal();
    dResources[6] = BWAPI::Broodwar->self()->supplyUsed();
  }

  bool isEnoughMinerals( std::vector<int> dResources, int mineralsCost ) {
    return dResources[1] - mineralsCost >= 0;
  }

  bool isEnoughGas( std::vector<int> dResources, int gasCost ) {
    return dResources[3] - gasCost >= 0;
  }

  bool isEnoughMineralsGas( std::vector<int> dResources, int mineralsCost ,
    int gasCost ) {
    return (dResources[1] - mineralsCost >= 0) && 
      (dResources[3] - gasCost >= 0);
  }

  void updateEffectiveMinerals( std::vector<int> dResources, 
    int mineralsCost ) {
    dResources[1] = dResources[1] - mineralsCost;
  }

  void updateEffectiveGas( std::vector<int> dResources,
    int gasCost ) {
    dResources[3] = dResources[3] - gasCost;
  }

  void updateEffectiveMineralsGas( std::vector<int> dResources,
    int mineralsCost , int gasCost) {
    dResources[1] = dResources[1] - mineralsCost;
    dResources[3] = dResources[3] - gasCost;
  }

  void updateEffectiveResources( std::vector<int> dResources, 
    std::multimap<BWAPI::UnitType, int>& dArmyMap) {
    for (auto itr = dArmyMap.find( BWAPI::UnitTypes::Terran_SCV ); 
      itr != dArmyMap.end(); itr++ ) {
      BWAPI::Broodwar << "SCV ID: " << itr->second << std::endl;

    }
  }

  void updateEffectiveSupply( std::vector<int> dResources ) {

  }

}