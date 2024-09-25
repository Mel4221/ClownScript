#ifndef Lexer_Tokenizer
#define Lexer_Tokenizer
#include <vector>
#include <string>
#include "Token.hpp"
using namespace std;
namespace ClownScript
{
    namespace Lexer
    {
        class Tokenizer
        {
            private:string Input; // Reference to a string
            private:int Position;
            private:vector<Token> Tokens; 
            public: vector<Token> Tokenize();
            public: vector<Token> Tokenize(string input);

            public: Tokenizer();
            public: Tokenizer(string input);
            public: ~Tokenizer();
        };
    }
}
#endif // Lexer_Tokenizer