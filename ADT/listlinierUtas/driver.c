#include "listlinierForUtas.c"
#include "../datetime/datetime.c"
#include "../time/time.c"

int main()
{
    threads thread;
    CreateThreads(&thread);
    char kar[MAX_CHAR];
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", &kar);
        insertLastThreads(&thread, kar);
    }
    displayThreads(thread, "panji");
    printf("%d", lengthThreads(thread));

    deleteAtThreads(&thread, 1);
    displayThreads(thread, "panji");
    printf("%d", lengthThreads(thread));
}