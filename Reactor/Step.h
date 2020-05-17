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

  void start();
  std::string getName() { return m_name; }

private:
  std::string m_name;
};
