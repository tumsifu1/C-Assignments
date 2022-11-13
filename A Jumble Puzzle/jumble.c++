//Aaron Moise 20214948
#include <iostream>
#include "jumble.h"
using namespace std;

//default Constructor
JumblePuzzle::JumblePuzzle(){
    jumble = NULL;
    row = 0;
    col = 0;
    size = 0;
    direction = 0;
}

JumblePuzzle::JumblePuzzle(const string& hiddenWord, const string& diff){
    int randDir;
    string directions = "nsew";
    int wordLength = hiddenWord.length();


    if(wordLength < 3 || wordLength > 10){
        throw BadJumbleException("Word should be between 3 and 10 letters");
    }

    //set the size of the game using provided difficulty
    if(diff == "easy"){
        size = 2 * wordLength;
    }else if(diff == "medium"){
        size = 3 * wordLength;
    }else if(diff == "hard"){
        size = 4 * wordLength;
    }else{
        throw BadJumbleException("Invalid difficult, difficulty must be easy, medium or hard");
    }
    
    int randVar = rand() % 4;
    
    //generating random column and row position between 0-size-1
    col = rand() % (size-1);
    row = rand() % (size -1);
    

    //radom directions
    int directionNS[4] = {-1, 0, 1, 0};
    int directionEW[4] = {0, 1, 0, -1};
    
    //choose a random direction from north, east, south and west
    direction = directions[randVar];
    //chose the placement of the word
    int nIncrement = directionNS[randVar];
    int eIncrement = directionEW[randVar];
    //if incrementing north to south make sure that there is enough space 
    if(nIncrement == 1){
        row = rand() % (size-1) - wordLength;
    }else if(nIncrement == 0){
        row = rand() % (size - 1);
    }else if(nIncrement == -1)
    //if too far in a column
    if(eIncrement == 1 || eIncrement == -1 ){
        col = rand() % (size -1) - wordLength;
    }else if(eIncrement == 0){
        col = rand() % (size -1)
    }
    
}
/*

char JumblePuzzle::getDirection(){
    switch(rand() % 4){
        case 0:
            return('n');
            break;
        case 1:
            return('e');
            break;
        case 2:
            return('s');
            break;
        case 3:
            return('w');
            break;
    }
}*/
int JumblePuzzle::getColPos(){
    return col;
}

int JumblePuzzle::getRowPos(){
    return row;
}

int JumblePuzzle::getSize(){
    return size;
}

char JumblePuzzle::getDirection(){
    return direction;
}







BadJumbleException::BadJumbleException(const string& msg){
    message = msg;
}

string BadJumbleException::what() const{
    return message;
}