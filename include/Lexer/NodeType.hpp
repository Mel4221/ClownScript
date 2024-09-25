#ifndef Lexer_NodeTypes
#define Lexer_NodeTypes
namespace ClownScript
{
    namespace Lexer
    {
        enum NodeType
        {
            Function,
            Parameter,
            Return, 
            Call,
            Condition
        };
    }
}
#endif // Lexer_NodeTypes