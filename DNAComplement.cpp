/**
 * DNAComplement class creates the complement and reverse complement
 * 
 * @author Ori Garibi
 * @version 1.0
 * @see DNAComplement.cpp
 * 
 */
#include "DNAComplement.h"
#include "FileProcessor.h"

DNAComplement::DNAComplement()
{
    //default constructor body, it's empty
}
DNAComplement::~DNAComplement()
{
    //default destructor
}
string DNAComplement::getComplement(string dna){ //this method creates the complement of the dna sequence; parameter is the dna sequence
    compStack = new GenStack<char>(20); //initialize the stack
    string complement;
    complement = "Complement:\n";
    for(int i = 0; i<dna.length(); ++i){ //changes the letters in the sequence to their complements and pushes to the stack
        if(dna[i] == 'A'){
            complement +='T';
            compStack->push('T');
        }
        else if(dna[i] == 'T'){
            complement += 'A';
            compStack->push('A');
        }
        else if(dna[i] == 'C'){
            complement += 'G';
            compStack->push('G');
        }
        else if(dna[i] == 'G'){
            complement += 'C';
            compStack->push('C');
        }
    }
    string cc = getReverseComplement(complement); //calls the reverse complement method
    complement+="\n";
    complement += "Reverse Complement:\n";
    complement+= cc;
    return complement; //returns complement
    delete compStack;//delete stack
}


string DNAComplement::getReverseComplement(string complement){ //this method makes the reverse complement; parameter is the complement
    string reverse;
    while(!compStack->isEmpty()){ //here i pop the stack onto a string to reverse it
        reverse+=compStack->pop();
    }
    return reverse; //returns reverse complement
}