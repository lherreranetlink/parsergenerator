#include "ioutils.h"

static char buff[BUFSIZ], *buffp;

void initializeBuffer()
{
    buffp = buff;
}

int getnextchar(FILE* input)
{
    return (buffp == buff)?fgetc(input):*--buffp;
}

void ungetchar(int c)
{
    *buffp++ = c;
}
