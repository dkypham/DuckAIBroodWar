#pragma once

#include "../Common.h"
#include "TileComparator.h"/

namespace MapDraw {
  // 0x01 = draw no build zones
  void drawMapInfo( std::vector<std::tuple<BWAPI::TilePosition,
    BWAPI::TilePosition>>& noBuildZones );

};