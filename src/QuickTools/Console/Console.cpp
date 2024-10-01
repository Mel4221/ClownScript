#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "../../../include/QuickTools/Console/Console.hpp"
using namespace QuickTools;
void Console::Clear()
{
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux/Unix
    #endif
}

void Console::SetColor(const string color) {
    static std::map<std::string, std::string> colorMap = {
        {"pink", "\033[35m"},   // Magenta
        {"cyan", "\033[36m"},   // Cyan
        {"red", "\033[31m"},    // Red
        {"green", "\033[32m"},  // Green
        {"yellow", "\033[33m"}, // Yellow
        {"blue", "\033[34m"},   // Blue
        {"reset", "\033[0m"}    // Reset to default
    };

    if (colorMap.find(color) != colorMap.end()) {
        std::cout << colorMap[color];
    } else {
        std::cout << colorMap["reset"]; // Default to reset if color is not found
    }
}

void Console::Print(const string text, const string strColor) 
{
    std::stringstream ss(strColor);
    std::string color;
    bool first = true;

    // Split the color string by '||'
    while (std::getline(ss, color, '|'))
    {
        if (!first) {
            std::cout << " "; // Add space between colors
        }
        SetColor(color);
        first = false;
    }

    // Print the text
    std::cout << text << std::endl;

    // Reset color to default
    SetColor("reset");
}

void Console::Wait(const string text)
{
    cout << text << endl; 
    char key = getchar(); // Waits for user input  
}
void Console::Wait()
{
    Console::Wait("Press any key to continue...");
}


