#include "Step.h"

#include <stdexcept>

Step::Step(const std::string &name) {
  if (name.empty())
    throw std::invalid_argument("Step name must not be empty.");

  m_name = name;
}
