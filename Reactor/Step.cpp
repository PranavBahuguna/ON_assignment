#include "Step.h"
#include "Windows.h"

Step::Step(const std::string &name) : m_name(name), m_nRemainingParentSteps(0) {}

void Step::addChild(const StepPtr stepPtr) {
  if (stepPtr == nullptr)
    return;

  m_children.push_back(stepPtr);
  stepPtr->addParentStep();
}

void Step::addParentStep() { ++m_nRemainingParentSteps; }

void Step::removeParentStep() { --m_nRemainingParentSteps; }

// Checks if we can start this step
bool Step::canStart() const { return m_nRemainingParentSteps == 0; }

// For now, this simply runs a sleep for 3 seconds
void Step::performTask() {
  Sleep(3000);

  // Decrements the number of parent steps remaining for all direct children by one.
  for (auto &child : m_children)
    child->removeParentStep();
}
