#pragma once

#include "Cursor.h"
#include "Graph.h"

class Process {
public:
  Process(const Graph &graph);

  void start();

private:
  void startTask(size_t index);

  Cursor m_cursor;
  const Graph m_graph;
};
