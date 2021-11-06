#include <iostream> 

using namespace std;

class FileProcessor
{

public:
    FileProcessor(); //default constructor
    ~FileProcessor(); //destructor
    void processFile(string input, string output);
    void runProgram(string input);
};