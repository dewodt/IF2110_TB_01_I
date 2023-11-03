#include "listlinierForUtas.h"
#include "stdio.h"
#include "stdlib.h"

// Meng-copy word
void copyText(Word textIn, Word *textOut)
{
  (*textOut).Length = (textIn).Length;
  for (int i = 0; i < (*textOut).Length; i++)
  {
    (*textOut).TabWord[i] = (textIn).TabWord[i];
  }
}

// newNode modified
Address newThreadNode(Word text, DATETIME time)
{
  Address p = (Address)malloc(sizeof(ThreadNode));
  if (p != NULL)
  {
    // Text Thread
    copyText(text, &TextThread(p));

    // Date Time Thread
    Day(TimeThread(p)) = Day(time);
    Month(TimeThread(p)) = Month(time);
    Year(TimeThread(p)) = Year(time);
    Second(Time(TimeThread(p))) = Second(Time(time));
    Minute(Time(TimeThread(p))) = Minute(Time(time));
    Hour(Time(TimeThread(p))) = Hour(Time(time));

    // Next Thread
    NextThread(p) = NULL;
  }
  return p;
}

// Create Node Modified
void CreateThreads(threads *l)
{
  FIRST(*l) = NULL;
}

// isEmpty modified
boolean isThreadsEmpty(threads l)
{
  return FIRST(l) == NULL;
}

// insertFirst modified
void insertFirstThreads(threads *l, Word text, DATETIME time)
{
  Address p = newThreadNode(text, time);
  if (p != NULL)
  {
    NextThread(p) = *l;
    FIRST(*l) = p;
  }
}

// insertlast modified
void insertLastThreads(threads *l, Word text, DATETIME time)
{
  if (isThreadsEmpty(*l))
  {
    insertFirstThreads(l, text, time);
  }
  else
  {
    Address p = newThreadNode(text, time);
    if (p != NULL)
    {
      Address temp = FIRST(*l);
      while (NextThread(temp) != NULL)
      {
        temp = NextThread(temp);
      }
      NextThread(temp) = p;
    }
  }
}

// deleteFirst modified
void deleteFirstThreads(threads *l)
{
  Address temp = FIRST(*l);
  FIRST(*l) = NEXT(temp);
  free(temp);
}

// deleteAt modified
void deleteAtThreads(threads *l, int idx)
// First berada pada utas pertama,
{
  idx -= 1;
  if (idx == 0)
  {
    deleteFirstThreads(l);
  }
  else
  {
    int i = 0;
    Address loc = FIRST(*l);
    while (i < idx - 1)
    {
      i++;
      loc = NextThread(loc);
    }

    Address p = NextThread(loc);
    NextThread(loc) = NEXT(p);
    free(p);
  }
}

int length(threads l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
  int count = 0;
  Address p = FIRST(l);
  while (p != NULL)
  {
    count++;
    p = NextThread(p);
  }
  return count;
}