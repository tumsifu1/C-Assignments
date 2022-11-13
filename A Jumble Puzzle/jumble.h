//Aaron Moise 20214948
#include <iostream>
using namespace std;
#pragma once

typedef char* charArrayPtr;

class JumblePuzzle{
private:
    int size;
    int row;
    int col;
    charArrayPtr* jumble;
    char direction;
    char genRandomDirection();
    
public:

    //default constructor
    JumblePuzzle();
    //constructor for the puzzle 
    JumblePuzzle(const string& word, const string& difficulty);
    //copy constructor
    JumblePuzzle(const JumblePuzzle& Orginal);

    //getters
    int getSize();
    int getRowPos();
    int getColPos();
    char getDirection();
    charArrayPtr* getJumble() const; //returns coppy of the whole jumble
};

//exception class
class BadJumbleException{
public:
    string what() const;
    BadJumbleException(const string& msg);

private:
    string message;
};