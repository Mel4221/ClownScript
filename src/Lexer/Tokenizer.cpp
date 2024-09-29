#include "../../include/Lexer/Tokenizer.hpp"
#include <iostream>
#include <string>

using namespace std; 
namespace ClownScript
{
    namespace Lexer
    {
        // Default constructor
        Tokenizer::Tokenizer() : Input(""), Column(0), Tokens(),Line(0),Current(' '){ 
            // Optionally initialize Input to an empty string
        }

        // Constructor with input
        Tokenizer::Tokenizer(string input) : Input(input), Column(0), Tokens(),Line(0),Current(' ') {  
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
        Token Tokenizer::HandleStringLiteral()
        {
            Token token;
            bool isPair = false; 
            int start = Column;
            int line = Line; 
            while(Column < Input.length())
            {
                Current = Input[Column];
                if(Column+1 < Input.length())
                {
                    if(Current == '"' && 
                    Input[Column+1] == '\n' &&
                    Input[Column-1] != '\\'
                    )
                    {
                        break;
                    }
                }

                Column++;
            }
            token.Type = TokenType::StringLiteral;
            token.Value = Input.substr(start,Column);
            token.Column = start; 
            token.Line = line; 
            return token; 
        }

        /* 
            sort of tryes to ignored single line  comments
        */
        void Tokenizer::HandleSingleLineComments()
        {
            while(Column < Input.length())
            {
                Current = Input[Column]; 
                if(Current == '\n')
                {
                    break;
                }
                Column++; 
            }

        }
        /* 
            sort of tryes to ignored single 
            multy lines comments
        */
        void Tokenizer::HandleComments()
        {
            bool isSingleLine = false; 
            int start = Column; 
            while(Column < Input.length())
            {   
                Current = Input[Column]; 
                if(Column+1 < Input.length())
                {   

                    if(Current == '/' && Input[Column+1] == '/')
                    {
                        isSingleLine = true; 
                    }   
                    if(isSingleLine && Current == '\n')
                    {
                        cout << "Comment..: \n"<<Input.substr(start,Column) <<endl; 
                        exit(0);
                        break;
                    }
                    if(Current == '*' && Input[Column+1] == '/')
                    {
                        break;
                    }
                    if(Current == '/' && !Input[Column+1] == '*' )
                    {
                        break;
                    }
                }
                //cout << "Comment..: \n"<<Input.substr(start,Column) <<endl; 
                Column++;
            }
        }
        /*
            Handles the keywords or identifier
        */
        Token Tokenizer::HandleKeywordOrIdentyfier()
        {
            Token token; 
            int start = Column;

            while(Column < Input.length() && 
                isalpha(Input[Column])||
                Input[Column] == '_'
                ){
                
                    //cout << "HandleKeywordOrIdentyfier..: " << Current << endl;
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
                       // Tokens.push_back(HandleKeywordOrIdentyfier());
                    }if(!isalpha(Current) && Current == '/')
                    {
                    
                        if(Column+1 < Input.length())
                        {
                            HandleComments();
                        }
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
