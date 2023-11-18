#include "listdinForUtas.c"
#include "../listlinier/listlinierForUtas.c"

int main()
{
    // Membuat kicauan utama
    Kicauan k;
    ID(k) = 10;
    char text[280] = "Halooo Burbir";
    for (int i = 0; i < 280; i++)
    {
        (TEXT(k))[i] = text[i];
    }
    LIKE(k) = 77;
    char author[20] = "Messi";
    for (int i = 0; i < 20; i++)
    {
        (AUTHOR(k))[i] = author[i];
    }
    DATETIME(k) = getCurrTime();

    // Output sederhana kicauan
    // printf("Output\n");
    // printf("ID= %d\n", ID(k));
    // printf("TEXT= %s\n", TEXT(k));
    // printf("LIKE= %d\n", LIKE(k));
    // printf("ID= %s\n", AUTHOR(k));
    // printf("DATETIME= ");
    // displayTime(DATETIME(k));
    // printf("\n");

    // Membuat Utas
    UTAS U;
    CreateUtas(&U, &k, 1);
    // displayUtas(U);

    SambungUtas(&U, "Sambungan 1", 1);
    SambungUtas(&U, "Sambungan 2", 2);
    SambungUtas(&U, "Sambungan 3", 3);
    SambungUtas(&U, "Sambungan 4", 4);
    SambungUtas(&U, "Sambungan 5", 5);
    SambungUtas(&U, "Sambungan 6", 6);

    // Membuat List Utas
    ListUtas li;
    CreateListUtas(&li, 10);

    deleteSambungan(&U, 1);
    insertUtas(&li, U);
    // displayUtas(U);
    deleteSambungan(&U, 1);
    insertUtas(&li, U);
    // displayUtas(U);
    deleteSambungan(&U, 1);
    insertUtas(&li, U);
    // displayUtas(U);
    deleteSambungan(&U, 1);
    insertUtas(&li, U);
    // displayUtas(U);

    displayUtas(BUFFERListDinUtas(li)[0]);
    displayUtas(BUFFERListDinUtas(li)[1]);
    displayUtas(BUFFERListDinUtas(li)[2]);
    displayUtas(BUFFERListDinUtas(li)[3]);
}