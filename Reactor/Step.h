#pragma once

#include <memory>
#include <string>

class Step;
typedef std::shared_ptr<Step> StepPtr;

class Step {
public:
  Step(const std::string &name);

  enum class Type { MANUAL, AUTOMATIC };

  virtual void start() const = 0;
  std::string getName() { return m_name; }

protected:
  std::string m_name;
};
