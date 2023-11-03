#include "listlinierForUtas.h"
#include "stdio.h"
#include "stdlib.h"

// Menampilkan date dengan format "DD/MM/YYYY H:M:S" tanpa karakter setelah dan sebelumnya
void displayTime(DATETIME time)
{
  int day, month, year, hour, minute, second;
  day = Day(time);
  month = Month(time);
  year = Year(time);
  hour = Hour(Time(time));
  minute = Minute(Time(time));
  second = Second(Time(time));

  printf("%d/%d/%d %d:%d:%d", day, month, year, hour, minute, second);
}

// Meng-copy word
void copyText(char textIn[MAX_CHAR], char *textOut[MAX_CHAR])
{
  for (int i = 0; i < 180; i++)
  {
    (*textOut)[i] = textIn[i];
  }
}

// Membuat kicauan sambungan
Address newThreadNode(char text[MAX_CHAR], DATETIME time)
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

// Membuat UTAS baru
void CreateThreads(threads *l)
{
  FIRST(*l) = NULL;
}

// Mengembalikan true jika UTAS kosong
boolean isThreadsEmpty(threads l)
{
  return FIRST(l) == NULL;
}

// Memasukkan kicauan sambungan di awal threads
void insertFirstThreads(threads *l, char text[MAX_CHAR], DATETIME time)
{
  Address p = newThreadNode(text, time);
  if (p != NULL)
  {
    NextThread(p) = FIRST(*l);
    FIRST(*l) = p;
  }
}

// Memasukkan elemen terakhirpada utas
void insertLastThreads(threads *l, char text[MAX_CHAR], DATETIME time)
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

// Menghapus Elemen pertama pada utas
void deleteFirstThreads(threads *l)
{
  Address temp = FIRST(*l);
  FIRST(*l) = NextThread(temp);
  free(temp);
}

// Menghapus Elemen dengan index pertama dimulai dari 1
void deleteAtThreads(threads *l, int idx)
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
    NextThread(loc) = NextThread(p);
    free(p);
  }
}

// Mengembalikan jumlah kicauan sambungan pada threads
int lengthThreads(threads l)
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

// Menampilkan threads secara keseluruhan, kicauan utama tidak ditampilkan
void displayThreads(threads l)
{
  int index = 1;

  Address P = FIRST(l);
  while (P != NULL)
  {
    printf("   | INDEX = %d\n", index);
    printf("   | INI NANTI DIAMBIL DARI KICAUAN\n");
    printf("   | ");
    displayTime(TimeThread(l));
    printf("\n");
    printf("   | %s\n", TextThread(l));
  }
}