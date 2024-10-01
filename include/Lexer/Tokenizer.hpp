#ifndef Lexer_Tokenizer
#define Lexer_Tokenizer
#include <vector>
#include <string>
#include "Token.hpp"
#include "../QuickTools/Console/Console.hpp"


//#include "Is.hpp"
//#include "Convert.hpp"


using namespace std;
namespace ClownScript
{
    namespace Lexer
    {
        class Tokenizer
        {
            private:string Input; // Reference to a string
            private:char Current; 
            private:int Column;
            private:int Line;
            private:vector<Token> Tokens; 
            public: vector<Token> Tokenize();
            public: bool PrintComments;
            public: vector<Token> Tokenize(string input);
            public: void HandlePragma();
            public: void HandleComments();
            public: Token HandleStringLiteral(); 
            public: Token HandleKeywordOrIdentyfier();
            public: Tokenizer();
            public: Tokenizer(string input);
            public: ~Tokenizer();
        };
    }
}
#endif // Lexer_Tokenizer