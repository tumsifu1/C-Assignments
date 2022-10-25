#include "insultgenerator_19ajgm.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<algorithm>

using namespace std;

FileException::FileException(const string& message) : message(message){}
string& FileException::what(){
    return message; 
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message){}
string& NumInsultsOutOfBounds::what(){
    return message;
    }

    //constructor
InsultGenerator::InsultGenerator(){}

void InsultGenerator::initialize(){

    ifstream fileIn("InsultsSource.txt");
    if(fileIn.fail()){
        FileException("File cannot be read.");
    }

    string col1, col2, col3;
    //read each column of the file seperately 

    while(fileIn >> col1 >> col2 >> col3){
        column1.push_back(col1);
        column2.push_back(col2);
        column3.push_back(col3);

    }    
    fileIn.close(); //close file
}


vector <string> InsultGenerator::generate(int size) const{
    
    if((size > 10000 || size < 1)){ //out of bounds
        throw NumInsultsOutOfBounds("Size must be between 1 and 10,000");
    }
    
    vector <string> insult; 
    //use this to delete elements from the column that have been used
    srand((unsigned int)time(NULL));
    //seed rand
    while(insult.size() < size){
    
        int word1(rand() % column1.size());
        int word2(rand() % column2.size());
        int word3(rand() % column3.size());

        insult.push_back("Thou " +column1.at(word1) + " " + column2.at(word2) + " " + column3.at(word3) + "!");

        insult.erase(unique(insult.begin(), insult.end()), insult.end());
        //erase any duplicates 
    }
    std::sort(insult.begin(), insult.end());
    //sort vector alphabetically
    
    return (insult);
}

string InsultGenerator::talkToMe() const{ //single insult generator
    srand((unsigned int)time(NULL));
    
    //seed rand()
    int word1(rand() % column1.size());
    int word2(rand() % column2.size());
    int word3(rand() % column3.size());

    return ( "Thou " + column1.at(word1) + " " + column2.at(word2) + " "  +column3.at(word3) + "!");
}

void InsultGenerator::generateAndSave(std::string filename, int const numInsults) {
    
    vector <string> insults(generate(numInsults)); //generate the insults

    int linecount(0);
   // int lines(column1.size()); //how many lines we need to write

    ofstream fileOut(filename); //file we are writing to

    if(fileOut.fail()){  //throw exception if unable to open file
        FileException("Unable to open file");
    }

    while(linecount < numInsults){
        fileOut<< insults.at(linecount) << endl;//write insults to file
        linecount++;
    }

    fileOut.close(); 
}
