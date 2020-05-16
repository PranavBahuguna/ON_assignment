// clang-format off
#include "pch.h"
#include "Cursor.h"
#include "Graph.h"
// clang-format on

namespace {
static Graph graph;
static Cursor *cursor;

class CursorTest : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    graph.addStep("Add Reagent 1");
    graph.addStep("Add Reagent 2", {1});
    graph.addStep("Preheat Heater", {2});
    graph.addStep("Mix Reagents", {2});
    graph.addStep("Heat Sample", {3, 4});
    graph.addStep("Extract Sample", {5});

    cursor = new Cursor(graph);
  }

  static void TearDownTestCase() { delete cursor; }
};

TEST_F(CursorTest, CursorTraversalFromOutOfRangeIndexFails) {
  // Cannot access 0 index or indices higher than maximum range
  try {
    cursor->move(0);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Step index (0) out of range.", err.what());
  }

  try {
    cursor->move(7);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Step index (7) out of range.", err.what());
  }
}

TEST_F(CursorTest, CursorTraversalFromNonLocatedIndicesFails) {
  // Cannot access indices the cursor isn't currently located at
  try {
    cursor->move(2);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Cursor is not currently located at step index (2).", err.what());
  }
}
} // namespace