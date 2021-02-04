#include "BuildingPlacement.h"

namespace BuildingPlacement {
  BWAPI::TilePosition naiveBuild( BWAPI::Unit builder, BWAPI::UnitType buildingType ) {
    BWAPI::TilePosition ret;
    int maxDist = 3;
    int stopDist = 40;
    BWAPI::TilePosition aroundTile = builder->getTilePosition();

    if (buildingType != BWAPI::UnitTypes::Terran_Refinery) {
      while ((maxDist < stopDist)) {
        for (int i = aroundTile.x - maxDist; i <= aroundTile.x + maxDist; i++) {
          for (int j = aroundTile.y - maxDist; j <= aroundTile.y + maxDist; j++) {
            if (BWAPI::Broodwar->canBuildHere( BWAPI::TilePosition( i, j ), buildingType )
              && BWAPI::Broodwar->canBuildHere( BWAPI::TilePosition( i + 2, j ), buildingType )) {
              bool unitsInWay = false;
              for (BWAPI::Unit u : BWAPI::Broodwar->getAllUnits()) {
                //if (u.getID() == builder.getID())
                //	continue;
                if ((std::abs( u->getTilePosition().x - i ) < 4)
                  && (std::abs( u->getTilePosition().y - j ) < 4))
                  unitsInWay = true;
              }
              return BWAPI::TilePosition( i, j );

            }
          }
        }
        maxDist += 2;
      }
    }
    // building is terran refinery
    else {
      for ( BWAPI::Unit u : BWAPI::Broodwar->getNeutralUnits() ) {
        if (( u->getType() == BWAPI::UnitTypes::Resource_Vespene_Geyser)
          && (std::abs( u->getTilePosition().x - aroundTile.x ) < stopDist)
          && (std::abs( u->getTilePosition().y - aroundTile.y ) < stopDist))
          return u->getTilePosition();
      }
    }
  }
}