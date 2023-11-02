#include "boolean.h"
#include "../wordmachine/wordmachine.h"
#include "../time/time.h"
#include "../time/datetime.c"

#ifndef listlinier_H
#define listlinier_Hthreadsthreads

/* Definisi Node : */
typedef int ElType;
typedef struct node *Address;
typedef struct node
{
    Word textThread;
    Address nextThread;
    DATETIME timeThread;
} ThreadNode;

#define TextThread(p) (p)->textThread
#define NextThread(p) (p)->nextThread
#define TimeThread(p) (p)->timeThread

Address newThreadNode(Word text, DATETIME time);

typedef Address threads; // thread -> thread -> thread

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

void CreateThreads(threads *l);

boolean isThreadsEmpty(threads l);

void insertLastThreads(threads *l, Word text, DATETIME time);

void deleteFirstThreads(threads *l);

void deleteAtThreads(threads *l, int idx);

int length(threads l);

#endif