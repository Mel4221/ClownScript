#include "../../include/Lexer/Is.hpp"

// Define and initialize the static member here
const unordered_set<string> ClownScript::Lexer::Is::Keywords = 
{
    "include", "if", "for", "while", "break", "return",
    "int", "float", "double", "long", "void", "object",
    "try", "catch", "true", "false", "async","const","var"
};
