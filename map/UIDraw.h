#pragma once

#include "../Common.h"
#include "../structure/BuildOrderElement.h"

namespace UIDraw {
  const int kColOne = 10;
  const int kColTwo = 390;

  const int kRowOne = 40;
  const int kRowTwo = 50;
  const int kRowThree = 60;
  const int kRowFour = 70;
  const int kRowFive = 80;
  const int kRowSix = 90;
  const int kRowSeven = 80;
  const int kRowEight = 90;
  const int kRowNine = 80;
  const int kRowTen = 90;

  void drawUIInfo( std::multimap<BWAPI::UnitType, int> dArmyMap,
    std::multimap<BWAPI::UnitType, int> dStructMap , 
    std::vector<int> dResources,
    std::queue<BuildOrderElement>& buildOrderListPtr );
};