#include "../Common.h"

struct BuildOrderElement {
  BWAPI::UnitType BOuT;
  BWAPI::TechType BOtT;
  int BOsupply;

public:
  BuildOrderElement( BWAPI::UnitType uT, BWAPI::TechType tT, int supply ) {
    BOuT = uT;
    BOtT = tT;
    BOsupply = supply;
  }

};