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

  size_t getNumParents() const { return m_nParents; }
  std::vector<StepPtr> getChildren() const { return m_children; }
  std::string getName() const { return m_name; }

private:
  size_t m_nParents;
  std::string m_name;
  std::vector<StepPtr> m_children;
};
