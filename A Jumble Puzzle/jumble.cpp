//Aaron Moise 20214948
#include <string>
#include <iostream>
#include <ctime>
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

JumblePuzzle::JumblePuzzle(const JumblePuzzle& obj){
    int i,j;
    size = obj.size;
    row = obj.col;
    col = obj.row;
    direction = obj.direction;

    if(obj.getJumble()){
        jumble = new char*[size];
        for( i = 0; i < size; i++){
            jumble[i] = new char[size];
        }
        for( i = 0; i < size; i++){
            for(j = 0; j < size; j++){
                jumble[i][j] = obj.getJumble()[i][j];
            }
        }

    }

}

JumblePuzzle::JumblePuzzle(const string& hiddenWord, const string& diff){
    //seed the randomizer
    srand(time(NULL));  
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

   //choose random placement of hidden word
    col = rand() % (size-1);
    row = rand() % (size-1);

    //check there is enough space in the given direction
    bool placed = false;

    while(placed == false){
        if(direction == 's' && ((size-row) >= wordLength)){
            placed = true;
        }else if(direction == 'n' && (row >= wordLength)){
            placed = true;
        }else if(( direction == 'e') && (size - col >= wordLength )){
            placed = true;
        }else if(direction == 'w' && col >=wordLength){
            placed = true;
        }else{
            direction = directions[(rand() % 3)];
        }
    }


    //direction of the jumble in numeric form
    int nIncrement = 0;
    int eIncrement = 0;
    
    if(direction == 'n'){
        nIncrement = -1;
        eIncrement = 0;
    }else if(direction == 's'){
        nIncrement = 1;
        eIncrement = 0;
    }else if(direction == 'w'){
        nIncrement = 0;
        eIncrement = -1;
    }else{
        nIncrement = 0;
        eIncrement = 1;
    }
    //allocate enough memory to the jumble
    jumble = new char*[size];
    
    //provide the array enough size for each row
    int i,j;
    for(i = 0; i < size; i++){
        jumble[i] = new char[size];
    }
     //build the jumble with random letters
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            jumble[i][j] = rand() % 26 + 'a';
        }
    }
    //set starting location of the jumble
    i = row;
    j = col;
    int k;
    //set the jumble to the hidden word
    for(k = 0; k < wordLength; k++){
        jumble[i][j] = hiddenWord[k];
        i += nIncrement;
        j += eIncrement;
    }
}

//getters
int JumblePuzzle::getColPos() const{
    return col;
}

int JumblePuzzle::getRowPos() const{
    return row;
}

int JumblePuzzle::getSize() const{
    return size;
}

char JumblePuzzle::getDirection() const{
    return direction;
}

charArrayPtr* JumblePuzzle::getJumble() const{
    charArrayPtr* jumbleCopy = new char*[size];
    int i,j;
    for(i = 0; i < size; i ++){
        jumbleCopy[i] = new char[size];
    }

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            jumbleCopy[i][j] = jumble[i][j];
        }
    }
    return jumbleCopy;
}

//decstructor
JumblePuzzle::~JumblePuzzle(){
    for(int i = (size-1); i >= 0; i--){
        //deallocate Heap meory
        delete[] jumble[i]; 
        jumble[i] = NULL;
    }
    delete[] jumble;
    jumble = NULL;
}

JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& obj){
    if(this != &obj){
        int i,j;
        //deallocate heap mem
        for(i = size-1; i>=0 ; i--){
            delete[] jumble[i];
        }
        delete[] jumble;

        //assign varaibles and jumble
        size = obj.getSize();
        col = obj.getColPos();
        row = obj.getRowPos();
        direction = obj.getDirection();

        if(obj.getJumble()){
            jumble = new char*[size];
            for(i =0; i<size; i++){
                jumble[i] = new char[size];
            }
            for(i=0; i<size; i++){
                for(j=0; j<size; j++){
                    jumble[i][j] = obj.getJumble()[i][j];
                }
            }
        }
    }
    return *this;
}
//exception
BadJumbleException::BadJumbleException(const string& msg){
    message = msg;
}

string BadJumbleException::what() const{
    return message;
}