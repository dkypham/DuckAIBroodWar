#include "MapDraw.h"

namespace MapDraw {

  // 0x01 = draw no build zones
  void drawMapInfo( std::vector<std::tuple<BWAPI::TilePosition, 
    BWAPI::TilePosition>>& noBuildZones ) {
    BWAPI::TilePosition topLeftTP = std::get<0>( noBuildZones.front() );
    BWAPI::TilePosition botRightTP = std::get<1>( noBuildZones.front() );

    BWAPI::Position topLeftPos = TileComparator::TPtoPos( topLeftTP );
    BWAPI::Position botRightPos = TileComparator::TPtoPos( botRightTP );

    BWAPI::Broodwar->drawBoxMap( topLeftPos, botRightPos, BWAPI::Colors::Red );
  }

}