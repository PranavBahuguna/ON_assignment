#include "pch.h"
#include "Cursor.h"

TEST(CursorTests, ConstructWithNullRootFails) {
  try {
    Cursor cursor(nullptr);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Error, root step cannot be null.", err.what());
  }
}

TEST(CursorTests, Move) {
  StepPtr step01 = std::make_shared<Step>("step01");
  StepPtr step02 = std::make_shared<Step>("step02");
  StepPtr step03 = std::make_shared<Step>("step03");
  step01->addChild(step02);
  step01->addChild(step03);

  Cursor cursor(step01);

  // On initial construction, held steps should include step01 only
  EXPECT_EQ(cursor.getSteps().size(), 1);
  EXPECT_TRUE(cursor.getSteps().find(step01) != cursor.getSteps().end());

  ASSERT_NO_THROW(cursor.move(step01));

  // After move, held steps should now contain step02 and step03, with step01 being discarded
  EXPECT_EQ(cursor.getSteps().size(), 2);
  EXPECT_TRUE(cursor.getSteps().find(step02) != cursor.getSteps().end());
  EXPECT_TRUE(cursor.getSteps().find(step03) != cursor.getSteps().end());
}

TEST(CursorTests, MoveFromNullStepFails) {
  StepPtr step01 = std::make_shared<Step>("step01");
  Cursor cursor(step01);

  try {
    cursor.move(nullptr);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Error, step cannot be null.", err.what());
  }
}

TEST(CursorTests, MoveFromNonContainedStepFails) {
  StepPtr step01 = std::make_shared<Step>("step01");
  StepPtr step02 = std::make_shared<Step>("step02");
  step01->addChild(step02);

  // Cursor will have only step01 in currently held steps for now
  Cursor cursor(step01);

  try {
    // Cursor does not contain step02 in currently held steps yet, so this should fail
    cursor.move(step02);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Error, the cursor's current locations do not contain the supplied step.", err.what());
  }
}