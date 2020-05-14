#include "Cursor.h"
#include "Step.h"

#include <Windows.h>

int main() {
  try {
    // Create workflow steps and link together
    StepPtr ws1 = std::make_shared<Step>("Add Reagent 1");
    StepPtr ws2 = std::make_shared<Step>("Add Reagent 2");
    StepPtr ws3 = std::make_shared<Step>("Preheat Heater");
    StepPtr ws4 = std::make_shared<Step>("Mix Reagents");
    StepPtr ws5 = std::make_shared<Step>("Heat Sample");
    StepPtr ws6 = std::make_shared<Step>("Extract Sample");

    ws1->addChild(ws2);
    ws2->addChild(ws3);
    ws2->addChild(ws4);
    ws3->addChild(ws5);
    ws4->addChild(ws5);
    ws5->addChild(ws6);

    Cursor cursor(ws1);
    ws1->performTask();
    cursor.move(ws1);

  } catch (std::exception &e) {
    printf(e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}