#include "Cursor.h"
#include "Step.h"
#include "Graph.h"

#include <Windows.h>

int main() {
  try {
    // Create and link workflow graph
    Graph graph(6);
    graph.addStep(1, "Add Reagent 1");
    graph.addStep(2, "Add Reagent 2", { 1 });
    graph.addStep(3, "Preheat Heater", { 2 });
    graph.addStep(4, "Mix Reagents", { 2 });
    graph.addStep(5, "Heat Sample", { 3, 4 });
    graph.addStep(6, "Extract Sample", { 5 });

    Cursor cursor(graph);
    cursor.move(1);

  } catch (std::exception &e) {
    printf(e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}