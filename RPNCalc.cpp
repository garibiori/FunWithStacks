/**
 * RPNCalc class makes calculations in RPN
 * 
 * @author Ori Garibi
 * @version 1.0
 * @see RPNCalc.cpp
 * 
 */
#include "RPNCalc.h"
#include "FileProcessor.h"
RPNCalc::RPNCalc()
{
    
    //default constructor body, it's empty
}

RPNCalc::~RPNCalc()
{

    //default destructor
}

float RPNCalc::getNum(char ch){ //gets number with individual characters as input
    int val;
    val = ch;
    return float(val-'0'); //changes character to float and returns
}

int RPNCalc::isOperator(char ch){ //determines if character is an operator; single char as input
    if(ch == '+' || ch == '-' ||ch == '*'||ch == '/'||ch == '^'){
        return 1; //is operator
    }
    return -1; //not operator
}
int RPNCalc::isOperand(char ch){ //chacks if is number by taking in characters and determining of they're between 0 and 9
    if(ch>='0' &&ch<='9'){
        return 1;//is number
    }
    return -1;//not number
}
float RPNCalc::operation(int a, int b, char op){ //takes in 2 numbers and operand and returns the operations
    if(op=='+'){
        return b+a;
    }
    else if(op=='-'){
        return b-a;
    }
    else if(op == '*'){
        return b*a;
    }
    else if(op == '/'){
        return b/a;
    }

}
float RPNCalc::finalEval(string final){ //takes in a string for the equation
    rpnStack = new GenStack<float>(20); //initialize stack(not reversed)
    onStack(final); //puts all values on stack
    int a,b;
    for(int i= 0; i<final.length();++i){ //for each value save as int and pop twice if isOperator
        if(isOperator(final[i])!= -1){
            a = reverse->peek();
            reverse->pop();
            b = reverse->peek();
            reverse->pop();
            reverse->push(operation(a,b,final[i])); //push to stack with the operation done
        }
        else if(isOperand(final[i])>0){ //if number push to stack
            reverse->push(getNum(final[i]));
        }
    }
    romanianProjectileGun();
    cout<<reverse->peek()<<endl;
    return reverse->peek(); //return the last in value
    delete rpnStack;//delete stacks
    delete reverse;
}
void RPNCalc::onStack(string file){ //this method pushes the string onto a stack
    for(int i = 0; i<file.length();++i){
        rpnStack->push(file[i]);
    }
    reverseStack(); //reverse the stack
}
void RPNCalc::reverseStack(){ //this method reverses the stack
    reverse = new GenStack<float>(20); //initialize reverse stack
    while(!rpnStack->isEmpty()){ //push from one stack to another to reverse
        reverse->push(rpnStack->pop());
    }
}
void RPNCalc::romanianProjectileGun(){
    cout<<"romanian projectile gun"<<endl;
}