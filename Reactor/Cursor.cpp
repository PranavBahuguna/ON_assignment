#include "Cursor.h"

#include <stdexcept>

Cursor::Cursor(const Graph &graph) : m_graph(graph) {
  for (size_t root : m_graph.getRoots()) {
    m_curSteps.insert(root);
    m_visited[root] = 0;
  }
}

// From a given step, attempts to move the cursor to all following child steps
void Cursor::move(size_t index) {
  // Validate the given index
  if (!m_graph.isIndexInRange(index))
    throw std::invalid_argument("Step index (" + std::to_string(index) + ") out of range.");
  if (m_curSteps.find(index) == m_curSteps.end())
    throw std::invalid_argument("Cursor is not currently located at step index (" +
                                std::to_string(index) + ").");

  // Remove current step
  m_curSteps.erase(index);

  // Try visiting all child steps
  for (size_t childIdx : m_graph.getAdj(index)) {

    // Add child to visited map if we haven't already done so, and decrement the number of blocking
    // steps left for the child
    auto it = m_visited.find(childIdx);
    size_t numBlocking = (it == m_visited.end()) ? m_graph.getNumParents(childIdx) : it->second;
    m_visited[childIdx] = numBlocking - 1;

    // If there are no more blocking steps left for the child, add to current held steps
    if (m_visited[childIdx] == 0)
      m_curSteps.insert(childIdx);
  }
}