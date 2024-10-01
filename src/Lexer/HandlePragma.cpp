#include "../../include/Lexer/Tokenizer.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace QuickTools;
using namespace ClownScript::Lexer;

void Tokenizer::HandlePragma()
{
    bool isSingleLine = false; 
   
    int start = Column;

    while (Column < Input.length())
    {   
        Current = Input[Column]; 
        
        // Check for the start of a single-line comment
        if (Current == '#' && Column + 1 < Input.length())
        {
            isSingleLine = true;
            Column += 2; // Move past the '//'
            start = Column; // Update start to skip comment
            while (Column < Input.length() && Input[Column] != '\n')
            {
                Column++; // Skip until end of line
            }

                std::ostringstream oss;
                oss << "pragma: " << Input.substr(start, Column - start) << std::endl;
               
                Console::Print(oss.str(),"pink");
                //Console::Print("","green");//just on my ter
            break; // Exit after handling single-line comment
        }

        Column++;
    }
}