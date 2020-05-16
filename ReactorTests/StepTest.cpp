// clang-format off
#include "pch.h"
#include "Step.h"
// clang-format on

/*
TEST(StepTest, Create) {
  // Creating steps with non-unique names should fail
  StepPtr step01;
  StepPtr step02;
  StepPtr step01_duplicate;

  ASSERT_NO_THROW(step01 = std::make_shared<Step>("step01"));
  ASSERT_NO_THROW(step02 = std::make_shared<Step>("step02"));

  try {
    step01_duplicate = std::make_shared<Step>("step01");
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Error, step (step01) already exists.", err.what());
  }
}*/
