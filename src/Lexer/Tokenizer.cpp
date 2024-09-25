#include "../../include/Lexer/Tokenizer.hpp"
#include <iostream>

namespace ClownScript
{
    namespace Lexer
    {
        // Default constructor
        Tokenizer::Tokenizer() : Input(""), Position(0), Tokens() { 
            // Optionally initialize Input to an empty string
        }

        // Constructor with input
        Tokenizer::Tokenizer(string input) : Input(input), Position(0), Tokens() {  
        }

        // Destructor
        Tokenizer::~Tokenizer() {
            // Clean up if needed, but avoid deleting Input since it's a reference
            // No need to delete since Input is not dynamically allocated
           // delete Tokens;
        }
        Token Tokenizer::HandleKeywordOrIdentyfier()
        {
            Token token();


            return token; 
        }
        // Tokenize method without input
        vector<Token> Tokenizer::Tokenize() 
        {
            while(Position < Input.length)
            {

                    if (std::isalpha(current) || current == '_') 
                    {
                        Tokens.push_back(HandleKeywordOrIdentyfier());
                    }

                    Position++;
            }
            


            // Implement tokenization logic here
            return Tokens; // Currently returns empty Tokens
        }

        // Tokenize method with input
        vector<Token> Tokenizer::Tokenize(string input) {
            Input = input; // Set the current input
            Position = 0;  // Reset position for new tokenization
            return Tokenize(); // Call the no-argument Tokenize
        }
    }
}
