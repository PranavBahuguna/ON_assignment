#pragma once

#include "Step.h"

#include <unordered_set>
#include <vector>

class Graph {
public:
  Graph();

  void addStep(const std::string &name, const std::vector<size_t> &parents = {});
  StepPtr getStep(size_t index) const;
  const std::vector<size_t>& getAdj(size_t index) const;
  const std::vector<size_t>& getRoots() const;
  size_t getNumParents(size_t index) const;
  bool isIndexInRange(size_t index) const;

private:
  const static int ROOT_INDEX = 0;

  void validateIndex(size_t index) const;

  std::vector<StepPtr> m_steps;
  std::vector<size_t> m_nParents;
  std::vector<std::vector<size_t>> m_adjList;
};