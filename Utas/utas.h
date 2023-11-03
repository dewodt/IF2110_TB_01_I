#include "ADT/time/time.h"
#include "ADT/time/datetime.c"
#include "ADT/listlinier/listlinierForUtas.h"
#include "ADT/wordmachine/wordmachine.h"
#include "kicauan.h"

#ifndef UTAS_H
#define UTAS_H

// Bentukan Utas
typedef struct
{
    Kicauan *tweet;
    int IDUtas;
    Address sambungan;
} UTAS;

#define Sambungan(u) (u).sambungan
#define Text(u) (u).text
#define DateTime(u) (u).datetime
#define IDUtas(u) (u).IDUtas

#endif