#include "hw_hdr.h"
#include "mystr.h"

#define STR "This a test string."

int main(int argc, char *argv[])
{
    char *src = (argc > 1) ? argv[1] : STR;
    char *dest = (char *) malloc(myStrlen(src));
    myStrcpy(dest, src);
    puts(dest);
}
