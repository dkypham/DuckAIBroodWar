#include "MapDraw.h"

namespace MapDraw {

  // 0x01 = draw no build zones
  void drawMapInfo( std::vector<std::pair<BWAPI::TilePosition, 
    BWAPI::TilePosition>>& noBuildZones ) {
    BWAPI::TilePosition topLeftTP = noBuildZones.front().first;
    BWAPI::TilePosition botRightTP = noBuildZones.front().second;

    BWAPI::Position topLeftPos = TileComparator::TPtoPos( topLeftTP );
    BWAPI::Position botRightPos = TileComparator::TPtoPos( botRightTP );

    BWAPI::Broodwar->drawBoxMap( topLeftPos, botRightPos, BWAPI::Colors::Red );
  }

}