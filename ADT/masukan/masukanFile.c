#include "stdio.h"
#include "stdlib.h"
#include "../boolean.h"
// #include "../modifiedliststatik/modifiedliststatik.h"
#include "masukanFile.h"

/* State Mesin MASUKANFILE */
boolean EndMASUKANFILE;
MASUKANFILE currentMASUKANFILE;
//boolean EOP;
//char currentChar;

void STARTMASUKANFILE(char nameFile[])
/* I.S. : currentChar sembarang
   F.S. : EndMASUKANFILE = true, dan currentChar = MARK;
          atau EndMASUKANFILE = false, currentMASUKANFILE adalah MASUKANFILE yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir MASUKANFILE */
{
  STARTFILE(nameFile);
  if (currentCharFILE == 10)
  {
    EndMASUKANFILE = true;
  }
  else
  {
    EndMASUKANFILE = false;
    CopyMASUKANFILE();
  }
}

void ADVMASUKANFILE()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentMASUKANFILE adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndMASUKANFILE = true.
   Proses : Akuisisi kata menggunakan procedure SalinMASUKANFILE */
{
  if (currentCharFILE == MARK)
  {
    EndMASUKANFILE = true;
  }
  else
  {
    CopyMASUKANFILE();
  }
}

void CopyMASUKANFILE()
/* Mengakuisisi MASUKANFILE, menyimpan dalam currentMASUKANFILE
   I.S. : currentChar adalah karakter pertama dari MASUKANFILE
   F.S. : currentMASUKANFILE berisi MASUKANFILE yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang MASUKANFILE melebihi NMax, maka sisa MASUKANFILE "dipotong" */
{
  int i = 0;
  do
  {
    currentMASUKANFILE.TabMASUKANFILE[i] = currentCharFILE;
    ADVFILE();
    i += 1;
  } while (currentCharFILE != 10 && i < NMax);
  currentMASUKANFILE.Length = i;
}

int masukanFileToInt(MASUKANFILE masukanFile){
  int hasil;
  hasil = 0;
  int i;
  for ( i = 0; i < masukanFile.Length; i++)
  {
    hasil *= 10;
    hasil += masukanFile.TabMASUKANFILE[i] - 48;
  }
  return hasil;
}

int charToInt(char sebenarnyaInt){
  return sebenarnyaInt - 48;
}

void bacaAwalFile(MASUKANFILE *MASUKANFILE, MASUKAN namaFile)
{

  char* str = MASUKANToStr(namaFile);
  //printf("%s\n", str);
  STARTMASUKANFILE(str); // sekarang gini dulu untuk testing, nanti bakal di ubah jadi STARTMASUKANFILE("../../?" + str + ?.config);
  *MASUKANFILE = currentMASUKANFILE;
  if ((*MASUKANFILE).TabMASUKANFILE[0] == 10)
  {
    int i;
    for (i = 1; i < (*MASUKANFILE).Length; i++)
    {
      (*MASUKANFILE).TabMASUKANFILE[i - 1] = (*MASUKANFILE).TabMASUKANFILE[i];
    }
    (*MASUKANFILE).Length = (*MASUKANFILE).Length - 1;
  }
  else
  {
  }
}

void bacaLanjutFile(MASUKANFILE *MASUKANFILE)
{
  ADVMASUKANFILE();
  *MASUKANFILE = currentMASUKANFILE;
  if ((*MASUKANFILE).TabMASUKANFILE[0] == 10)
  {
    int i;
    for (i = 1; i < (*MASUKANFILE).Length; i++)
    {
      (*MASUKANFILE).TabMASUKANFILE[i - 1] = (*MASUKANFILE).TabMASUKANFILE[i];
    }
    (*MASUKANFILE).Length = (*MASUKANFILE).Length - 1;
  }
  else
  {
  }
}

boolean isSameFile(MASUKANFILE masuk, char string[])
{
  // Membandingkan masuk dengan string
  boolean hasil;
  hasil = true;
  int i;
  i = 0;
  while ((i < masuk.Length) && hasil)
  {
    if (masuk.TabMASUKANFILE[i] != string[i])
    {
      hasil = false;
    }
    i++;
  }
  return hasil;
}


void displayMASUKANFILE(MASUKANFILE masuk)
{
  // Menampilkan isi MASUKANFILE
  int i;
  printf("[");
  for (i = 0; i < masuk.Length; i++)
  {
    printf("%c,", masuk.TabMASUKANFILE[i]);
  }
  printf("]\n");
}

