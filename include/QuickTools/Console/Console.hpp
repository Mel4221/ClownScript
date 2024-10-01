#ifndef Console_Clear
#define Console_Clear
#include <string>
using namespace std;
namespace QuickTools
{
    class Console
    {
        public: static void Clear();
        public: static void Print(const string, const string strColor) ;
        public: static void SetColor(const string) ;
        public: static void Wait();
        public: static void Wait(const string); 

    };
}
#endif // Console_Clear