#pragma once

#include "Step.h"

class ManualStep : public Step {
public:
  ManualStep(const std::string &name);

  void start() const override;
};