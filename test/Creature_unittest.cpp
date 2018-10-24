#include "../src/headers/Creature.h"
#include "gtest/gtest.h"

Creature defaultCreature = Creature();
Creature constructedCreature = Creature("Example", 100, 87);

TEST(CreatureTest, getMaxHealth) {
  EXPECT_EQ(10, defaultCreature.getMaxHealth());
  EXPECT_EQ(100, constructedCreature.getMaxHealth());
}

TEST(CreatureTest, getHealth) {
  EXPECT_EQ(10, defaultCreature.getHealth());
  EXPECT_EQ(87, constructedCreature.getHealth());
}

/* consider using sutomated testing to test sub/add health */