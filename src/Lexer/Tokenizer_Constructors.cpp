#include "../../include/Lexer/Tokenizer.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ClownScript::Lexer;
// Default constructor
Tokenizer::Tokenizer() : Input(""), Column(0), Tokens(),Line(0),Current(' '),PrintComments(false)
{ 
    // Optionally initialize Input to an empty string
}

// Constructor with input
Tokenizer::Tokenizer(string input) : Input(input), Column(0), Tokens(),Line(0),Current(' '),PrintComments(false)
{  

}     


// Destructor
Tokenizer::~Tokenizer() {
    // Clean up if needed, but avoid deleting Input since it's a reference
    // No need to delete since Input is not dynamically allocated
    // delete Tokens;
}