#include "AutomaticStep.h"

#include <Windows.h>

AutomaticStep::AutomaticStep(const std::string &name) : Step(name) {}

// Runs a sleep for 3 seconds to simulate an automatic process
void AutomaticStep::start() const { Sleep(3000); }
