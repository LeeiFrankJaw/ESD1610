#include <string>
#include "hw_hdr.hpp"

int countLetter(const string& str, char ch)
{
    int sum = 0, i = -1;
    while ((i = str.find(ch, i+1)) != (int) string::npos)
	sum++;
    return sum;
}
