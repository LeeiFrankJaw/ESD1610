#include "hw_hdr.hpp"
#include "mystring.hpp"
#include <string>

int countLetter(const string &str, char ch)
{
    int sum = 0, i = -1;
    while ((i = str.find(ch, i+1)) != (int) string::npos)
	sum++;
    return sum;
}

void swapCharArr(const char *&s1, const char *&s2)
{
    const char *p;
    p = s1;
    s1 = s2;
    s2 = p;
}
