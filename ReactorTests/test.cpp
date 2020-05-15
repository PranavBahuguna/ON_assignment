#include "pch.h"
#include "Step.h"

TEST(StepTest, AddingNullChildFails) {
  Step step01("step01");
  step01.addChild(nullptr);

  EXPECT_EQ(step01.getChildren().size(), 0);
}
