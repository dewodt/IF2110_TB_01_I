#include <stdio.h>
#include "../tree/tree.h"

/* Prosedur membuat kicauan baru */
void createKicauan(Kicauan *k, int id, char text[], int like, char author, DATETIME datetime)
/* I.S. data id, text, like, author, datetime valid */
/* F.S. Terbentuk kicauan dengan id, teks, like, author, datetime sesuai input */
{
  // Update info kicauan
  InfoKicauan infoKicauan = INFOKICAUAN(*k);

  ID(infoKicauan) = id;
  AUTHOR(infoKicauan) = author;
  LIKE(infoKicauan) = like;
  DATETIME(infoKicauan) = datetime;

  // Update text
  int i;
  for (i = 0; i < 280; i++)
  {
    TEXT(infoKicauan)
    [i] = text[i];
  }

  // Set first child null
  FIRSTLEFTCHILD(*k) = NULL;
}

/* Prosedur membuat balasan baru */
AddressBalasan newNodeBalasan(Balasan balasan);
/* I.S. Sembarang */
/* F.S. Bila alokasi berhasil, terbentuk alokasi node balasan baru
  Bila alokasi gagal, F.S.=I.S. */