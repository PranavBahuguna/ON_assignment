#include "ManualStep.h"

#include <Windows.h>

ManualStep::ManualStep(const std::string &name) : Step(name) {}

// Creates a messagebox asking user to perform this step
void ManualStep::start() const {
  std::string msg = "Perform manual step: " + m_name;
  MessageBoxA(NULL, msg.data(), "Manual Step", MB_ICONINFORMATION | MB_OK);
}