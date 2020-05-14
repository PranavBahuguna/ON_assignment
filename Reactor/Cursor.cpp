#include "Cursor.h"

Cursor::Cursor(const StepPtr root) { curSteps.insert(root); }

// From a given step, attempts to move the cursor to all following child steps
void Cursor::move(const StepPtr stepPtr) { 
  // Remove current step
  curSteps.erase(stepPtr);
  
  // Try adding all child steps
  for (auto child : stepPtr->getChildren()) {
    if (child->canStart())
      curSteps.insert(child);
  }
}