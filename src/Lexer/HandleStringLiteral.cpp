#include "../../include/Lexer/Tokenizer.hpp"
#include <stdexcept> // For std::runtime_error
#include <iostream>
#include <string>

using namespace std;
using namespace QuickTools; 
using namespace ClownScript::Lexer;

Token Tokenizer::HandleStringLiteral()
{
    Token token;
    bool isPair = false; 
    int start = Column;
    int line = Line; 
    Current = Input[Column]; // Initialize Current

    // Move past the initial opening quote
    Column++;

    while (Column < Input.length())
    {
        Current = Input[Column];

        // Check for the closing quote
        /*Column == 0 ||*/
        if (Current == '"' && (Input[Column - 1] != '\\')) 
        {
            // Found the closing quote
            Column++; // Move past the closing quote
            isPair = true; // Indicate that we found a complete string
            break;
        }

        // Check for newline
        /*
        if (Current == '\n') 
        {
            // Handle error for unclosed string literals if desired
            break;
        }
        */
        Column++;
    }
    Console::Wait(Input.substr(start, Column - start));
    if (!isPair) {
        string error = "Line: " + to_string(line) +" "+Input.substr(0,line);
        throw runtime_error("Not closing string literal..: "+error);
        /*
        // Handle unclosed string literal error here (optional)
        token.Type = TokenType::Error; // Example: set to error type
        token.Value = "Unclosed string literal"; // Example message
        token.Line = line;
        token.Column = start; // Set to starting column
        */
        return token;
    }

    token.Type = TokenType::StringLiteral;
    token.Value = Input.substr(start, Column - start); // Correctly calculate length
    token.Column = start; 
    token.Line = line; 

    return token; 
}