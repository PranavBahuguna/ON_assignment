#pragma once

#include "Graph.h"
#include "Step.h"

#include <memory>
#include <unordered_map>
#include <unordered_set>

class Cursor {
public:
  Cursor(const Graph &graph);

  std::unordered_set<size_t> getSteps() { return m_curSteps; }
  std::vector<size_t> move(size_t index);

  bool hasLocationAt(size_t index) const;

private:
  const Graph m_graph;
  std::unordered_map<size_t, size_t> m_visited;
  std::unordered_set<size_t> m_curSteps;
};
