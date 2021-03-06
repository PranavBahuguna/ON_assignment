// clang-format off
#include "pch.h"
#include "Graph.h"
// clang-format on

namespace {
static Graph *graph;

class GraphTest : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    graph = new Graph();
    graph->addStep("Add Reagent 1", Step::Type::MANUAL, {0});
    graph->addStep("Add Reagent 2", Step::Type::MANUAL, {1});
    graph->addStep("Preheat Heater", Step::Type::AUTOMATIC, {2});
    graph->addStep("Mix Reagents", Step::Type::AUTOMATIC, {2});
    graph->addStep("Heat Sample", Step::Type::AUTOMATIC, {3, 4});
    graph->addStep("Extract Sample", Step::Type::MANUAL, {5});
  }

  static void TearDownTestCase() { delete graph; }
};

TEST_F(GraphTest, StepIndexValidation) {
  // Can access steps contained with graph range (0 - 6)
  EXPECT_EQ(graph->getNumSteps(), 6);

  ASSERT_NO_THROW(graph->getStep(0));
  ASSERT_NO_THROW(graph->getStep(1));
  ASSERT_NO_THROW(graph->getStep(2));
  ASSERT_NO_THROW(graph->getStep(3));
  ASSERT_NO_THROW(graph->getStep(4));
  ASSERT_NO_THROW(graph->getStep(5));
  ASSERT_NO_THROW(graph->getStep(6));

  // Cannot access indices higher than maximum range
  try {
    graph->getStep(7);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Step index (7) out of range.", err.what());
  }
}

TEST_F(GraphTest, AddRootNode) {
  // Adding a step with a parent at index 0 makes it a root node with a single parent
  ASSERT_NO_THROW(graph->addStep("New root node", Step::Type::AUTOMATIC, {0}));
  EXPECT_EQ(graph->getNumParents(7), 1);

  // Root adjacent child list should contain the new root index
  auto roots = graph->getAdj(0);
  EXPECT_EQ(roots.size(), 2);
  EXPECT_EQ(roots[0], 1);
  EXPECT_EQ(roots[1], 7);

  // New root's own adjacent children should be empty as no children have been added yet
  auto adj = graph->getAdj(7);
  EXPECT_TRUE(adj.empty());
}

TEST_F(GraphTest, AddChildNode) {
  // Adding a step without at least one parent will make it a child node
  ASSERT_NO_THROW(graph->addStep("New child node", Step::Type::AUTOMATIC, {1, 7}));
  EXPECT_EQ(graph->getNumParents(8), 2);

  // Each parent's adjacent child list should contain the new root index
  auto &children01 = graph->getAdj(1);
  EXPECT_EQ(children01.size(), 2);
  EXPECT_EQ(children01[0], 2);
  EXPECT_EQ(children01[1], 8);

  auto &children07 = graph->getAdj(7);
  EXPECT_EQ(children07.size(), 1);
  EXPECT_EQ(children07[0], 8);
}
} // namespace