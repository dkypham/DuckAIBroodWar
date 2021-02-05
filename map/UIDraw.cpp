#include "UIDraw.h"

namespace UIDraw {
  void drawUIInfo(std::multimap<BWAPI::UnitType, int> dArmyMap,
                  std::multimap<BWAPI::UnitType, int> dStructMap,
                  std::vector<int> dResources,
                  std::queue<BuildOrderElement>& buildOrderListPtr) {

    // Column One Info
    BWAPI::Broodwar->drawTextScreen(kColOne, kRowOne, "mins actual: %i\n",
                                    dResources[0]);
    BWAPI::Broodwar->drawTextScreen(kColOne, kRowTwo, "mins effective: %i\n",
                                    dResources[1]);
    BWAPI::Broodwar->drawTextScreen(kColOne, kRowThree, "gas actual: %i\n",
                                    dResources[2]);
    BWAPI::Broodwar->drawTextScreen(kColOne, kRowFour, "gas effective: %i\n",
                                    dResources[3]);
    BWAPI::Broodwar->drawTextScreen(kColOne, kRowFive, "supply actual: %i\n",
                                    dResources[4]);
    BWAPI::Broodwar->drawTextScreen(kColOne, kRowSix, "supply effective: %i\n",
                                    dResources[5]);
    BWAPI::Broodwar->drawTextScreen(kColOne, kRowSeven, "supply used: %i\n",
                                    dResources[6]);
    BWAPI::Broodwar->drawTextScreen(kColOne, kRowNine,
                                    "Next in build order : at supply: %i\n",
                                    buildOrderListPtr.front().BOsupply);

    // Column Two Info
    BWAPI::Broodwar->drawTextScreen(kColTwo, kRowOne, "FPS: %d", 
                                    BWAPI::Broodwar->getFPS());
  }
}