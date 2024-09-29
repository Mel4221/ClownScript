#ifndef Lexer_Token
#define Lexer_Token
#include <string>
#include "TokenType.hpp"
#include "Is.hpp"
using namespace std;
namespace ClownScript
{
    namespace Lexer
    {
        class Token
        {
            public:TokenType Type;
            public:int Line;
            public:int Column;
            public:string Value;
            public: static TokenType ParseToType(const std::string& value) 
            {

            /*
            if(Is::ValidKeyword(value)){
                return TokenType::Keyword; 
            }
            */

            // Check for known keywords and assign corresponding TokenType
            if (value == "using") {
                return TokenType::Using;
            } 

            if (value == "namespace") {
                return TokenType::Namespace;
            } 

            if (value == "include") {
                return TokenType::Include;
            } 

            if (value == "return") {
                return TokenType::Return;
            } 

            if (value == "if") {
                return TokenType::Conditional;
            } 

            if (value == "try") {
                return TokenType::Try;
            } 

            if (value == "catch") {
                return TokenType::Catch;
            } 
            
            if (value == "async") {
                return TokenType::Async;
            } 

            if (value == "function") {
                return TokenType::Function;
            }

            if (value == "for") {
                return TokenType::For;
            }

            if (value == "foreach") {
                return TokenType::ForEach;
            }

            // If none of the above, return Unknown
            return TokenType::Unknown;

            }


       public:
    std::string ToType() const
    {
        switch (Type) {
            case Identifier:    return "identifier";
            case StringLiteral: return "stringliteral";
            case Operator:      return "operator";
            case Symbol:        return "symbol";
            case Whitespace:    return "whitespace";
            case Arrow:         return "arrow";
            case Function:      return "function";
            case Namespace:     return "namespace";
            case Using:         return "using";
            case Include:       return "include";
            case Assignment:    return "assignment";
            case Conditional:   return "conditional";
            case Try:          return "try";
            case Catch:         return "catch";
            case Return:        return "return";
            case Async:         return "async";
            case Comment:       return "comment";
            case Parameter:     return "parameter";
            case Call:          return "call";
            case Path:          return "path";
            case Generic:       return "generic";
            case Object:        return "object";
            case Property:      return "property";
            case Array:         return "array";
            case For:           return "for";
            case ForEach:       return "foreach";
            case Int:           return "int";
            case Double:        return "double";
            case Float:         return "float";
            case Long:          return "long";
            case Char:          return "char";
            case Byte:          return "byte"; 
            case Unknown:       return "unknown"; // Fallthrough case for unknown token
            default:           return "unknown";   // Default case for any unhandled tokens
        }
    }


            public:Token(TokenType type, string value) {
                Type = type;
                Value = value;
            }

            public: string ToString()const {
             return  ToType() +" : "+ Value +" -> Line: "+to_string(Line+1) +" Column: "+to_string(Column+1);//$"{ToType()}: {Value}";
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