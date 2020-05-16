#include "pch.h"
#include "Step.h"

TEST(StepTests, AddChild) { 
  StepPtr step01 = std::make_shared<Step>("step01");
  StepPtr step02 = std::make_shared<Step>("step02");

  EXPECT_EQ(step01->getChildren().size(), 0);
  EXPECT_EQ(step02->getNumParents(), 0);

  ASSERT_NO_THROW(step01->addChild(step02));

  // Number of children held by parent, and number of parents held by children should be incremented
  EXPECT_EQ(step01->getChildren().size(), 1);
  EXPECT_EQ(step02->getNumParents(), 1);
}

TEST(StepTests, AddNullChildFails) {
  StepPtr step01 = std::make_shared<Step>("step01");

  try {
    step01->addChild(nullptr);
    FAIL();
  } catch (std::invalid_argument &err) {
    ASSERT_STREQ("Error, step cannot be null.", err.what());
  }

  EXPECT_TRUE(step01->getChildren().empty());
}
