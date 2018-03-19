#ifndef IOUTILS_H_INCLUDED
#define IOUTILS_H_INCLUDED
#include <stdio.h>

void initializeBuffer();
int getnextchar(FILE* input);
void ungetchar(int charRead);

#endif // IOUTILS_H_INCLUDED
