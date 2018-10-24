#include <iostream>
#include <fstream>
#include "headers/World.h"
#include "headers/Dungeon.h"

World::World(){}

World::~World(){}

void World::mainMenu(){
	int choice = 0;

	while (choice != 3) {
		std::cout << "Welcome to RPG!" << std::endl;
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1 - New Game" << std::endl;
		std::cout << "2 - Load save" << std::endl;
		std::cout << "3 - Quit" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;

		switch(choice){
			case 1:		//New Game
				p = new Player();
				loadedMenu();
				break;
			case 2:		//Load
				load();
				loadedMenu();
				break;
			case 3:		//Quit
				std::cout << "Bye!" << std::endl;
				break;
			default:
				std::cout << "Please enter a valid number.\n" << std::endl;	
		}
	}			
}

void World::loadedMenu(){
	int choice = 0;

	while (choice != 5 && p->getHealth() > 0) {
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1 - Enter dungeon" << std::endl;
		std::cout << "2 - Rest Up" << std::endl;
		std::cout << "3 - Status" << std::endl;
		std::cout << "4 - Save" << std::endl;
		std::cout << "5 - Quit" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;

		switch(choice){
			case 1:		//enter dungeon
				enterDung(0);
				break;
			case 2:		//rest
				p->addHealth(5);
				std::cout << std::endl;
				break;
			case 3:		//status
				std::cout << "Health: " << p->getHealth() << std::endl;
				std::cout << "Level: " << p->getLevel() << std::endl;
				//std::cout << "XP to level: " << p->getXP() << std::endl; //Not implimented
				std::cout << std::endl;
				break;
			case 4:		//save
				save();
				break;
			case 5:		//Exit
				break;
			default:
				std::cout << "Please enter a valid number.\n" << std::endl;	
		}
	}
}

void World::enterDung(int difficulty){  //difficulty not yet implimented
	Dungeon d = Dungeon();
	int status;
	char choice = 'y';

	std::cout << "You enter the dungeon..." << std::endl;
	status = d.combat(p);

	while (status == 2 && choice != 'n' && choice != 'N') {
		std::cout << "Continue to next level? (Y/N)" << std::endl;
		std::cin >> choice;

		if (choice == 'y' || choice == 'Y') {
			std::cout << "You continue on...\n" << std::endl;
			d.nextLevel();
			status = d.combat(p);
		}
	}

	if (status == 0) {
		p->subHealth(p->getHealth());
		std::cout << "You are revived in town.\n" << std::endl;
	}

	else
		std::cout << "You emerge from the dugeon.\n" << std::endl;
}

void World::save(){
	std::string name;
	std::fstream f;
	bool valid = true;
	char choice;

	while(valid){
		std::cout << "Enter a name: ";
		std::cin >> name;

		f.open("saves/" + name, std::fstream::in);

		if(f.peek() != std::ifstream::traits_type::eof()){
			std::cout << "A file with that name already exists, would you like to overwrite this? (Y/N)";
			std::cin >> choice;
			if(choice == 'Y' || choice == 'y')
				valid = false;

			else
				f.close();	
		}
		else
			valid = false;	
	}

	f.close();

	f.open("saves/" + name, std::fstream::out);

	f << p->getName() << std::endl;
	f << p->getMaxHealth() << std::endl;
	f << p->getHealth() << std::endl;
	f << p->getLevel() <<  std::endl;
	f << p->getXp() << std::endl;

	f.close();
}

void World::load(){
	std::string name;
	std::fstream f;
	char choice;
	bool valid = true;
	int stats[5] = {};

	while(valid){
		std::cout << "Enter the name of the file to load: ";
		std::cin >> name;

		f.open("saves/" + name, std::fstream::in);

		if(f.peek() != std::ifstream::traits_type::eof()){
			std::cout << "A file with that name already exists, would you like to overwrite it? (Y/N)";
			std::cin >> choice;
			if(choice == 'Y' || choice == 'y')
				valid = false;

			else
				f.close();	
		}
		else
			valid = false;	
	}
	f.open("saves/" + name, std::fstream::in);

	for(int i = 0; i < 5; i++)
		f >> stats[i];

  // TODO Fix this
	//p = new Player(stats[0], stats[1], stats[2], stats[3], stats[4]);

	f.close();
}