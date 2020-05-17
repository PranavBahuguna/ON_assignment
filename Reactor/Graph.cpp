#include "Graph.h"

#include <memory>
#include <stdexcept>

Graph::Graph() {
  // Initialise the root (0) index, all subsequent steps are indexed from 1
  m_steps.push_back(nullptr);
  m_nParents.push_back(0);
  m_adjList.push_back({});
}

// Add a new step to the graph
void Graph::addStep(const std::string &name, const std::vector<size_t> &parents) {
  size_t index = m_steps.size();

  if (parents.empty()) {
    // If step has no parents, this is a root
    m_adjList[ROOT_INDEX].push_back(index);
    m_nParents.push_back(1);
  } else {
    // Link to all parent steps
    for (size_t pIndex : parents) {
      validateIndex(pIndex);
      m_adjList[pIndex].push_back(index);
    }
    m_nParents.push_back(parents.size());
  }

  m_steps.push_back(std::make_shared<Step>(name));
  m_adjList.push_back({});
}

// Gets the step at the given index
StepPtr Graph::getStep(size_t index) const {
  validateIndex(index);

  return m_steps[index];
}

// Gets all adjacent children for a step at a given index
const std::vector<size_t> &Graph::getAdj(size_t index) const {
  validateIndex(index);

  return m_adjList[index];
}

// Gets the number of parents for a step at a given index
size_t Graph::getNumParents(size_t index) const {
  validateIndex(index);

  return m_nParents[index];
}

// Checks if a given step index is within the bounds of the graph
bool Graph::isIndexInRange(size_t index) const { return index < m_steps.size(); }

// Returns the number of steps in the graph
size_t Graph::getNumSteps() const { return m_steps.size() - 1; }

// Performs validation for a given step index, throws error if invalid
void Graph::validateIndex(size_t index) const {
  if (!isIndexInRange(index))
    throw std::invalid_argument("Step index (" + std::to_string(index) + ") out of range.");
}
