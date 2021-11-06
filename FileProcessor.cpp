/**
 * FileProcessor class determines what the user wants to run then writes to file for DNA
 * 
 * @author Ori Garibi
 * @version 1.0
 * @see FileProcessor.cpp
 * 
 */
#include "FileProcessor.h"
#include "DNAComplement.h"
#include "RPNCalc.h"
#include <fstream>
#include <iostream>
using namespace std;

FileProcessor::FileProcessor()
{
    //default constructor body, it's empty
}
FileProcessor::~FileProcessor()
{
    //default destructor
}

void FileProcessor::processFile(string file, string output) //takes in a file from the command line and outputs a new file
{
    char data[500];

    // open and read the input file
    ifstream infile;
    infile.open(file);
    int count = 0;

    string sentence;
    string inputLine = "";

    while (getline(infile, sentence))
    {
        inputLine += sentence;
    }

    cout << "Reading from the file..." << endl;
    infile >> inputLine;

    DNAComplement *sp = new DNAComplement; //creates a pointer to the DNAComplement class
    string outputParagraph = sp->getComplement(inputLine); //points to the getComplement function

    //close the inputted file.
    infile.close();
    //open an output file
    ofstream outFile;
    outFile.open(output);

    cout << "Writing to the file:" << endl;

    //write inputted data into the file
    outFile << outputParagraph << endl;

    //close the output file
    outFile.close();
    //no return
    delete sp;
}

void FileProcessor::runProgram(string user){ //this method uses the user command line input and makes a decision
    if(user == "RPN"){ 
        string eqn;
        cout << "Enter equation in RPN" <<endl; //prompt user for the equation
        cin >> eqn;
        RPNCalc *hp = new RPNCalc;
        float num = hp->finalEval(eqn); //run the RPN
        delete hp;
    }
    else if(user == "DNA"){
        string file;
        cout<<"Enter your file: "<<endl; //prompt user for a file
        cin>>file;
        processFile(file,"dnaoutput.txt"); //run processFile where DNAComplement class is ran and writes to file
    }

}

