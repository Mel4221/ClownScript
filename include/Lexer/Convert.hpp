#include <string>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>
using namespace std;

namespace ClownScript
{
    namespace Lexer
    {
        class Convert
        {
             public: Keyword ToKeyWord(const std::string& str) {
                static const std::unordered_map<std::string, Keyword> stringToTypeMap = {
                    { "INCLUDE", Keyword::INCLUDE },
                    { "IF", Keyword::IF },
                    { "FOR", Keyword::FOR },
                    { "WHILE", Keyword::WHILE },
                    { "BREAK", Keyword::BREAK },
                    { "RETURN", Keyword::RETURN },
                    { "INT", Keyword::INT },
                    { "FLOAT", Keyword::FLOAT },
                    { "DOUBLE", Keyword::DOUBLE },
                    { "LONG", Keyword::LONG },
                    { "VOID", Keyword::VOID },
                    { "OBJECT", Keyword::OBJECT },
                    { "TRY", Keyword::TRY },
                    { "CATCH", Keyword::CATCH },
                    { "TRUE", Keyword::TRUE },
                    { "FALSE", Keyword::FALSE },
                    { "ASYNC", Keyword::ASYNC }
                };

                std::string upperStr = str; // Make a copy of the input string
                std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper); // Convert to uppercase

                auto it = stringToTypeMap.find(upperStr); // Search in the map
                if (it != stringToTypeMap.end()) {
                    return it->second; // Return the corresponding enum value
                }

                throw std::invalid_argument("Invalid type string: " + str); // Exception if not found
            }

        }
   
    }
}