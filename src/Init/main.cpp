#ifndef ClownScript_Main
#define ClownScript_Main

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
//#include "../../include/Lexer/Token.hpp"
#include "../../include/Lexer/Tokenizer.hpp"
using namespace ClownScript::Lexer;
using namespace std; 

string ReadAllText(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        throw runtime_error("Error opening file: " + filename);
    }
    ostringstream buffer;
    buffer << inputFile.rdbuf(); // Read the file into the buffer
     
    return buffer.str();// Return the contents as a string reference
}

int main(int argc ,char** argv)
{

    
    string code = ReadAllText("../Docs/update.clown");
    cout << code << endl;
    Tokenizer token(code);
    vector<Token> tokens =  token.Tokenize();
    for(int v = 0; v < tokens.size(); v++)
    {
       //cout << tokens[v].ToString() << endl; 
    }
    cout <<"Tokens..: "<< tokens.size()<< endl;
    //cout << "working" << endl; 
    /*
    //List(argc,argv);
    string colors[] = {"Blue","Green","Cyan","Yellow"}; 
    List(colors); 
    */
    return 0;
}

#endif // ClownScript_Main