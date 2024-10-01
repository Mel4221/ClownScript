#include "../../include/Lexer/Tokenizer.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace ClownScript::Lexer;
/*
    This method is the tokinizer which would
    return all the tokens created, to find
    all the types of tokens created visist the
    /include/Lexer/TokenType.hpp
*/
vector<Token> Tokenizer::Tokenize() 
{
    while(Column < Input.length())
    {
            Current = Input[Column]; 
            if(!isalpha(Current) && Current == '"' )
            {
                Tokens.push_back(HandleStringLiteral());
            }
            //cout << "Tokenize..: " << Current << endl;
            if(Current == '\n')
            {
                Line++; 
            }if (isalpha(Current) || Current == '_') 
            {
                Tokens.push_back(HandleKeywordOrIdentyfier());
            }if(!isalpha(Current) && Current == '/')
            {
            
                if(Column+1 < Input.length())
                {
                    HandleComments();
                }
            }if(!isalpha(Current) && Current == '#')
            {
                HandlePragma();
            }
            Column++;
    }
    

    
    // Implement tokenization logic here
    return Tokens; // Currently returns empty Tokens
}

// Tokenize method with input
vector<Token> Tokenizer::Tokenize(string input) {
    Input = input; // Set the current input
    Column = 0;  // Reset the Column for new tokenization
    return Tokenize(); // Call the no-argument Tokenize
}
