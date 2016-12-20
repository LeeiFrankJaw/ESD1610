#include "hw_hdr.hpp"
#include "mystring.hpp"

int main(int argc, char *argv[])
{
    string str;

    if (argc > 1)
	str = argv[1];
    else
	cin >> str;
    cout << countLetter(str, 'i') << endl;

    return 0;
}
