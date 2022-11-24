#include <iostream>
#include <string>

#include "weapon.hpp"
#include "fighter.hpp"
#include "dice.hpp"
#include "helpers.hpp"

#include <fstream>

// the number of fighters in each round
#define Num_Fighters 100

using namespace std;

int main() {
    
    // the vector to save the name of fighters
    vector <string> d_names;
    vector <string> a_names;
    
    // the vector to save the hp of fighters
    vector <int> d_hps;
    vector <int> a_hps;
    
    // the vector to save the damages of fighters
    vector <int> d_damages;
    vector <int> a_damages;
    
    // the vector to save the regeneration of fighters
    vector <double> d_regs;
    vector <double> a_regs;
    
    // the vector to save the weapon's name of fighters
    vector <string> d_weapons;
    vector <string> a_weapons;
    
    // variable to save current fighter' name
    string a_name;
    string d_name;
    
    // variable to save current fighters's No and last fighter's No
    int d_no = 0, a_no = 0;
    
    // the number of total fighters and round
    int number_fighters = 0, round = 1;
    
    // the won numbers
    int a_win_num = 0, d_win_num = 0;
    
    // to check expiring of fighters
    bool d_inc = false, a_inc = false;
    
    // the number of expired fighters
    int a_exp_num = 0, d_exp_num = 0;

    // read the source data oneline by oneline 
    ifstream input_f("input.dat.txt");
    
    while (std::getline(input_f, a_name)){
    	
    	// save the fighter's name into vector
    	a_names.push_back(a_name);
    	
    }
    
    input_f.close();
    
    // to get the number of total fighters
    number_fighters = a_names.size();

    
    // loop for getting information of fighters
    for (int i = 0; i < number_fighters; i++){
    	
    	//=================== Attacker =====================//
    	
    	// make object of BaseFighter class and save attacker information into vector
    	BaseFighter *att = new BaseFighter(a_names[i]);
    	
    	// save attacker's hp into vector
    	a_hps.push_back(att->hp);//att->hp
    	
    	// save attacker's damage into vector
    	a_damages.push_back(att->damage);
    	
    	// save attacker's regeneration into vector
    	a_regs.push_back(att->rr);
    	
    	// save attacker's weapon name into vector
    	if ((a_name == "Elf") || (a_name == "DragonBorn"))
    		a_weapons.push_back(att->weapon_1->name + " + " + att->weapon_2->name);
    	
		else
    		a_weapons.push_back(att->weapon->name);
    	
    	//==================== Defender ======================//
    	// same as above
    	
    	d_name = randomChoice({"Warrior", "Wizard", "Archer", "Elf", "DragonBorn"});
    	
    	BaseFighter *def = new BaseFighter(d_name);
    	
    	d_names.push_back(def->name);
    	
    	d_hps.push_back(def->hp);
    	
    	d_damages.push_back(def->damage);
    	
    	d_regs.push_back(def->rr);
    	
    	if ((d_name == "Elf") || (d_name == "DragonBorn"))
    		d_weapons.push_back(def->weapon_1->name + " + " + def->weapon_2->name);
    	
		else
    		d_weapons.push_back(def->weapon->name);
    	
	}
	
	// make object of BaseFighter class for defender and attacker
	BaseFighter *defender = new BaseFighter();
	BaseFighter *attacker = new BaseFighter();
	
	
	// loop through all fighters
	while(1){
		
		// loop till the expired number of defender or attacker equals Num_Fighters(100)
		while((a_exp_num < Num_Fighters) && (d_exp_num < Num_Fighters)){
			
			cout<<"( ROUND "<<round<<" ) Attacker : Defender"<<endl;
			
			// display the current fighters's information
			cout<<a_names[a_no]<<" ( hp: "<<a_hps[a_no]<<", weapon: "
				<<a_weapons[a_no]<<", damage: "<<a_damages[a_no]<<" )"
				<<" : "<<d_names[d_no]<<" ( hp: "<<d_hps[d_no]<<", weapon: "
				<<d_weapons[d_no]<<", damage: "<<d_damages[d_no]<<" )"<<endl;
			
			cout<<"Fighting..."<<endl<<endl;
			
			
			// if the current defender is expired after fighting, the No of defenders increases.
			// if not, the current defender's hp decrease as the current attacker's damage
			if ((d_hps[d_no] - a_damages[a_no]) <= 0){
				
				// increase the number of defenders and expired number
				d_no++;
				d_exp_num++;
				d_inc = true;
				
				// break the while loop
				if ((d_no) == number_fighters) break;
			}
			
			else {
				
				d_hps[d_no] = d_hps[d_no] - a_damages[a_no];
			}
			
			// if the current attacker is expired after fighting, the No of attacker increases.
			// if not, the current attacker's hp decrease as the current defender's damage
			if (d_inc == true){
				
				if ((a_hps[a_no] - d_damages[d_no-1]) <= 0){
				
					// increase the number of attackers and expired number
					a_no++;
					a_exp_num++;
					a_inc = true;
					
					// break the while loop
					if ((a_no) == number_fighters) break;
				}
				
				else {
					
					a_hps[a_no] = a_hps[a_no] - d_damages[d_no-1];
					
				}
			}
			
			else {
				if ((a_hps[a_no] - d_damages[d_no]) <= 0){
				
					// increase the number of attackers and expired number
					a_no++;
					a_exp_num++;
					
					// break the while loop
					if ((a_no) == number_fighters) break;
				}
				
				else {
					
					a_hps[a_no] = a_hps[a_no] - d_damages[d_no];
					
				}
			}
			
			d_inc = false;
			
		}
		
		
		
		// display the expired number of fighters in current round.
		cout<<endl<<"========================================"<<endl<<endl;
		
		cout<<"The expired number of Attackers and Defenders in Round "
			<<round<<" : "<<a_exp_num<<" : "<<d_exp_num<<endl;
		
		// display the fighting result in current round.
		if (d_exp_num > a_exp_num){
			
			// increase the won number
			a_win_num++;
			cout<<"Attacker won in Round "<<round<<endl;
		}
		
		else {
			
			// increase the won number
			d_win_num++;
			cout<<"Defender won in Round "<<round<<endl;
		}
		
		// display the scores
		cout<<"Scores : (Attacker : Defecder) "<<a_win_num<<" : "<<d_win_num<<endl;
		
		cout<<endl<<"========================================"<<endl;
		
		// break the while loop
		if (((a_no) == number_fighters) ||
				((d_no) == number_fighters)) break;
		
		// increase the number of round
		round++;
		
		// initialize the expired number of attackers and defenders in current round
		a_exp_num = 0;
		d_exp_num = 0;
		
	}
	
	
	// display the total result
	if (a_win_num > d_win_num)
		cout<<"ATTACKER WON. CONGRATULATION !!!"<<endl;
	else if (a_win_num < d_win_num)
		cout<<"DEFENDER WON. CONGRATULATION !!!"<<endl;
	else
		cout<<"ATTACKER and DEFENDER IS ENDING. CONGRATULATION !!!"<<endl;
	
	
    return 0;
    
}
