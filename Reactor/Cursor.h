#pragma once

#include "Step.h"
#include "Graph.h"

#include <unordered_set>
#include <unordered_map>
#include <memory>

class Cursor {
public:
  Cursor(const Graph &graph);

  std::unordered_set<size_t> getSteps() { return m_curSteps; }
  void move(size_t index);

private:
  const Graph m_graph;
  std::unordered_map<size_t, size_t> m_visited;
  std::unordered_set<size_t> m_curSteps;
};
