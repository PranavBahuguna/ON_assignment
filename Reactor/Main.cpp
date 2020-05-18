#include "Graph.h"
#include "Process.h"

#include <Windows.h>

int main() {
  try {
    // Create and link workflow graph
    Graph graph;
    graph.addStep("Add Reagent 1", {0});
    graph.addStep("Add Reagent 2", {1});
    graph.addStep("Preheat Heater", {2});
    graph.addStep("Mix Reagents", {2});
    graph.addStep("Heat Sample", {3, 4});
    graph.addStep("Extract Sample", {5});

    Process process(graph);
    process.start();

  } catch (std::exception &e) {
    printf(e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}