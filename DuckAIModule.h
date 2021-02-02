#pragma once
#include "Common.h"
#include "economy/WorkerManager.h"
#include "structure/BuildOrderList.h"

// Remember not to use "Broodwar" in any global class constructor!

class DuckAIModule : public BWAPI::AIModule {
public:
  // Virtual functions for callbacks, leave these as they are.
  virtual void onStart();
  virtual void onFrame();
  virtual void onUnitCreate(BWAPI::Unit unit);
  virtual void onUnitDestroy(BWAPI::Unit unit);
  virtual void onUnitMorph(BWAPI::Unit unit);

  virtual void onUnitComplete(BWAPI::Unit unit);
  // Everything below this line is safe to modify.

};
