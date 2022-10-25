//Aaron Moise 19ajgm
#include <iostream>
using namespace std;
#pragma once

class Fraction{

private:
    int num, den; 
    int findGCD(int num1, int num2);
//find the greatest common divisor of two numbers
public:

    //getters
    int numerator() const; 
    int denominator() const;

    Fraction(); //default constructor creates 0/1
    Fraction(int numerator); //constructor for one value
    Fraction(int numerator, int denominator); //constructor for numerator and denominator
    
    //unary operators
    Fraction operator-();//overload (negative sign)
    Fraction& operator++();//overload ++(post increment)
    Fraction operator++(int);//overload ++(pre increment)

    //binary operator
    friend bool operator>(Fraction const &obj1, Fraction const &obj2);//overload >
    friend bool operator<(Fraction const &obj1, Fraction const &obj2);//overload <
    friend bool operator==(Fraction const &obj1, Fraction const &obj2);//overload ==
    friend bool operator!=(Fraction const &obj1, Fraction const &obj2);//overload !=
    friend bool operator>=(Fraction const &frac1, Fraction const &frac2);//overloard >=
    friend bool operator<=(Fraction const &frac1, Fraction const &frac2);//overloard <=
    friend ostream& operator<<(ostream& out, const Fraction &frac);//overlord outpt
    friend istream& operator>>(istream& in, Fraction &frac); //overload input
    
};
//non member overloading so int will work on left hand side
Fraction operator+(Fraction const &lhs, Fraction const &rhs);//overload +
Fraction operator-(Fraction const &lhs, Fraction const &rhs);//overload -
Fraction operator*(Fraction const &lhs, Fraction const &rhs);//overload *
Fraction operator/(Fraction const &lhs, Fraction const &rhs);//overload /
Fraction operator+=(const Fraction& lhs,const Fraction& rhs);//overload +=

class FractionException{
public:
    FractionException(const string& message);
    //constructor for FractionException
    string what();
    //returns error mesage
private:
    string message;
    //error message
};
