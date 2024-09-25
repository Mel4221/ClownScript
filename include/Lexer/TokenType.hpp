#ifndef Lexer_TokenTypes
#define Lexer_TokenTypes
namespace ClownScript
{
    namespace Lexer
    {
        enum TokenType
        {
            Keyword,
            Identifier,
            StringLiteral,
            Operator,
            Symbol,
            Whitespace,
            Arrow,
            Unknown
        };
    }
}
#endif // Lexer_TokenTypes