MASUKAN masukanFileToMasukan(MASUKANFILE masukanFile){
  MASUKAN hasil;
  hasil.Length = masukanFile.Length;
  int i;
  for ( i = 0; i < masukanFile.Length; i++)
  {
    hasil.TabMASUKAN[i] = masukanFile.TabMASUKANFILE[i];
  }
  
  return hasil;
}

// void MASUKANFILEToStr(MASUKANFILE masukanFile, char *str[])
// {
//   int len = masukanFile.Length;
//   int i;

//   for (i = 0; i < len; i++)
//   {
//     // printf("%c\n", masukan.TabMASUKAN[i]);
//     str[i] = masukanFile.TabMASUKANFILE[i];
//   }
//   str[len] = '\0';
// }

void bacaPengguna(ListStatik* listPengguna, MASUKAN namaFile){
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile,namaFile);
  int n;
  n = masukanFileToInt(masukanFile);
  int i;
  for ( i = 0; i < n; i++)
  {
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int j;
    for ( j = 0; j < masukanFile.Length; j++)
    {
      listPengguna->contents[i].username[j] = masukanFile.TabMASUKANFILE[j];
    }
    
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int k;
    for ( k = 0; k < masukanFile.Length; k++)
    {
      listPengguna->contents[i].password[k] = masukanFile.TabMASUKANFILE[k];   
    }


    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int l;
    for ( l = 0; l < masukanFile.Length; l++)
    {
      listPengguna->contents[i].bio[l] = masukanFile.TabMASUKANFILE[l];
    }
  
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    listPengguna->contents[i].phone_num = masukanFileToMasukan(masukanFile);

    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int a;
    for ( a = 0; a < masukanFile.Length; a++)
    {
      listPengguna->contents[i].weton[a] = masukanFile.TabMASUKANFILE[a];
    }
    
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int b;
    for ( b = 0; b < masukanFile.Length; b++)
    {
      listPengguna->contents[i].acc_type[b] = masukanFile.TabMASUKANFILE[b];
    }
    int c;
    for ( c = 0; c < 5; c++)
    {
      bacaLanjutFile(&masukanFile);
      // displayMASUKANFILE(masukanFile);
      int d;
      for ( d = 0; d < 10; d++)
      {
        ELMT_MTX(listPengguna->contents[i].profile,c,d) = masukanFile.TabMASUKANFILE[2*(d)];
      }
    }
  }
}

void bacaKicauan(ListDinKicauan* listKicauan, MASUKAN namaFile, ListStatik listPengguna){
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile,namaFile);
  int n;
  n = masukanFileToInt(masukanFile);
  int i;
  for ( i = 0; i < n; i++)
  {
    // id
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int id;
    id = masukanFileToInt(masukanFile);
    tempKicauan.id = id;
    // text
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int a;
    char text[masukanFile.Length];
    for ( a = 0; a < masukanFile.Length; a++)
    {
      text[a] = masukanFile.TabMASUKANFILE[a];
    }
    // like
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int like;
    like = masukanFileToInt(masukanFile);
    tempKicauan.like = like;
    // author
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    MASUKAN tempMasukan;
    tempMasukan = masukanFileToMasukan(masukanFile);
    int idx;
    idx = searchID_Pengguna(listPengguna,tempMasukan);
    User author;
    author = listPengguna.contents[idx];
    // datetime
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int HH = charToInt(masukanFile.TabMASUKANFILE[11])*10 + charToInt(masukanFile.TabMASUKANFILE[12]);
    int MM = charToInt(masukanFile.TabMASUKANFILE[14])*10 + charToInt(masukanFile.TabMASUKANFILE[15]);
    int SS = charToInt(masukanFile.TabMASUKANFILE[17])*10 + charToInt(masukanFile.TabMASUKANFILE[18]);
    int DD = charToInt(masukanFile.TabMASUKANFILE[0])*10 + charToInt(masukanFile.TabMASUKANFILE[1]);
    int BB = charToInt(masukanFile.TabMASUKANFILE[3])*10 + charToInt(masukanFile.TabMASUKANFILE[4]);
    int YYYY = charToInt(masukanFile.TabMASUKANFILE[6])*1000 + charToInt(masukanFile.TabMASUKANFILE[7])*100 + charToInt(masukanFile.TabMASUKANFILE[8])*10 + charToInt(masukanFile.TabMASUKANFILE[9]);
    DATETIME datetime;
    CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);
    Kicauan tempKicauan;
    CreateKicauan(&tempKicauan,id,&text,like,&author,datetime);
    AddressKicauan addKicauan;
    addKicauan = newNodeKicauan(tempKicauan);
    insertLastListDinKicauan(listKicauan,addKicauan);
  }
}

