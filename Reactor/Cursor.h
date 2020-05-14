#pragma once

#include "Step.h"

#include <unordered_set>

class Cursor {
public:
  Cursor(const StepPtr root);

  std::unordered_set<StepPtr> getSteps() { return curSteps; }
  void move(const StepPtr stepPtr);

private:
  std::unordered_set<StepPtr> curSteps;
};
