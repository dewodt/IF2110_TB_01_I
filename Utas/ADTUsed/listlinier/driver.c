#include <stdio.h>
#include "listlinierForUtas.h"

int main()
{
    char str[100] = "tesssss";
    char nar[100];

    for (int i = 0; i < 100; i++)
    {
        nar[i] = str[i];
    }
    printf("%s", nar);
}