#include "UIDraw.h"

namespace UIDraw {
  void drawUIInfo( std::multimap<BWAPI::UnitType, int> dArmyMap,
    std::multimap<BWAPI::UnitType, int> dStructMap,
    std::vector<int> dResources,
    std::queue<BuildOrderElement>& buildOrderListPtr ) {
    
    BWAPI::Broodwar->drawTextScreen( 10, 40, "mins actual: %i\n", 
      dResources[0] );
    BWAPI::Broodwar->drawTextScreen( 10, 50, "mins effective: %i\n",
      dResources[1] );
    BWAPI::Broodwar->drawTextScreen( 10, 60, "gas actual: %i\n",
      dResources[2] );
    BWAPI::Broodwar->drawTextScreen( 10, 70, "gas effective: %i\n",
      dResources[3] );
    BWAPI::Broodwar->drawTextScreen( 10, 80, "supply actual: %i\n",
      dResources[4] );
    BWAPI::Broodwar->drawTextScreen( 10, 90, "supply effective: %i\n",
      dResources[5] );
    BWAPI::Broodwar->drawTextScreen( 10, 100, "supply used: %i\n",
      dResources[6] );

    BWAPI::Broodwar->drawTextScreen( 10, 120, 
      "Next in build order : at supply: %i\n",
      //std::to_string(buildOrderListPtr.front().BOuT), 
      buildOrderListPtr.front().BOsupply );


  }
}