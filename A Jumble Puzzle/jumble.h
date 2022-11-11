//Aaron Moise 20214948
#include <iostream>
using namespace std;
#pragma once

class jumblePuzzle{
private:
    int size;
    string difficulty;
    string jumble;
    
public:
    int getSize();
    string getJumble();

    //getters
    jumblePuzzle();
    jumblePuzzle(string word, string difficulty);
    jumblePuzzle(jumblePuzzle copy);
    //constructors 
}