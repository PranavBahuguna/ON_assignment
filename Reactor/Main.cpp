#include "WorkflowStep.h"

#include <Windows.h>

int main() {
  try {
    // Create workflow steps and link together
    auto ws1 = std::make_shared<WorkflowStep>("Add Reagent 1");
    auto ws2 = std::make_shared<WorkflowStep>("Add Reagent 2");
    auto ws3 = std::make_shared<WorkflowStep>("Preheat Heater");
    auto ws4 = std::make_shared<WorkflowStep>("Mix Reagents");
    auto ws5 = std::make_shared<WorkflowStep>("Heat Sample");
    auto ws6 = std::make_shared<WorkflowStep>("Extract Sample");

    ws1->addChild(ws2);
    ws2->addChild(ws3);
    ws2->addChild(ws4);
    ws3->addChild(ws5);
    ws4->addChild(ws5);
    ws5->addChild(ws6);

  } catch (std::exception &e) {
    printf(e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}