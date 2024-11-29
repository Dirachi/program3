/*
    File: driver.cpp
    Author: Tobin McGee
    Purpose: Read the pokemon data from text document.
        Store it in a binary tree. Then print the data.
*/
#include <iostream>
#include <fstream>
#include "Pokemon.h"
#include "BinaryTree.h"
using namespace std;
string filename;
string tempName;
string tempStr;
int tempIndex;
int numAdded;
BinaryTree<pokemon> pokeDex;
pokemon tempMon;


int main(){
    ifstream is;
    //open the file, close the program if it fails
    is.open("pokedex.txt");
    if(!is){
        cout << "\nerror opening file";
        cin.get();
        return 0;
    }
    //while loop that pulls in pokemon, grabs the index using a delimiter, if it exists proceed
    while(getline(is, tempStr, '#')){
        tempIndex = stoi(tempStr);// convert the string to an int
        getline(is, tempName, '#');// pull in the pokemon's name
        tempMon = pokemon(tempIndex, tempName);// create the temp pokemon
        if(pokeDex.searchNode(tempMon)){
            //if duplicate found, display message
            cout << "\nOops!  The Pokemon with index " << tempStr << " is already in the Pokedex.";
        }
        else{
            //if there is no dupe, add it to the tree
            pokeDex.insertNode(tempMon);
            numAdded++;// increment numadded
            cout << "\nInserting Pokemon with index " << tempIndex << " into the Pokedex.";
        }
        
    }
    //report number added
    cout << endl << endl << numAdded << " Pokemon have been added to the Pokedex!";

    //print tree
    cout << "\n\n********************POKEDEX:********************\n";
    pokeDex.displayInOrder();
    return 0;
}