void splitMasukanFileJadi2(MASUKANFILE masukanFile, MASUKANFILE* hasil1, MASUKANFILE* hasil2){
  int i;
  boolean spaceFound = false;
  int a,b;
  a = 0;
  b = 0;
  for ( i = 0; i < masukanFile.Length; i++)
  {
    if(masukanFile.TabMASUKANFILE[i] == ' '){
      spaceFound = true;
    }else{
      if(spaceFound){
        hasil2->TabMASUKANFILE[b] = masukanFile.TabMASUKANFILE[i];
        hasil2->Length += 1;
        b ++;
      }else{
        hasil1->TabMASUKANFILE[a] = masukanFile.TabMASUKANFILE[i];
        hasil1->Length += 1;
        a ++;
      }
    }
  }
  
}

void bacaBalasan(ListDinKicauan* listKicauan, MASUKAN namaFile, ListStatik listPengguna){
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile,namaFile);
  int n;
  n = masukanFileToInt(masukanFile);
  int i;
  for ( i = 0; i < n; i++)
  {
    bacaLanjutFile(&masukanFile);
    int id;
    id = masukanFileToInt(masukanFile);
    bacaLanjutFile(&masukanFile);
    int m;
    m = masukanFileToInt(masukanFile);
    int j;
    for ( j = 0; j < m; j++)
    {
      bacaLanjutFile(&masukanFile);
      // parent, id balasan
      MASUKANFILE mP,mQ;
      splitMasukanFileJadi2(masukanFile,mP,mQ);
      int p,q;
      p = masukanFileToInt(mP);
      q = masukanFileToInt(mQ);

      // text
      bacaLanjutFile(&masukanFile);
      char text[masukanFile.Length];
      int a;
      for ( a = 0; a < masukanFile.Length; a++)
      {
        text[a] = masukanFile.TabMASUKANFILE[a];
      }
      
      // author
      bacaLanjutFile(&masukanFile);
      MASUKAN tempMasukan;
      tempMasukan = masukanFileToMasukan(masukanFile);
      int idx;
      idx = searchID_Pengguna(listPengguna,tempMasukan);
      User author;
      author = listPengguna.contents[idx];

      // datetime
      bacaLanjutFile(&masukanFile);
      int HH = charToInt(masukanFile.TabMASUKANFILE[11])*10 + charToInt(masukanFile.TabMASUKANFILE[12]);
      int MM = charToInt(masukanFile.TabMASUKANFILE[14])*10 + charToInt(masukanFile.TabMASUKANFILE[15]);
      int SS = charToInt(masukanFile.TabMASUKANFILE[17])*10 + charToInt(masukanFile.TabMASUKANFILE[18]);
      int DD = charToInt(masukanFile.TabMASUKANFILE[0])*10 + charToInt(masukanFile.TabMASUKANFILE[1]);
      int BB = charToInt(masukanFile.TabMASUKANFILE[3])*10 + charToInt(masukanFile.TabMASUKANFILE[4]);
      int YYYY = charToInt(masukanFile.TabMASUKANFILE[6])*1000 + charToInt(masukanFile.TabMASUKANFILE[7])*100 + charToInt(masukanFile.TabMASUKANFILE[8])*10 + charToInt(masukanFile.TabMASUKANFILE[9]);
      DATETIME datetime;
      CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);
      Balasan tempBalasan;
      CreateBalasan(&tempBalasan,q, &text,&author,datetime);
      TreeKicauan tempTree;
      tempTree = ELMT_LDK(*listKicauan,id-1);
      if(p == -1){
        balasKicauan(tempTree,tempBalasan);
      }else{
        balasBalasan(getBalasan(tempTree,p),tempBalasan);
      }
    }
  }
}

void bacaUtas(ListDinKicauan* listKicauan, MASUKAN namaFile, ListStatik listPengguna){
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile,namaFile);
  int n;
  n = masukanFileToInt(masukanFile);
  int i;
  for ( i = 0; i < n; i++)
  {
    bacaLanjutFile(&masukanFile);
    int idKicau;
    idKicau = masukanFileToInt(masukanFile);
    bacaLanjutFile(&masukanFile);
    a = masukanFileToInt(masukanFile);
    int a;
    a = 0;
    AddressKicauan addKicauan;
    addKicauan = ELMT_LDK(listKicauan,idKicau);
    for ( a = 0; a < listKicauan->nEff; a++)
    {
      bacaLanjutFile(&masukanFile);
      char* 
    }
    
  }
  
}