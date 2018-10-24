#include <iostream>
#include <cmath>
#include "headers/Player.h"

Player::Player() {
  std::string temp;
  std::cout << "What is your name? ";
	std::cin >> temp;
  setName(temp);
  level = 1;
	experience = 0;
	weapon = Weapon("Wooden Sword", 1, 5);
  calculateStats();
}

Player::Player(std::string n, int m, int h, int l, int e) {
  setName(n);
  setMaxHealth(m);
  setHealth(h);
	level = l;
	experience = e;
  // Set up equipment
  calculateStats();
}

void Player::calculateStats() {
  setAttack(weapon.getStat());
  int sum = 0;
  sum += getWep().getStat();
	sum += getShield().getStat();
	sum += getHelm().getStat();
	sum += getBody().getStat();
	sum += getPants().getStat();
  setDefense(sum);
}

// XP (need to actually do this)
void Player::addXp(int xp) {
	experience += xp;
	if (experience > ((level + 2) ^ 2)) {
		experience -= ((level + 2) ^ 2);
		level += 1;
	}
}

// Getters
int Player::getLevel() { return level; }

int Player::getXp() { return experience; }

Weapon Player::getWep() { return weapon; }

Shield Player::getShield() { return shield; }

Helm Player::getHelm() { return helm; }

Body Player::getBody() { return body; }

Pants Player::getPants() { return pants; }

// Setters
Weapon Player::setWep(Weapon new_weapon) { // Returns old wep
	Weapon old_weapon = weapon;
	weapon = new_weapon;
	return weapon;
}

Shield Player::setShield(Shield new_shield) { // Returns old shield
	Shield old_shield = shield;
	shield = new_shield;
	return old_shield;
}

Helm Player::setHelm(Helm new_helm) { // Returns old helm
	Helm old_helm = helm;
	helm = new_helm;
	return old_helm;
}

Body Player::setBody(Body new_body) { // Returns old body
	Body old_shield = body;
	body = new_body;
	return old_shield;
}

Pants Player::setPants(Pants new_pants) { // Returns old pants
	Pants old_shield = pants;
	pants = new_pants;
	return old_shield;
}