#pragma once
#include "../Common.h"

namespace Resources{
  const int kResourcesSize = 7;

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