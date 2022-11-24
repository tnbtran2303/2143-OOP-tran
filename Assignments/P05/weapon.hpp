#include <iostream>
#include <string>
#include <vector>

#include "dice.hpp"
#include "helpers.hpp"

using namespace std;

#pragma once

class Weapon {

public:
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    Dice*  die;

    /**
     * @brief Construct a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     */
    Weapon() {
        name = "Fists&Feet";
        damage = randomChoice({"1.d.4", "1.d.6"});
        die = new Dice(damage);
    }
    /**
     * @brief Overloaded Constructor for a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     * @param choices-vector of string "die" choices like {"2.d.8","2.d.10","3.d.4"}
     */
    Weapon(string w_name) {
    	if (w_name == "Sword") {
    		name = w_name;
	        damage = randomChoice({"1.d.12", "2.d.6", "3.d.4"});
	        die = new Dice(damage);
		}
		if (w_name == "Bow") {
    		name = w_name;
	        damage = randomChoice({"1.d.8", "2.d.4", "1.d.10"}); 
	        die = new Dice(damage);
		}
		if (w_name == "Magic") {
    		name = w_name;
	        damage = randomChoice({"1.d.20", "2.d.10", "3.d.6", "5.d.4"});
	        die = new Dice(damage);
		}
        if (w_name == "Fire") {
    		name = w_name;
	        damage = randomChoice({"1.d.6", "1.d.8"});
	        die = new Dice(damage);
		}
		
    }

    double use() {
        return die->roll();
    }
/*
    friend ostream& operator<<(ostream& os, const Weapon& w) {
        return os << "[" << w.name << " , " << w.damage << "]";
    }
    */
    
    friend ostream& operator<<(ostream& os, const Weapon& w) {
        return os << w.name;
    }
};
