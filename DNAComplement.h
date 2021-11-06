#include <iostream> 
#include "GenStack.h"
using namespace std;

class DNAComplement
{

public:
    DNAComplement(); //default constructor
    ~DNAComplement(); //destructor
    string getComplement(string input);
    string getReverseComplement(string input);
private:
    GenStack<char> *compStack;
};