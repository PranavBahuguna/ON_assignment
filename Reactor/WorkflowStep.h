#pragma once

#include <memory>
#include <string>
#include <vector>

class WorkflowStep {
public:
  WorkflowStep(const std::string &name);

  void addChild(const std::shared_ptr<WorkflowStep> stepPtr);

private:
  std::string m_name;
  std::vector<std::shared_ptr<WorkflowStep>> m_children;
};
