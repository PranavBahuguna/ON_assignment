#pragma once

#include "Step.h"

class AutomaticStep : public Step {
public:
  AutomaticStep(const std::string &name);

  void start() const override;
};