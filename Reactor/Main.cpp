#include "Graph.h"
#include "Process.h"

#include <Windows.h>

int main() {
  try {
    // Create and link workflow graph
    Graph graph;
    graph.addStep("Add Reagent 1", Step::Type::MANUAL, {0});
    graph.addStep("Add Reagent 2", Step::Type::MANUAL, {1});
    graph.addStep("Preheat Heater", Step::Type::AUTOMATIC, {2});
    graph.addStep("Mix Reagents", Step::Type::AUTOMATIC, {2});
    graph.addStep("Heat Sample", Step::Type::AUTOMATIC, {3, 4});
    graph.addStep("Extract Sample", Step::Type::MANUAL, {5});

    Process process(graph);
    process.start();

  } catch (std::exception &e) {
    printf(e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}