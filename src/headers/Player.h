#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Body.h"
#include "Helm.h"
#include "Pants.h"
#include "Shield.h"
#include "Weapon.h"

class Player : public Creature{
public:
	Player();
	Player(std::string, int, int, int, int);
	int getLevel();
	int getXp();
	Weapon getWep();
	Shield getShield();
	Helm getHelm();
	Body getBody();
	Pants getPants();
	void addXp(int);
	Weapon setWep(Weapon);
	Shield setShield(Shield);
	Helm setHelm(Helm);
	Body setBody(Body);
	Pants setPants(Pants);

private:
	int level;
	int experience;
	Weapon weapon;
	Shield shield;
	Helm helm;
	Body body;
	Pants pants;
  void calculateStats();
};
#endif
