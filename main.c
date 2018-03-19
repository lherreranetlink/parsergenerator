#include <stdio.h>
#include <stdlib.h>
#include "rulecreator.h"

int main(int argc, char* argv[])
{
    char filename[] = "example";
    FILE* fd;
    if ((fd = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "%s file not exists\n", filename);
        exit(1);
    }
    createRules(fd);
    return 0;
}
