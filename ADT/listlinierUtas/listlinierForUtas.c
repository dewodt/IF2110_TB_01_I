#include "listlinierForUtas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Mengembalikan waktu lokal dalam tipe bentukan DATETIME
DATETIME getCurrTime() // Works
{
  DATETIME datetime;
  time_t t = time(NULL);
  struct tm date = *localtime(&t);
  Year(datetime) = date.tm_year + 1900;
  Month(datetime) = date.tm_mon + 1;
  Day(datetime) = date.tm_mday;
  Hour(Time(datetime)) = date.tm_hour;
  Minute(Time(datetime)) = date.tm_min;
  Second(Time(datetime)) = date.tm_sec;

  return datetime;
}

// Menampilkan date dengan format "DD/MM/YYYY H:M:S" tanpa karakter setelah dan sebelumnya
void displayTime(DATETIME time) // Works
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
void copyText(char textIn[MAX_CHAR], char textOut[MAX_CHAR]) // Works
{
  for (int i = 0; i < 180; i++)
  {
    (textOut)[i] = textIn[i];
  }
}

// Membuat kicauan sambungan
Address newThreadNode(char text[MAX_CHAR]) // Works
{
  DATETIME time = getCurrTime();
  Address p = (Address)malloc(sizeof(ThreadNode));
  if (p != NULL)
  {
    // Text Thread
    copyText(text, TextThread(p));

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
void CreateThreads(threads *l) // Works
{
  FIRST(*l) = NULL;
}

// Mengembalikan true jika UTAS kosong
boolean isThreadsEmpty(threads l)
{
  return FIRST(l) == NULL;
}

// Memasukkan kicauan sambungan di awal threads
void insertFirstThreads(threads *l, char text[MAX_CHAR]) // Works
{
  Address p = newThreadNode(text);
  if (p != NULL)
  {
    NextThread(p) = FIRST(*l);
    FIRST(*l) = p;
  }
}

// Memasukkan elemen terakhirpada utas
void insertLastThreads(threads *l, char text[MAX_CHAR]) // Works
{
  if (isThreadsEmpty(*l))
  {
    insertFirstThreads(l, text);
  }
  else
  {
    Address p = newThreadNode(text);
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

// Memasukkan Elemen pada indeks tertentu, indeks dipastikan valid, index dimulai dari 1
void insertAtThreads(threads *l, char text[MAX_CHAR], int idx)
{
  Address P = *l;
  Address prevP = NULL;

  if (idx == 1)
  {
    insertFirstThreads(l, text);
  }
  else
  {
    Address N = newThreadNode(text);
    for (int i = 1; i < idx; i++)
    {
      prevP = P;
      P = NextThread(P);
    }
    NextThread(prevP) = N;
    NextThread(N) = P;
  }
}

// Menghapus Elemen pertama pada utas
void deleteFirstThreads(threads *l) // Works
{
  Address temp = FIRST(*l);
  FIRST(*l) = NextThread(temp);
  free(temp);
}

// Menghapus Elemen dengan index pertama dimulai dari 1, dipastikan indeks valid
void deleteAtThreads(threads *l, int idx) // Works
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
int lengthThreads(threads l) // Works
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
void displayThreads(threads l, char author[20])
{
  int index = 1;

  Address P = FIRST(l);
  while (P != NULL)
  {
    printf("   | INDEX = %d\n", index);
    printf("   | %s\n", author);
    printf("   | ");
    displayTime(TimeThread(P));
    printf("\n");
    printf("   | %s\n", TextThread(P));
    printf("\n");
    P = NextThread(P);
    index++;
  }
}