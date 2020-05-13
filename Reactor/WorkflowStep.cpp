#include "WorkflowStep.h"

WorkflowStep::WorkflowStep(const std::string &name) : m_name(name) {}

void WorkflowStep::addChild(const std::shared_ptr<WorkflowStep> stepPtr) {
  m_children.push_back(stepPtr);
}