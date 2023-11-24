#include "prioQueueint.h"
#include <stdio.h>

infotypeQ MakePQ(int prio, char info)
{
    infotypeQ newElement;
    Prio(newElement) = prio;
    Info(newElement) = info;
    return newElement;
}

int main()
{
    PrioQueueint Q;
    MakeEmpty(&Q, 5);

    // Memasukan Elemen dengan prioritas
    char input;
    int inpt;
    scanf("%d %c", &inpt, &input);
    Enqueue(&Q, MakePQ(inpt, input));

    scanf("%d %c", &inpt, &input);
    Enqueue(&Q, MakePQ(inpt, input));

    scanf("%d %c", &inpt, &input);
    Enqueue(&Q, MakePQ(inpt, input));

    scanf("%d %c", &inpt, &input);
    Enqueue(&Q, MakePQ(inpt, input));

    printf("\nElemen priority queue:\n");
    PrintPrioQueueint(Q);

    // Dequeue Element
    infotypeQ X;
    Dequeue(&Q, &X);
    printf("Dequeue: %d %c\n", Prio(X), Info(X));
    PrintPrioQueueint(Q);

    Dequeue(&Q, &X);
    printf("Dequeue: %d %c\n", Prio(X), Info(X));
    PrintPrioQueueint(Q);

    // Enqueue Element
    Enqueue(&Q, MakePQ(5, 'E'));
    Enqueue(&Q, MakePQ(2, 'F'));

    // Final outpur
    printf("Elemen hasil operasi:\n");
    PrintPrioQueueint(Q);

    DeAlokasi(&Q);
}
