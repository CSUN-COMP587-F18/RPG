#include "../src/headers/Player.h"
#include "gtest/gtest.h"

Player constructedPlayer = Player("Name", 100, 95, 10, 1000);

TEST(PlayerTest, getName) {
  EXPECT_EQ("", constructedPlayer.getName());
}

TEST(PlayerTest, getMaxHealth) {
  EXPECT_EQ(100, constructedPlayer.getMaxHealth());
}

TEST(PlayerTest, getHealth) {
  EXPECT_EQ(95, constructedPlayer.getHealth());
}

TEST(PlayerTest, getLevel) {
  EXPECT_EQ(10, constructedPlayer.getLevel());
}

TEST(PlayerTest, getXp) {
  EXPECT_EQ(1000, constructedPlayer.getXp());
}


/*
	Weapon getWep();
	Shield getShield();
	Helm getHelm();
	Body getBody();
	Pants getPants();
	Weapon setWep(Weapon);
	Shield setShield(Shield);
	Helm setHelm(Helm);
	Body setBody(Body);
	Pants setPants(Pants);
*/