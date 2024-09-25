 #ifndef Lexer_Token
#define Lexer_Token
#include <string>

#include "TokenType.hpp"
using namespace std;
namespace ClownScript
{
    namespace Lexer
    {
        class Token
        {
            public:TokenType Type;
            public:int LineNumber;
            public:int ColumnNumber;
            public:string Value;
            public: string ToType()const
            {
            
                switch (Type) {
                case Keyword:        return "keyword";
                case Identifier:     return "identifier";
                case StringLiteral:  return "stringliteral";
                case Operator:       return "operator";
                case Symbol:         return "symbol";
                case Whitespace:     return "whitespace";
                case Arrow:          return "arrow";
                default: Unknown:    return "unknown";
                }
            }

            public:Token(TokenType type, string value) {
                Type = type;
                Value = value;
            }

            public: string ToString()const {
             return  ToType() + Value;//$"{ToType()}: {Value}";
            }
            public:Token()
            {
                
            }
            ~Token() 
            {
            // Cleanup code if necessary
            }
        };
    }
}
#endif // Lexer_Token