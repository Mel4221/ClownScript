#include "../../include/Lexer/Is.hpp"

// Define and initialize the static member here
const unordered_set<string> ClownScript::Lexer::Is::Keywords = 
{
    "include", "if", "for", "while", "break", "return",
    "int", "float", "double", "long","byte","string", "void", "object",
    "try", "catch", "true", "false", "async", "const", "var",
    "using", "namespace", "function", "identifier", "operator",
    "symbol", "whitespace", "arrow", "assignment", "conditional",
    "comment", "parameter", "call", "path", "generic", "array",
    "foreach"
};
