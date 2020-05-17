#pragma once

#include "Cursor.h"
#include "Graph.h"
#include "Step.h"

#include <queue>

class Process {
public:
  Process(const Graph &graph);

  void start();

private:
  void startTask(size_t index);

  Cursor m_cursor;
  const Graph m_graph;
  std::queue<size_t> m_indexQueue;
};