//Aaron Moise 19ajgm
#include "fraction_19ajgm.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//fraction exception
FractionException::FractionException(const string& message) : message(message){
}
string FractionException::what(){
    return message;
}

//default constructor
Fraction::Fraction(){
    this->num = 0;
    this->den = 1;
}
//getter for numerator
int Fraction::numerator() const{
    return num;
}

//getter for denominator
int Fraction::denominator() const {
    return den;
}

//find greatest common divisor 
int Fraction::findGCD(int num1, int num2){
    num1 = abs(num1); //get abs value before finding gcd
    num2 = abs(num2);

    int gcd;
    for(int i = 1; i<= num1 && i <= num2; i++){
        if(num1%i == 0 && num2%i == 0)
            gcd = i;
        }
        return gcd;
}  

//one input constructor 
Fraction::Fraction(int numerator){
    num = numerator;
    den = 1;
}

//two input constructor
Fraction::Fraction(int numerator, int denominator){
    if(denominator == 0)
        throw FractionException("CANNOT HAVE 0 IN DENOMINATOR ");
    
    int gcd = findGCD(numerator, denominator);
    if( denominator < 0 && numerator < 0){ //if denominator and numerator are negative
        this->num = abs(numerator/gcd);
        this->den = abs(denominator/gcd);
    }else if( denominator < 0){
        this->num = -numerator/gcd;
        this->den = -(denominator/gcd);
    }else{
        this->num = numerator/gcd;
        this->den = denominator/gcd;
    }
}

ostream& operator<<(ostream& out, const Fraction &frac){
    out << frac.numerator() << "/" << frac.denominator();
    return out;
}

istream& operator>>(istream& in, Fraction& frac){
    int numerator, denominator;
    //read numerator
    in >> numerator; 
    if(in.peek() != 10){ //if next key pressed is not enter
        char nextChar;
        in >> nextChar;
        if(nextChar == '/')
            in >> denominator;
        else 
            denominator = 1;
        frac = Fraction(numerator, denominator);
    }else 
        frac = Fraction(numerator);
    return in;
}

Fraction operator+(const Fraction &lhs, const Fraction &rhs ){
    int denominator, numerator;// local den and num
    denominator = lhs.denominator() * rhs.denominator(); //den for new fraction
    numerator = (lhs.numerator() * rhs.denominator()) + ( lhs.denominator() * rhs.numerator()); //numerator of new faction
    return Fraction(numerator, denominator);
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs ){
    int denominator, numerator;
    denominator = lhs.denominator() * rhs.denominator(); 
    numerator = (lhs.numerator() * rhs.denominator()) - ( lhs.denominator() * rhs.numerator()); 
}
Fraction operator*(Fraction const &lhs, Fraction const &rhs){
    int denominator, numerator;
    numerator = lhs.numerator() * rhs.numerator();
    denominator = lhs.denominator() * rhs.denominator();
    return Fraction(numerator, denominator);
}
 
Fraction operator/(Fraction const &lhs, Fraction const &rhs){
    int den1, num1;
    den1 = (lhs.denominator() * rhs.numerator());
    num1 = (lhs.numerator() * rhs.denominator()); 
    return Fraction(num1, den1);
}

bool operator>(Fraction const &frac1, Fraction const &frac2){//overload >
    int num1, num2;
    num1 = frac1.numerator() * frac2.denominator();
    num2 = frac2.numerator() * frac1.denominator();
    return(num1 > num2);
}


bool operator<(Fraction const &frac1, Fraction const &frac2){//overload < 
    int num1, num2;
    num1 = frac1.num * frac2.den;
    num2 = frac2.num * frac1.den;
    return(num1 < num2);
}

bool operator==(Fraction const &frac1, Fraction const &frac2){//overload ==
    int num1, num2;
    num1 = frac1.num * frac2.den;
    num2 = frac2.num * frac1.den;
    return(num1 == num2);
}

bool operator!=(Fraction const &frac1, Fraction const &frac2){//overload !=
    int num1, num2;
    num1 = frac1.num * frac2.den;
    num2 = frac2.num * frac1.den;
    return(num1 != num2);
}

bool operator>=(Fraction const &frac1, Fraction const &frac2){//overload !=
    int num1, num2;
    num1 = frac1.num * frac2.den;
    num2 = frac2.num * frac1.den;
    return(num1 >= num2);
}

bool operator<=(Fraction const &frac1, Fraction const &frac2){//overload !=
    int num1, num2;
    num1 = frac1.num * frac2.den;
    num2 = frac2.num * frac1.den;
    return(num1 <= num2);
}

Fraction operator+=(Fraction& lhs,const Fraction& rhs){
    lhs =  lhs + rhs;
    return lhs;
}

Fraction Fraction::operator-(){
    return Fraction(-num, den);
}

Fraction Fraction::operator++(int val){
    Fraction frac(num, den);
    num += den;
    return frac;
}

Fraction& Fraction::operator++(){
    num += den;
    return *this;
}


