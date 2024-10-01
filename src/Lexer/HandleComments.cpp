#include "../../include/Lexer/Tokenizer.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ClownScript::Lexer;

/* 
    sort of tryes to ignored single 
    multy lines comments
*/
void Tokenizer::HandleComments()
{
    bool isSingleLine = false; 
    bool isMultiLine = false;
    int start = Column;

    while (Column < Input.length())
    {   
        Current = Input[Column]; 
        
        // Check for the start of a single-line comment
        if (Current == '/' && Column + 1 < Input.length() && Input[Column + 1] == '/')
        {
            isSingleLine = true;
            Column += 2; // Move past the '//'
            start = Column; // Update start to skip comment
            while (Column < Input.length() && Input[Column] != '\n')
            {
                Column++; // Skip until end of line
            }
            if(PrintComments)
            {
                cout << "Single Line Comment:"<<
                endl<<"{"<<endl<<
                Input.substr(start, Column - start)<<
                endl << "}"<<endl;
            }
            break; // Exit after handling single-line comment
        }

        // Check for the start of a multi-line comment
        if (Current == '/' && Column + 1 < Input.length() && Input[Column + 1] == '*')
        {
            isMultiLine = true;
            Column += 2; // Move past the '/*'
            start = Column; // Update start to skip comment
            while (Column < Input.length())
            {
                if (Current == '*' && Column + 1 < Input.length() && Input[Column + 1] == '/')
                {
                    Column += 2; // Move past the '*/'
                    if(PrintComments)
                    {
                        cout << "Multi Line Comment:"<<
                        endl<<"{"<<endl<<
                        Input.substr(start, Column - start - 2) <<
                        endl <<"}"<< endl; // Exclude '*/'
                    }
                    break; // Exit after handling multi-line comment
                }
                Column++; // Continue scanning
                Current = Input[Column]; // Update Current
            }
            break; // Exit after handling multi-line comment
        }
        Column++;
    }
}