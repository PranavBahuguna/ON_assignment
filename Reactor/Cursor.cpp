#include "Cursor.h"

#include <stdexcept>

Cursor::Cursor(const Graph &graph) : m_graph(graph) {
  m_curSteps.insert(0);
  m_visited[0] = 0;
}

// From a given step, attempts to move the cursor to all following child steps
std::vector<size_t> Cursor::move(size_t index) {
  // Validate the given index
  if (!m_graph.isIndexInRange(index))
    throw std::invalid_argument("Step index (" + std::to_string(index) + ") out of range.");
  if (!hasLocationAt(index))
    throw std::invalid_argument("Cursor does not currently hold a location at step index (" +
                                std::to_string(index) + ").");

  // Remove current step
  m_curSteps.erase(index);
  std::vector<size_t> newSteps;

  // Try visiting all child steps
  for (size_t childIdx : m_graph.getAdj(index)) {

    // Add child to visited map if we haven't already done so, and decrement the number of blocking
    // steps left for the child
    auto it = m_visited.find(childIdx);
    size_t numBlocking = (it == m_visited.end()) ? m_graph.getNumParents(childIdx) : it->second;
    m_visited[childIdx] = numBlocking - 1;

    // If there are no more blocking steps left for the child, add to current held steps
    if (m_visited[childIdx] == 0) {
      m_curSteps.insert(childIdx);
      newSteps.push_back(childIdx);
    }
  }

  return newSteps; // return the newly added steps we can reach now
}

// Checks if the cursor currently holds a location at the given index
bool Cursor::hasLocationAt(size_t index) const {
  return m_curSteps.find(index) != m_curSteps.end();
}
