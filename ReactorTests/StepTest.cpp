// clang-format off
#include "pch.h"
#include "AutomaticStep.h"
#include "ManualStep.h"
// clang-format on

TEST(StepTest, Create) {
  // Creating steps with empty names should fail
  ASSERT_NO_THROW(AutomaticStep stepNonEmptyName("step01"));

  try {
    AutomaticStep stepEmptyName("");
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Step name must not be empty.", err.what());
  }
}
