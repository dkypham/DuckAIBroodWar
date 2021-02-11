#pragma once
#include "../Common.h"

namespace Resources{
  const int kResourcesSize = 7;
  const int kSupplyModifier = 2; // divide by 2 to match in game supply
  const int kActMinIndex = 0;
  const int kEffMinIndex = 1;
  const int kActGasIndex = 2;
  const int kEffGasIndex = 3;
  const int kActSupIndex = 4;
  const int kEffSupIndex = 5;
  const int kSupUseIndex = 6;


  void initializeResources( std::vector<int>& dResources );
  void updateResources( std::vector<int>& dResources , 
    std::multimap<BWAPI::UnitType, int>& dArmyMap );
  bool isEnoughMinerals( std::vector<int> dResources, int mineralsCost );
  bool isEnoughGas( std::vector<int> dResources, int gasCost );
  bool isEnoughMineralsGas( std::vector<int> dResources, int mineralsCost,
    int gasCost );
  void updateEffectiveMinerals( std::vector<int> dResources,
    int mineralsCost );
  void updateEffectiveGas( std::vector<int> dResources,
    int gasCost );
  void updateEffectiveMineralsGas( std::vector<int> dResources,
    int mineralsCost, int gasCost );
  void updateEffectiveResources( std::vector<int> dResources,
    std::multimap<BWAPI::UnitType, int>& dArmyMap );
}