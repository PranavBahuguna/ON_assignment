#include "Process.h"

#include <thread>

Process::Process(const Graph &graph) : m_graph(graph), m_cursor(graph) {}

void Process::start() {
  printf("Starting process...\n");
  startTask(0);
  printf("Process completed.\n");
}

void Process::startTask(size_t index) {
  // Do the actual work
  StepPtr stepPtr = m_graph.getStep(index);
  if (stepPtr != nullptr) {
    printf("Starting step %s...\n", stepPtr->getName().data());
    stepPtr->start();
    printf("Finished step %s...\n", stepPtr->getName().data());
  }

  // Find new available step indices, and start worker threads on them
  std::vector<std::thread> threads;
  auto newIndices = m_cursor.move(index);
  
  for (size_t newIndex : newIndices)
    threads.push_back(std::thread(&Process::startTask, this, newIndex));

  for (auto &thread : threads)
    thread.join();
}
