#ifndef Lexer_Token
#define Lexer_Token
#include <string>
#include <sstream> // For std::ostringstream
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
            public: 
static TokenType ParseToType(const std::string& value) 
{        
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
    if (value == "int") {
        return TokenType::Int;
    }
    if (value == "double") {
        return TokenType::Double;
    }
    if (value == "float") {
        return TokenType::Float;
    }
    if (value == "long") {
        return TokenType::Long;
    }
    if (value == "char") {
        return TokenType::Char;
    }
    if (value == "byte") {
        return TokenType::Byte;
    }
    if (value == "string") {
        return TokenType::String;
    }
    // Add more types as necessary
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
            case String:        return "string";
            default:           return "unknown";   // Default case for any unhandled tokens
        }
    }


            public:Token(TokenType type, string value) 
            {
                Type = type;
                Value = value;
            }

           public:
    std::string ToString() const {
        std::ostringstream oss; // Create a string stream
        oss << "Token:" << std::endl
            << "{" << std::endl 
            << "Type: " << ToType() << std::endl
            << "Value: " << Value << std::endl
            << "Line: " << (Line + 1) << std::endl
            << "Column: " << (Column + 1) << std::endl
            << "}" << std::endl;
        return oss.str(); // Return the string representation
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