#pragma once

#include <memory>
#include <string>
#include <vector>
#include <unordered_set>

class Step;
typedef std::shared_ptr<Step> StepPtr;

class Step {
public:
  Step(const std::string &name);

  void performTask();

private:
  std::string m_name;
};
