#include "Step.h"
#include "Windows.h"

#include <stdexcept>

Step::Step(const std::string &name) : m_name(name), m_nParentSteps(0) {}

void Step::addChild(const StepPtr stepPtr) {
  if (stepPtr == nullptr)
    throw std::invalid_argument("Error, step cannot be null.");

  m_children.push_back(stepPtr);
  ++stepPtr->m_nParentSteps;
}

// For now, this simply runs a sleep for 3 seconds
void Step::performTask() { Sleep(3000); }
