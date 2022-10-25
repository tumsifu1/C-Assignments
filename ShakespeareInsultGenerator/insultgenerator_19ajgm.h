#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream> 
#include <set>

using namespace std;


class FileException 
//file exception if can't read or write file
{
public:
    
    FileException(const string& message); 
    //constructor for FileException
    string& what();
    //returns error message
private:
    string message;
    //error message
    
};

class NumInsultsOutOfBounds 
//exception if the requested number of insults is out of bounds
{
public:
    
    NumInsultsOutOfBounds(const string& message);
    //constructor  
    string& what();
    //returns error message

private:
    string message;
    //error message
};

class InsultGenerator
{
public:
    
    InsultGenerator(); 
    //constructor

    void initialize();
    // load all the source phrases from the InsultsSource.txt file into the attributes.

    string talkToMe() const;
    // talkToMe() returns a single insult, generated at random.

    vector<string> generate(int numInsults) const;
    // generate() generates the requested number of unique insults.

    void generateAndSave(std::string fileName, int const numInsults);
    // generateAndSave() generates the requested number of unique insults and saves them to the filename
    // supplied.  If the file cannot be written, the method should throw an exception.  Note that the
    // insults in the file should be in alphabetical order!
    // Check the number to generate limits first
private:

    vector <string> column1;
    vector <string> column2;
    vector <string> column3;
    //column 1 to 3 of the insultsourcefile

};
