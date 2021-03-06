#pragma once

#include "Graph.h"

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <mutex>

class Cursor {
public:
  Cursor(const Graph &graph);

  std::vector<size_t> move(size_t index);

private:
  const Graph m_graph;
  std::unordered_map<size_t, size_t> m_visited;
  std::unordered_set<size_t> m_curIndices;

  std::mutex m_mutex;
};
