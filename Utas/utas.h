#include "../ADT/time/time.h"
#include "../ADT/time/datetime.c"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/listlinier/listlinier.h"

#ifndef UTAS_H
#define UTAS_H

// Bentukan Utas
typedef struct
{
    int IDUtas;
    DATETIME datetime;
    Word text;
    Address sambungan;
} UTAS;

#define Sambungan(u) (u).sambungan
#define Text(u) (u).text
#define DateTime(u) (u).datetime
#define IDUtas(u) (u).IDUtas

// Modified List Dinamis Untuk Menyimpan Utas
typedef int IdxType;
typedef struct
{
    UTAS *buffer;
    int nEff;
    int capacity;
} ListDin;

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

// Modified List Linier Untuk Kicauan Sambungan
/* Definisi Node : */

typedef struct node *Address;
typedef struct node
{
    Word info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(Word text);

#endif