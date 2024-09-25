#ifndef Lexer_Is
#define Lexer_Is
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm> // For std::transform
using namespace std;

namespace ClownScript
{
    namespace Lexer
    {
        class Is
        {
        public:
            static const unordered_set<string> Keywords; // Declare without initialization


        private: static bool Exist(const string& input)
        {
            for (const auto& keyword : Keywords) 
            {
                //cout << keyword << " == " << input << endl; 
                if (keyword == input) {
                    return true; // Found a valid keyword
                }
            }
            return false; 
        }
        public:
            static bool ValidKeyword(const string& input)
            {
                //string upperInput = input;
                bool isValid = false; 
                //transform(upperInput.begin(), upperInput.end(), upperInput.begin(), ::toupper);
                isValid = Exist(input);

                //cout << "ToUpper: " << upperInput << endl;
                //string valid = isValid == true?"TRUE":"FALSE";
              
                //cout << input <<" -> "<< valid << endl; 
                return isValid;
            }
              
        };
    }
}

#endif // Lexer_Is
