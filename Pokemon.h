/*
    File: Pokemon.h
    Author: Tobin McGee
    Date: 11/29/2024
    Purpose: Binary Tree class template
*/
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef POKEMON_H
#define POKEMON_H

class pokemon{
    private:
        int index;
        string name;
    public:
    
        //constuctors
        pokemon(){
            index = 0;
            name = "None";
        };
        pokemon(int inIndex, string inName){
            index = inIndex;
            name = inName;
        };

        //setters
        void setID(int inID){
            index = inID;
        };
        void setName(string inName){
            name = inName;
        };
        //getters
        int getID() const {
            return index;
        };
        string getName() const {
            return name;
        };

        //overloaded operators
        bool operator<(const pokemon& temp) const { 
            if(this->index < temp.index){
                return true;
            };
            return false;
        }
        bool operator==(const pokemon& temp) const { 
            if(this->index == temp.index){
                return true;
            };
            return false;
        }
        friend ostream & operator << (ostream & os, const pokemon temp){
            os << "Pokemon Index Number: " << left << setfill(' ') << setw(10)  << temp.index ;
            os << "Name: " << temp.name;
            return os;
        };
};

#endif