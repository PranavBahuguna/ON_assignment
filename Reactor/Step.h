#pragma once

#include <memory>
#include <string>
#include <vector>

class Step;
typedef std::shared_ptr<Step> StepPtr;

class Step {
public:
  Step(const std::string &name);

  void addChild(const StepPtr stepPtr);
  void performTask();

  bool canStart() const;
  size_t getRemainingParentSteps() const { return m_nRemainingParentSteps; }
  std::vector<StepPtr> getChildren() const { return m_children; }
  std::string getName() const { return m_name; }

protected:
  void addParentStep();
  void removeParentStep();

private:
  size_t m_nRemainingParentSteps;
  std::string m_name;
  std::vector<StepPtr> m_children;
};
