#include "../../include/Lexer/Tokenizer.hpp"
#include "../../include/QuickTools/Console/Console.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace QuickTools; 
using namespace ClownScript::Lexer;
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
        
        /*
        Console::Clear();
        for(int item =0; item < Tokens.size(); item++)
        {
            cout << Tokens[item].ToString() << endl;
        }
        */

        //cout <<"Token..:"<<endl<<token.ToString();
        //char key = getchar(); // Waits for user input    

        return token; 
    
    //token.Type = TokenType.Identifier;
    return  Token(); 
}
