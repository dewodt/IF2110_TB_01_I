#include "stackdraf.h"
#include <stdio.h>

int main()
{
    Stack S, RS, tempStack;
    infotype X;

    // Membuat stack kosong
    CreateEmptyStack(&S);
    CreateEmptyStack(&RS);
    CreateEmptyStack(&tempStack); // Added line to create a temporary stack

    // Menambahkan elemen ke dalam stack
    printf("Push elemen ke dalam stack:\n");
    for (int i = 1; i <= 5; i++)
    {
        printf("Input (integer) %d: ", i);
        scanf("%d", &X);
        PushStack(&S, X);
        printf("Element pushed\n");
    }

    // Menampilkan isi stack sebelum dibalik
    printf("\nStack sebelum di reverse:\n");
    while (!IsEmptyStack(S))
    {
        PopStack(&S, &X);
        PushStack(&tempStack, X);
        printf("%d\n", X);
    }

    ReverseStack(tempStack, &RS);

    // Menampilkan isi stack setelah dibalik
    printf("\nStack setelah di reverse:\n");

    while (!IsEmptyStack(RS))
    {
        PopStack(&RS, &X);
        printf("%d\n", X);
    }

    return 0;
}
