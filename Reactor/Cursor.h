#pragma once

#include "Step.h"

#include <unordered_set>
#include <unordered_map>

class Cursor {
public:
  Cursor(const StepPtr root);

  std::unordered_set<StepPtr> getSteps() { return m_curSteps; }
  void move(const StepPtr stepPtr);

private:
  std::unordered_map<StepPtr, size_t> m_visited;
  std::unordered_set<StepPtr> m_curSteps;
};
