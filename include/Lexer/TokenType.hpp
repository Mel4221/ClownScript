#ifndef Lexer_TokenTypes
#define Lexer_TokenTypes
namespace ClownScript
{
    namespace Lexer
    {
        enum TokenType
        {
            Identifier,
            StringLiteral,
            Operator,
            Symbol,
            Whitespace,
            Arrow,
            Function,      // For function declarations
            Namespace,     // For the namespace keyword
            Using,         // For the using keyword
            Include,       // For the include keyword
            Assignment,    // For assignments
            Conditional,   // For conditional statements (if)
            Try,           // For try keyword
            Catch,         // For catch keyword
            Return,        // For return statements
            Async,         // For async keyword
            Comment,   // For comments
            Parameter,     // For parameters in function definitions
            Call,          // For function calls
            Path,// For paths in includes
            Object,
            Property,
            Generic,
            Array,
            For,
            ForEach,
            Unknown
            
        };
    
    }
}
#endif // Lexer_TokenTypes
