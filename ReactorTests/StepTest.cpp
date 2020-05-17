// clang-format off
#include "pch.h"
#include "Step.h"
// clang-format on

TEST(StepTest, Create) {
  // Creating steps with empty names should fail
  ASSERT_NO_THROW(Step stepNonEmptyName("step01"));

  try {
    Step stepEmptyName("");
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Step name must not be empty.", err.what());
  }
}
