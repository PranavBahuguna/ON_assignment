#include "Cursor.h"

#include <stdexcept>

Cursor::Cursor(const StepPtr root) {
  if (root == nullptr)
    throw std::invalid_argument("Error, root step cannot be null");

  m_curSteps.insert(root);
  m_visited[root] = root->getNumParentSteps();
}

// From a given step, attempts to move the cursor to all following child steps
void Cursor::move(const StepPtr stepPtr) { 
  // Validate the step argument
  if (stepPtr == nullptr)
    throw std::invalid_argument("Error, step cannot be null.");
  if (m_curSteps.find(stepPtr) == m_curSteps.end())
    throw std::invalid_argument("Error, the cursor's current locations do not contain the supplied step.");

  // Remove current step
  m_curSteps.erase(stepPtr);

  // Try visiting all child steps
  for (auto child : stepPtr->getChildren()) {

    // Add child to visited map if we haven't already done so, and decrement the number of blocking steps
    // left for the child
    auto it = m_visited.find(child);
    size_t numBlocking = (it == m_visited.end()) ? child->getNumParentSteps() : it->second;
    m_visited[child] = numBlocking - 1;

    // If there are no more blocking steps left for the child, add to current held steps
    if (m_visited[child] == 0)
      m_curSteps.insert(child);
  }
}