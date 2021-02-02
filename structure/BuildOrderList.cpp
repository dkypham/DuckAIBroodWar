#include "BuildOrderList.h"

namespace BuildOrderList {
  static BWAPI::UnitType CC = BWAPI::UnitTypes::Terran_Command_Center;
  static BWAPI::UnitType SD = BWAPI::UnitTypes::Terran_Supply_Depot;
  static BWAPI::UnitType BARRACKS = BWAPI::UnitTypes::Terran_Barracks;
  static BWAPI::UnitType REFINERY = BWAPI::UnitTypes::Terran_Refinery;
  static BWAPI::UnitType FACTORY = BWAPI::UnitTypes::Terran_Factory;
  static BWAPI::UnitType MACHINESHOP = BWAPI::UnitTypes::Terran_Machine_Shop;
  static BWAPI::TechType SIEGE = BWAPI::TechTypes::Tank_Siege_Mode;

  void initializeBuildOrder( std::queue<BuildOrderElement>& buildOrderList,
    BWAPI::Race enemyRace ) {
    initOneFactFE( buildOrderList );
  }

  void addToBuildOrder( std::queue<BuildOrderElement>& buildOrderList,
    BWAPI::UnitType uT, BWAPI::TechType tT, int supply ) {
    buildOrderList.push( BuildOrderElement( uT, tT, supply ) );
  }

  void initOneFactFE( std::queue<BuildOrderElement>& buildOrderList ) {
    addToBuildOrder( buildOrderList, SD, NULL, 9 );
    addToBuildOrder( buildOrderList, BARRACKS, NULL, 12 );
    addToBuildOrder( buildOrderList, REFINERY, NULL, 12 );
    addToBuildOrder( buildOrderList, SD, NULL, 15 );
    addToBuildOrder( buildOrderList, FACTORY, NULL, 16 ); // 2 scv off gas
    addToBuildOrder( buildOrderList, MACHINESHOP, NULL, 20 ); // 2 scv on gas
    addToBuildOrder( buildOrderList, NULL, SIEGE, 22 );
    addToBuildOrder( buildOrderList, SD, NULL, 23 );
    addToBuildOrder( buildOrderList, CC, NULL, 28 );
    addToBuildOrder( buildOrderList, SD, NULL, 28 );
    addToBuildOrder( buildOrderList, FACTORY, NULL, 32 );
    addToBuildOrder( buildOrderList, SD, NULL, 500 );
  }

}