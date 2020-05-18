#pragma once

#include <memory>
#include <string>

class Step;
typedef std::shared_ptr<Step> StepPtr;

class Step {
public:
  Step(const std::string &name);

  enum class Type { MANUAL, AUTOMATIC };

  void start();
  std::string getName() { return m_name; }

private:
  std::string m_name;
};
