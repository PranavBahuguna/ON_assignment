// clang-format off
#include "pch.h"
#include "Cursor.h"
#include "Graph.h"
// clang-format on

namespace {
static Cursor *cursor;

class CursorTest : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Graph graph;
    graph.addStep("Add Reagent 1", {0});
    graph.addStep("Add Reagent 2", {1});
    graph.addStep("Preheat Heater", {2});
    graph.addStep("Mix Reagents", {2});
    graph.addStep("Heat Sample", {3, 4});
    graph.addStep("Extract Sample", {5});

    cursor = new Cursor(graph);
  }

  static void TearDownTestCase() { delete cursor; }
};

TEST_F(CursorTest, CursorMove) {
  // Cursor should initially hold only index 0, and can be moved from there
  std::vector<size_t> newIndices;
  ASSERT_NO_THROW(newIndices = cursor->move(0));

  // Move function should return the newly available step index (1) from the graph
  EXPECT_EQ(newIndices.size(), 1);
  EXPECT_EQ(newIndices[0], 1);
}

TEST_F(CursorTest, CursorMoveFromInvalidIndexFails) {
  // Cannot access indices higher than maximum range
  try {
    cursor->move(7);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Step index (7) out of range.", err.what());
  }

  // Cannot access indices the cursor isn't currently located at
  try {
    cursor->move(2);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Cursor does not currently hold a location at step index (2).", err.what());
  }
}
} // namespace