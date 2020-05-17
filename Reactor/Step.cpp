#include "Step.h"
#include "Windows.h"

#include <stdexcept>

Step::Step(const std::string &name) {
  if (name.empty())
    throw std::invalid_argument("Step name must not be empty.");

  m_name = name;
}

// For now, this simply runs a sleep for 3 seconds
void Step::performTask() { Sleep(3000); }
