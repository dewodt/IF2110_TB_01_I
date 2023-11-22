#include "listlinierForUtas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../masukan/masukan.h"

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

/* List linier */
// Membuat kicauan sambungan
AddressUtas newThreadNode(char text[MAX_CHAR], DATETIME time) // Works
{
  AddressUtas p = (AddressUtas)malloc(sizeof(ThreadNode));
  if (p != NULL)
  {
    // Text Thread
    strcpy(TextThread(p), text);

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
  AddressUtas p = newThreadNode(text, getCurrTime());
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
    AddressUtas N = newThreadNode(text, getCurrTime());
    if (N != NULL)
    {
      AddressUtas temp = FIRST(*l);
      while (NextThread(temp) != NULL)
      {
        temp = NextThread(temp);
      }
      NextThread(temp) = N;
    }
  }
}

// Memasukkan Elemen pada indeks tertentu, indeks dipastikan valid, index dimulai dari 1
void insertAtThreads(threads *l, char text[MAX_CHAR], int idx)
{
  AddressUtas P = *l;
  AddressUtas prevP = NULL;

  if (idx == 1)
  {
    insertFirstThreads(l, text);
  }
  else
  {
    AddressUtas N = newThreadNode(text, getCurrTime());
    for (int i = 1; i < idx; i++)
    {
      prevP = P;
      P = NextThread(P);
    }
    NextThread(prevP) = N;
    NextThread(N) = P;
  }
}

// Fungsi untuk me-load utas dari config
void insertLastThreadForConfig(UTAS *utas, char text[MAX_CHAR], DATETIME time)
{
  AddressUtas P = KicauanSambungan(*utas);
  AddressUtas N = newThreadNode(text, time);
  if (P == NULL)
  {
    KicauanSambungan(*utas) = N;
  }
  else
  {
    while (NextThread(P) != NULL)
    {
      P = NextThread(P);
    }
    NextThread(P) = N;
  }
}

// Menghapus Elemen pertama pada utas
void deleteFirstThreads(threads *l) // Works
{
  AddressUtas temp = FIRST(*l);
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
    AddressUtas loc = FIRST(*l);
    while (i < idx - 1)
    {
      i++;
      loc = NextThread(loc);
    }

    AddressUtas p = NextThread(loc);
    NextThread(loc) = NextThread(p);
    free(p);
  }
}

// Mengembalikan jumlah kicauan sambungan pada threads
int lengthThreads(threads l) // Works
{
  int count = 0;
  AddressUtas p = FIRST(l);
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

  AddressUtas P = FIRST(l);
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

// Konstruktor Utas
void CreateUtas(UTAS *u, Kicauan *kicauan, int id)
{
  threads sambungan;
  CreateThreads(&sambungan);
  KicauanUtama(*u) = kicauan;
  IDUtas(*u) = id;
  KicauanSambungan(*u) = sambungan;
}

// Menyambung utas pada elemen terakhir, dipastikan index valid
void SambungUtasLast(UTAS *u, char text[MAX_CHAR])
{
  insertLastThreads(&KicauanSambungan(*u), text);
}

// Menyambung utas pada index tertentu, dipastikan index valid. INDEX DIMULAI DARI 1
void SambungUtasAt(UTAS *u, char text[MAX_CHAR], int index)
{
  insertAtThreads(&KicauanSambungan(*u), text, index);
}

// Menyambung utas pada index tertentu, dipastikan index valid. INDEX DIMULAI DARI 1
void HapusUtasAt(UTAS *u, int index)
{
  if (index == 1)
  {
    AddressUtas temp = KicauanSambungan(*u);
    KicauanSambungan(*u) = NextThread(temp);
    free(temp);
  }
  else
  {
    deleteAtThreads(&KicauanSambungan(*u), index);
  }
}

// Menampilkan Utas dengan format pada spek
void displayUtas(UTAS u)
{
  // Cetak kicauan utama
  printf(" | ID = %d\n", ID(*(KicauanUtama(u))));
  printf(" | %s\n", AuthorUtas(u));
  printf(" | ");
  displayTime(DATETIME(*(KicauanUtama(u))));
  printf("\n");
  printf(" | %s\n", TEXT(*(KicauanUtama(u))));
  printf("\n");

  // Cetak kicauan sambungan
  displayThreads(KicauanSambungan(u), AuthorUtas(u));
}
