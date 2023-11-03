#include "ADTUsed/time/time.h"
#include "ADTUsed/datetime/datetime.h"
#include "ADTUsed/listlinier/listlinierForUtas.h"
#include "ADTUsed/kicauan/kicauan.h"

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