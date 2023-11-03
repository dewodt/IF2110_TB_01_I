#include "utas.h"

// Teks tidak akan kosong
void copyText(Word textIn, Word *textOut)
{
    (*textOut).Length = (textIn).Length;
    for (int i = 0; i < (*textOut).Length; i++)
    {
        (*textOut).TabWord[i] = (textIn).TabWord[i];
    }
}

void CreateThread(ListDin *thread, Word text, DATETIME time)
{
    // ID Utas  -> Mulai dari 1
    int idU = NEFF(*thread) + 1; // Lebih 1 dari index array
    (ELMT(*thread, NEFF(*thread))).IDUtas = idU;

    // Date Time
    Day(DateTime(ELMT(*thread, idU - 1))) = Day(time);
    Month(DateTime(ELMT(*thread, idU - 1))) = Month(time);
    Year(DateTime(ELMT(*thread, idU - 1))) = Year(time);
    Hour(Time(DateTime(ELMT(*thread, idU - 1)))) = Hour(Time(time));
    Minute(Time(DateTime(ELMT(*thread, idU - 1)))) = Minute(Time(time));
    Second(Time(DateTime(ELMT(*thread, idU - 1)))) = Second(Time(time));

    // Text
    copyText(text, &(ELMT(*thread, idU - 1)).text);

    NEFF(*thread) += 1;
    // Sambungan masih null krn blm ada

    // LOOPING NANYA MAU NAMBAH KICAUAN SAMBUNGAN GA
}

void addThread(ListDin *thread, Word text, int idUtas, int index)
{
    Address N = newNode(text);                          // JANLUP DI MODIF
    Address p = Sambungan(BUFFER(*thread)[idUtas - 1]); // Menunjuk ke kicauan sambungan pertama
    if (p = NULL)
    {
        Sambungan(BUFFER(*thread)[idUtas - 1]) = N;
    }
    else
    {
        int idx = 1;
        while (next(p) != NULL && idx < index)
        {
            p = NEXT(p);
            idx++;
        }
        NEXT(p) = N;
    }
}

int main()
{
    ListDin thread;
    CreateList(&thread);
}