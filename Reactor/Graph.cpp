#include "Graph.h"

#include <memory>
#include <stdexcept>

Graph::Graph(size_t numSteps) {
  m_steps.resize(numSteps + 1);
  m_steps[0] = nullptr;
  m_nParents.resize(numSteps + 1);
  m_adjList.resize(numSteps + 1);
}

void Graph::addStep(size_t sIndex, const std::string &name, const std::vector<size_t> &parents) {
  if (!isStepIndexInRange(sIndex))
    throw std::invalid_argument("Step index out of range.");

  m_steps[sIndex] = std::make_shared<Step>(name);

  if (parents.empty()) {
    // If step has no parents, this is a root
    m_adjList[ROOT_INDEX].push_back(sIndex);
  } else {
    // Link to all parent steps
    for (size_t pIndex : parents) {
      if (!isStepIndexInRange(pIndex))
        throw std::invalid_argument("Parent step index out of range.");

      m_adjList[pIndex].push_back(sIndex); 
    }
  }
  m_nParents[sIndex] = parents.size();
}

// Gets the step at the given index
Step Graph::getStep(size_t index) const {
  if (!isStepIndexInRange(index))
    throw std::invalid_argument("Step index out of range.");

  return *m_steps[index];
}

// Gets all adjacent children for a step at a given index
std::vector<size_t> Graph::getAdj(size_t index) const {
  if (!isStepIndexInRange(index))
    throw std::invalid_argument("Step index out of range.");

  std::vector<size_t> adj;
  for (size_t adjIdx : m_adjList[index])
    adj.push_back(adjIdx);

  return adj;
}

// Gets the graph's root nodes
std::vector<size_t> Graph::getRoots() const { return getAdj(ROOT_INDEX); }

// Gets the number of parents for a step at a given index
size_t Graph::getNumParents(size_t index) const {
  if (!isStepIndexInRange(index))
    throw std::invalid_argument("Step index out of range.");

  return m_nParents[index];
}

// Checks if a given step index is within the bounds of the graph
bool Graph::isStepIndexInRange(size_t index) const {
  return index > 0 || index < m_steps.size();
}
