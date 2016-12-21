#include "hw_hdr.hpp"
#include "mystring.hpp"

int main(int argc, char *argv[])
{
    const char *s1, *s2;
    string *str;

    if (argc > 1)
	s1 = argv[1];
    else {
	str = new string;
	getline(cin, *str);
	s1 = str->c_str();
    }
    if (argc > 2)
	s2 = argv[2];
    else {
	str = new string;
	getline(cin, *str);
	s2 = str->c_str();
    }

    swapCharArr(s1, s2);
    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}
