#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "weapon.hpp"
#include "helpers.hpp"

using namespace std;

#pragma once


class BaseFighter {
	
public:
	
    string name;
    double rr;
    int hp;
	int damage;
    Weapon *weapon;
    Weapon *weapon_1;
    Weapon *weapon_2;
	
    BaseFighter() {
        name = "None";
        hp = (rand() % 5) + 3;
        rr = (rand() % 11) * 0.06 + 0.15;
        weapon = new Weapon;
        damage = weapon->use();
    }
    BaseFighter(string f_name) {
    	if (f_name == "Warrior") {
    		name = f_name;
	        hp = (rand() % 5) + 3;
	        rr = (rand() % 11) * 0.06 + 0.15;
	        weapon = new Weapon("Sword");
	        damage = weapon->use();
		}
		if (f_name == "Wizard") {
    		name = f_name;
	        hp = (rand() % 5) + 3;
	        rr = (rand() % 11) * 0.06 + 0.15;
	        weapon = new Weapon("Magic");
	        damage = weapon->use();
		}
		if (f_name == "Archer") {
    		name = f_name;
	        hp = (rand() % 5) + 3;
	        rr = (rand() % 11) * 0.06 + 0.15;
	        weapon = new Weapon("Bow");
	        damage = weapon->use();
		}
		if (f_name == "Elf") {
    		name = f_name;
	        hp = (rand() % 5) + 3;
	        rr = (rand() % 11) * 0.06 + 0.15;
	        weapon_1 = new Weapon("Magic");
	        weapon_2 = new Weapon("Sword");
	        weapon = new Weapon("Magic");
	        damage = weapon_1->use() + weapon_2->use();
		}
		if (f_name == "DragonBorn") {
    		name = f_name;
	        hp = (rand() % 5) + 3;
	        rr = (rand() % 11) * 0.06 + 0.15;
	        weapon_1 = new Weapon("Magic");
	        weapon_2 = new Weapon("Fire");
	        weapon = new Weapon("Magic");
	        damage = weapon_1->use() + weapon_2->use();
		}
    	
	}
	
    virtual double attack(const BaseFighter& f){

        	return f.damage;
    }
    
    int get_hp(const BaseFighter& f){
    	return f.hp;
	}

	friend ostream& operator<<(ostream& os, const BaseFighter& f) {
		return os << f.name;


    		
	}


};
