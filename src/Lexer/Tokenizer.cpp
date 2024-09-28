#include "../../include/Lexer/Tokenizer.hpp"
#include <iostream>
#include <string>

using namespace std; 
namespace ClownScript
{
    namespace Lexer
    {
        // Default constructor
        Tokenizer::Tokenizer() : Input(""), Column(0), Tokens(),Line(0){ 
            // Optionally initialize Input to an empty string
        }

        // Constructor with input
        Tokenizer::Tokenizer(string input) : Input(input), Column(0), Tokens(),Line(0) {  
        }

        // Destructor
        Tokenizer::~Tokenizer() {
            // Clean up if needed, but avoid deleting Input since it's a reference
            // No need to delete since Input is not dynamically allocated
           // delete Tokens;
        }

        /* 
                int start = _position;
        while (_position < _input.Length && char.IsLetterOrDigit(_input[_position]) ||
                _input[_position] == '_' ) {
            _position++;
         //   if(_position == _input.Length)break;

        }
        string value = _input.Substring(start, _position - start);
        return new Token(TokenType.Identifier, value);
        */
    
        Token Tokenizer::HandleKeywordOrIdentyfier()
        {
            Token token; 
            int start = Column;
            while(Column < Input.length() && 
                isalpha(Input[Column])||
                Input[Column] == '_'
                ){
                   Column++;//Keep Moving Foward
                } 
                string value = Input.substr(start,Column - start);

                token.Type = Token::ParseToType(value); 
                token.Line = Line;
                token.Column = Column;
                token.Value = value;  
                return token; 
            
            //token.Type = TokenType.Identifier;
            return  Token(); 
        }

        // Tokenize method without input
        vector<Token> Tokenizer::Tokenize() 
        {
            while(Column < Input.length())
            {
                    char current = Input[Column]; 
                    if(current == '\n')
                    {
                        Line++; 
                    }
                    if (isalpha(current) || current == '_') 
                    {
                        Tokens.push_back(HandleKeywordOrIdentyfier());
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
    }
}
