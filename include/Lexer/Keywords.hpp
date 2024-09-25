#ifndef Lexer_Keyword
#define Lexer_Keyword
namespace ClownScript
{
    namespace Lexer
    { 
        enum class Keyword{
            INCLUDE,
            IF,
            FOR,
            WHILE,
            BREAK,
            RETURN,
            INT,
            FLOAT,
            DOUBLE,
            LONG,
            VOID,
            OBJECT,
            TRY,
            CATCH,
            TRUE,
            FALSE,
            ASYNC,
            VAR,
            CONST
        };

    }
}
#endif // Lexer_Keyword