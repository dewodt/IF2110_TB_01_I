#include <stdio.h>
#include "listlinierForUtas.h"
#include "../masukan/masukan.c"
#include "../tree/tree.h"
#include "../modifiedliststatik/modifiedliststatik.h"

char currentChar;
boolean EOP;

int main()
{
    threads sambungan;
    UTAS utas;
    int i;
    char input[280];

    // Membuat Kicauan sambungan
    CreateThreads(&sambungan);
    for (i = 0; i < 4; i++)
    {
        printf("Masukkan Kicauan Sambungan ke-%d\n", i + 1);
        scanf("%s", &input);
        insertLastThreads(&sambungan, input, getCurrTime());
    }

    printf("\nKicauan Sambungan:\n\n");
    displayThreads(sambungan, "Random Man");
}