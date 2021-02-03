#include "UIDraw.h"

namespace UIDraw {
  void drawUIInfo( std::multimap<BWAPI::UnitType, int> dArmyMap,
    std::multimap<BWAPI::UnitType, int> dStructMap,
    std::vector<int> dResources ) {

    BWAPI::Broodwar->drawTextScreen( 10, 40, "mins actual: " +
      dResources[0] );
    BWAPI::Broodwar->drawTextScreen( 10, 50, "mins Effective: " + 
      dResources[2] );
    BWAPI::Broodwar->drawTextScreen( 10, 60, "gas Actual: " + 
      dResources[3] );
    BWAPI::Broodwar->drawTextScreen( 10, 70, "gas Effective: " + 
      dResources[4] );
    BWAPI::Broodwar->drawTextScreen( 10, 80, "supply total Actual: " + 
      dResources[5] );
    BWAPI::Broodwar->drawTextScreen( 10, 90, "supply total Effective: " + 
      dResources[6] );

  }
}