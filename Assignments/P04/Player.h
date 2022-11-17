#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <random>

#include "Hands.h"
using namespace std;

/**
 * Player
 *
 * @description: A class that represents a player in the game.
 *     A player has two weapons and a hand to hold one of them
 *
 * @methods:
 *      void change()                       : changes the hand to the other weapon
 *      void updateResHand(string)          : updates the hand to another weapon
 *      string getWeapon1()                 : returns the hand
 *      string getWeapon2()                 : returns the other weapon
 *      bool operator==(Player)             : compares if two players are equal
 *      bool operator>(Player)              : compares if this player is greater than the other
 *      static bool winner(string, string)  : compares two hands to see who wins
 */
struct Player {
    string weapon1;
    string weapon2;
    // other possible stuff
    string resHand;
    /**
     * Constructor guarantees a player has two different "weapons"
     */
    Player() {
        weapon1 = Hands::RandHand();
        weapon2 = Hands::RandHand();

        // if both weapons are the same
        // choose another.
        while (weapon2 == weapon1) {
            weapon2 = Hands::RandHand();
        }
    }

    // Change the hand to the other weapon
    void change() {
        int step = rand() % 5;
        while (step >= 0) {
            --step;
            weapon1 = Hands::RandHand();
        }

        step = rand() % 5;
        while (step >= 0) {
            --step;
            weapon2 = Hands::RandHand();
        }
        // choose another.
        while (weapon2 == weapon1) {
            weapon2 = Hands::RandHand();
        }
        resHand = "";
    }

    void updateResHand(string _resHand) {
        resHand = _resHand;
    }

    string getWeapon1() const {
        return weapon1;
    }

    string getWeapon2() const {
        return weapon2;
    }

    bool operator==(const Player& a) const {
        return (weapon1 == a.weapon1 && weapon2 == a.weapon1);
    }

    bool operator>(Player& a) {
        if (winner(weapon1, a.weapon1)) {
            resHand = weapon1;
            a.updateResHand(a.weapon1);
            return true;
        }
        if (weapon1 == a.weapon1 && winner(weapon2, a.weapon2)) {
            resHand = weapon2;
            a.updateResHand(a.weapon2);

            return true;
        }
        return false;
    }

    static bool winner(string emojisP1, string emojisP2) {
        map<string, vector<string>>
            law = {{ROCK2, {LIZARD2, SCISSORS2}},
                   {PAPER2, {ROCK2, SPOCK2}},
                   {SCISSORS2, {LIZARD2, PAPER2}},
                   {LIZARD2, {SPOCK2, PAPER2}},
                   {SPOCK2, {ROCK2, SCISSORS2}}};
        auto it = std::find(law[emojisP1].begin(), law[emojisP1].end(), emojisP2);
        if (it != law[emojisP1].end())
            return true;
        return false;
    }
};

#endif  // PLAYER_H