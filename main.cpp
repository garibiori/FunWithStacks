/**
 * main class is the main method
 * 
 * @author Ori Garibi
 * @version 1.0
 * @see main.cpp
 * 
 */
//main file, where are main method lives
#include <iostream> //pre-processir directive
using namespace std;
#include "RPNCalc.h"
#include "GenStack.h"
#include "DNAComplement.h"
#include "FileProcessor.h"
int main(int argc, char ** argv)
{

    FileProcessor *mp = new FileProcessor; //create pointer to FileProcessor
    mp->runProgram(argv[1]); //run runProgram with command line parameters


    delete mp; //delete pointer
    return 0;
}