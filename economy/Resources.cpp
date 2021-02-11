#include "Resources.h"

namespace Resources {
  // dResources[0] = Actual mineral amount
  // dResources[1] = Effective mineral amount
  // dResources[2] = Actual gas amount
  // dResources[3] = Effective gas amount
  // dResources[4] = Actual available supply amount
  // dResources[5] = Effective available supply amount
  // dResources[6] = Actual supply used

  void initializeResources(std::vector<int>& dResources) {
    dResources[kActMinIndex] = BWAPI::Broodwar->self()->minerals();
    dResources[kEffMinIndex] = BWAPI::Broodwar->self()->minerals();
    dResources[kActGasIndex] = BWAPI::Broodwar->self()->gas();
    dResources[kEffGasIndex] = BWAPI::Broodwar->self()->gas();
    dResources[kActSupIndex] = BWAPI::Broodwar->self()->supplyTotal() / 
      kSupplyModifier;
    dResources[kEffSupIndex] = BWAPI::Broodwar->self()->supplyTotal() / 
      kSupplyModifier;
    dResources[kSupUseIndex] = BWAPI::Broodwar->self()->supplyUsed() / 
      kSupplyModifier;
  }

  void updateResources(std::vector<int>& dResources,
                       std::multimap<BWAPI::UnitType, int>& dArmyMap) {
    dResources[kActMinIndex] = BWAPI::Broodwar->self()->minerals();
    dResources[kEffMinIndex] = BWAPI::Broodwar->self()->minerals();
    dResources[kActGasIndex] = BWAPI::Broodwar->self()->gas();
    dResources[kEffGasIndex] = BWAPI::Broodwar->self()->gas();
    dResources[kActSupIndex] = BWAPI::Broodwar->self()->supplyTotal() /
      kSupplyModifier;
    dResources[kEffSupIndex] = BWAPI::Broodwar->self()->supplyTotal() /
      kSupplyModifier;
    dResources[kSupUseIndex] = BWAPI::Broodwar->self()->supplyUsed() /
      kSupplyModifier;
  }

  bool isEnoughMinerals(std::vector<int> dResources, int mineralsCost) {
    return dResources[kEffMinIndex] - mineralsCost >= 0;
  }

  bool isEnoughGas(std::vector<int> dResources, int gasCost) {
    return dResources[kEffGasIndex] - gasCost >= 0;
  }

  bool isEnoughMineralsGas(std::vector<int> dResources, int mineralsCost,
                           int gasCost) {
    return (dResources[kEffMinIndex] - mineralsCost >= 0) &&
      (dResources[kEffGasIndex] - gasCost >= 0);
  }

  void updateEffectiveMinerals(std::vector<int> dResources,
                               int mineralsCost) {
    dResources[1] = dResources[1] - mineralsCost;
  }

  void updateEffectiveGas(std::vector<int> dResources,
                          int gasCost) {
    dResources[kEffGasIndex] = dResources[kEffGasIndex] - gasCost;
  }

  void updateEffectiveMineralsGas(std::vector<int> dResources,
                                  int mineralsCost, int gasCost) {
    dResources[kEffMinIndex] = dResources[kEffMinIndex] - mineralsCost;
    dResources[kEffGasIndex] = dResources[kEffGasIndex] - gasCost;
  }

  void updateEffectiveResources(std::vector<int> dResources,
                                std::multimap<BWAPI::UnitType, int>& dArmyMap) {
    for (auto itr = dArmyMap.find(BWAPI::UnitTypes::Terran_SCV);
         itr != dArmyMap.end(); itr++) {
      //BWAPI::Broodwar << "SCV ID: " << itr->second << std::endl;

    }
  }

  void updateEffectiveSupply(std::vector<int> dResources) {

  }

}