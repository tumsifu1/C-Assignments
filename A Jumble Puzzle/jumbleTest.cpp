#include <string>
#include <iostream>
#include <ctime>
#include "jumble.cpp"
using namespace std;

int main(){
    JumblePuzzle* game1 = new JumblePuzzle("batman", "easy");
    cout<< "testing/n";
    cout<< game1->getRowPos();


}