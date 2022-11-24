#include <iostream>
#include <vector>
#include <string>
#include "helpers.hpp"

using namespace std;

#pragma once

class Die {
    int sides;
public:
    Die():sides{6}{}
    Die(int sides):sides{sides}{}
    int roll(int rolls = 1) {
        int sum = 0;
        while(rolls--){
            sum += (rand() % sides) + 1;
        }
        return sum;
    };
    
    friend ostream& operator<<(ostream &os,const Die& d){
        return os <<"["<< d.sides<<"]";
    }
};


class Dice {
private:
    vector< Die > dice;
    bool average;
    bool best;
    bool constant;
    int x = 0;

public:

    Dice() {
        init(1,6);
    }
    Dice(int n, int s) {
        init(n,s);
    }
    Dice(string d) {
    	int n = 0, s = 0;
    	
        vector<string> dot_parts = tokenize(d,".");
        vector<string> plus_parts = tokenize(d,"+");
        
		if (dot_parts[0] == "a") {
			this->average = true;
			n = stoi(dot_parts[1]);
        	s = stoi(dot_parts[3]);
		}
		else if (dot_parts[0] == "b") {
			this->best = true;
			n = stoi(dot_parts[1]);
        	s = stoi(dot_parts[3]);
		}
		else {
			if ((dot_parts[1] == "d") && (dot_parts[2].length() < 3)) {
	        	n = stoi(dot_parts[0]);
	        	s = stoi(dot_parts[2]);
			}
			else if ((dot_parts[1] == "d") && (dot_parts[2].length() >= 3)) {
				this->constant = true;
				n = stoi(dot_parts[0]);
	        	s = stoi((tokenize(plus_parts[0],"."))[2]);
	        	this->x = stoi(plus_parts[1]);
			}
		}

        init(n,s);
    }

    void init(int n,int s){
        while (n--) {
            dice.push_back(Die(s));
        }
    }

    /**
     * @brief Roll the dice and return the sum
     * 
     * @param rolls 
     * @return int : sum of rolls
     */
    int roll(int rolls = 1) {
        int sum = 0;
        while(rolls--){
            for (int i = 0; i < dice.size(); i++) {
				sum += dice[i].roll();
            }
        }
        return sum + x;
    }

    /**
     * @brief Roll the dice and return the maximum dice value
     * 
     * @param None 
     * @return int : max value of all die being rolled
     */
    int maxRoll() {
        int max = 0;
        for (int i = 0; i < dice.size(); i++) {
        	if (max < dice[i].roll()) max = dice[i].roll();
        }
        // YOU MUST IMPLEMENT
        return max;
    }

    /**
     * @brief Roll the dice and return the AVG dice value
     * 
     * @param None 
     * @return int : AVG value of all die being rolled
     */
    int avgRoll() {
        int avg;
        avg = this->roll()/dice.size();
        // YOU MUST IMPLEMENT
        return avg;
    }


    friend ostream& operator<<(ostream &os,const Dice& d){
        for(int i=0;i<d.dice.size();i++){
            os << d.dice[i];
        }
        return os;
    }
};
