#pragma once

#include "Step.h"

#include <unordered_set>
#include <vector>

class Graph {
public:
  Graph(size_t numSteps);

  void addStep(size_t sIndex, const std::string &name, const std::vector<size_t> &parents = {});
  Step getStep(size_t index) const;
  std::vector<size_t> getAdj(size_t index) const;
  std::vector<size_t> getRoots() const;
  size_t getNumParents(size_t index) const;
  bool isStepIndexInRange(size_t sIndex) const;

private:
  const static int ROOT_INDEX = 0;

  std::vector<StepPtr> m_steps;
  std::vector<size_t> m_nParents;
  std::vector<std::vector<size_t>> m_adjList;
};