#include <iostream> //pre-processir directive
#include "GenStack.h"
using namespace std;

class RPNCalc
{

public:
    RPNCalc();  //default constructor
    ~RPNCalc(); //destructor
    float getNum(char input);
    int isOperator(char input);
    int isOperand(char input);
    float operation(int a, int b, char op);
    float finalEval(string input);
    void romanianProjectileGun();
    void onStack(string input);
    void reverseStack();

private:
    GenStack<float> *rpnStack;
    GenStack<float> *reverse;
};
