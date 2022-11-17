#ifndef HANDS_H
#define HANDS_H
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

#define ROCK u8"\U0000270A"
#define PAPER u8"\U0000270B"
#define SCISSORS u8"\U0001F44C"
#define LIZARD u8"\U0001F918"
#define SPOCK u8"\U0001F596"

#define ROCK2 u8"\U0001F5FB"
#define PAPER2 u8"\U0001F4C3"
#define SCISSORS2 u8"\U0001F52A"
#define LIZARD2 u8"\U0001F438"
#define SPOCK2 u8"\U0001F596"


/**
 * Hands
 *
 * @description: A static class that only has references to
 *      emojis for printing out Rock Paper Scissors Lizard Spock
 *
 * @methods:
 *      string RandHand()   : returns a random hand (emoji)
 *      string Rock()       : returns the emoji for "rock"
 *      string Paper()      : returns the emoji for "paper"
 *      string Scissors()   : returns the emoji for "scissors"
 *      string Lizard()     : returns the emoji for "lizard"
 *      string Spock()      : returns the emoji for "spock"
 */
struct Hands {
    const string rock = ROCK2;
    const string paper = PAPER2;
    const string scissors = SCISSORS2;
    const string lizard = LIZARD2;
    const string spock = SPOCK2;

    static map<string, string> Emojis;  // stl map
    //         name  , emoji

    static map<string, string> Names;  // stl map
    //         emoji  , name

    static string RandHand() {
        auto it = Emojis.begin();  // iterator to front of map

        std::advance(it, rand() % Emojis.size());  // advance some random amnt of steps

        string random_hand = it->second;  // grab emoji from map

        return random_hand;  // return rand emoji
    }

    static string Rock() {
        return Emojis["rock"];
    }
    static string Paper() {
        return Emojis["paper"];
    }
    static string Scissors() {
        return Emojis["scissors"];
    }
    static string Lizard() {
        return Emojis["lizard"];
    }
    static string Spock() {
        return Emojis["spock"];
    }
};

// initialize static data member for
// hands struct (class)
map<string, string> Hands::Emojis = {
    {"rock", ROCK2},
    {"paper", PAPER2},
    {"scissors", SCISSORS2},
    {"lizard", LIZARD2},
    {"spock", SPOCK2}};

// initialize static data member for
// hands struct (class)
map<string, string> Hands::Names = {
    {ROCK2, "rock"},
    {PAPER2, "paper"},
    {SCISSORS2, "scissors"},
    {LIZARD2, "lizard"},
    {SPOCK2, "spock"}};

#endif  // HANDS_H