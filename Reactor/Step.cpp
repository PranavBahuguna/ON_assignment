#include "Step.h"
#include "Windows.h"

#include <stdexcept>

Step::Step(const std::string &name) {
  // Check if a step with this name already exists
  if (_stepNameMap.find(name) != _stepNameMap.end())
    throw std::invalid_argument("Error, step with that name already exists");

  _stepNameMap.insert(name);
  m_name = name;
}

// For now, this simply runs a sleep for 3 seconds
void Step::performTask() { Sleep(3000); }
