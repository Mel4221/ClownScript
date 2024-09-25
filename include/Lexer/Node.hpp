#ifndef Lexer_Node
#define Lexer_Node
namespace ClownScript
{
    namespace Lexer
    {
        class Node
        {
            public:int LineNumber; // To track the line number in the source code
            public:int ColumnNumber; // To track the column number in the source code
            public:Node Parent; // To reference the parent node in the tree
            public:NodeTypes Type;
            public:Node()
            {
                
            }
            ~Node() 
            {
            // Cleanup code if necessary
            }
        };
    }
}
#endif // Lexer_Node