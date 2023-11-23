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

void bacaAwalFile(MASUKANFILE *MASUKANFILE, MASUKAN namaFile, int x)
{

  char* str = MASUKANToStr(namaFile);
  //printf("%s\n", str);
  if(x == 1){
    STARTMASUKANFILE(concatStr(concatStr("config/",MASUKANToStr(namaFile)),"pengguna.config")); 
  }
  else if (x == 2){
    STARTMASUKANFILE(concatStr(concatStr("config/",MASUKANToStr(namaFile)),"kicauan.config")); 
  }else if (x == 3)
  {
    STARTMASUKANFILE(concatStr(concatStr("config/",MASUKANToStr(namaFile)),"balasan.config")); 
  }else if (x == 4)
  {
    STARTMASUKANFILE(concatStr(concatStr("config/",MASUKANToStr(namaFile)),"draf.config")); 
  }else if (x == 5)
  {
    STARTMASUKANFILE(concatStr(concatStr("config/",MASUKANToStr(namaFile)),"utas.config")); 
  }
  
  
  
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

// membaca pengguna.config
// status: done?
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
  int e;
  for ( e = 0; e < n; e++)
  {
    bacaLanjutFile(&masukanFile);
    int f;
    for ( f = 0; f < masukanFile.Length; f++)
    {
      ELMT_MTX(,e,f) == masukanFile.TabMASUKANFILE[2*f] - 48;
    }  
  }
  bacaLanjutFile(&masukanFile);
  int g;
  g = masukanFileToInt(masukanFile);
  int h;
  for ( h = 0; h < g; h++)
  { 
    bacaLanjutFile(&masukanFile);
    int x;
    int numTemp,num1,num2;
    numTemp = 0;
    num1 = -1;
    num2 = -1;
    for ( x = 0; x < masukanFile.Length; x++)
    {
      if(num1 == -1 && num2 == -1){
        if(masukanFile.TabMASUKANFILE[x] != 32){
          numTemp *= 10;
          numTemp += masukanFile.TabMASUKANFILE[x] - 48;
        }else{
          if(num1 == -1){
            num1 = numTemp;
          }else{
            num2 = numTemp
          }
      }
      }
    }
    ELMT_MTX(RelasiTeman,num1,num2) = 1;
  }
}

// membaca kicauan.config
// status: done?
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

// membaca balasan.config
// status: done?
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

// membaca pengguna.config
// status: tinggal connectin thread
void bacaUtas(ListDinKicauan* listKicauan, MASUKAN namaFile, ListStatik listPengguna, ListUtas listUtas){
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
    int a;
    a = 0;
    a = masukanFileToInt(masukanFile);
    Kicauan kicauan;
    kicauan = ELMT_LDK(listKicauan,idKicau);
    UTAS utasUtama;
    CreateUtas(&utasUtama, &kicauan, i);
    for ( a = 0; a < listKicauan->nEff; a++)
    {
      bacaLanjutFile(&masukanFile);
      char* text;
      text = MASUKANToStr(masukanFileToMasukan(masukanFile));
      bacaLanjutFile(&masukanFile); // just for skipping author karena udah bs ambil author dari kicauan
      bacaLanjutFile(&masukanFile);
      int HH = charToInt(masukanFile.TabMASUKANFILE[11])*10 + charToInt(masukanFile.TabMASUKANFILE[12]);
      int MM = charToInt(masukanFile.TabMASUKANFILE[14])*10 + charToInt(masukanFile.TabMASUKANFILE[15]);
      int SS = charToInt(masukanFile.TabMASUKANFILE[17])*10 + charToInt(masukanFile.TabMASUKANFILE[18]);
      int DD = charToInt(masukanFile.TabMASUKANFILE[0])*10 + charToInt(masukanFile.TabMASUKANFILE[1]);
      int BB = charToInt(masukanFile.TabMASUKANFILE[3])*10 + charToInt(masukanFile.TabMASUKANFILE[4]);
      int YYYY = charToInt(masukanFile.TabMASUKANFILE[6])*1000 + charToInt(masukanFile.TabMASUKANFILE[7])*100 + charToInt(masukanFile.TabMASUKANFILE[8])*10 + charToInt(masukanFile.TabMASUKANFILE[9]);
      DATETIME datetime;
      CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);
      User author;
      author = tempKicauan.author;
      // threads tempUtas;
      // tempUtas = newThreadNode(text,datetime);
      insertLastThreadForConfig(&utasUtama, text, datetime);
    }
    insertUtas(&listUtas,utasUtama);
  }
  
}

void MASUKANFILEToStrAndInt(MASUKANFILE masukanFile, MASUKANFILE* nama, int* angka){
  int a;
  int idxLastSpace;
  idxLastSpace = -1;
  for ( a = 0; a < masukanFile.Length; a++)
  {
    if(masukanFile.TabMASUKANFILE[a] == 32){
      idxLastSpace = a;
    }
  }
  MASUKANFILE masukanNama, masukanAngka;
  int b;
  for ( b = 0; b < idxLastSpace + 1; b++)
  {
    masukanNama.Length += 1;
    masukanNama.TabMASUKANFILE[b] = masukanFile.TabMASUKANFILE[b];
  }
  int c;
  int idx;
  idx = 0;
  for ( c = idxLastSpace+ 1 ; c < masukanFile.Length ; c++)
  {
    masukanAngka.Length += 1;
    masukanAngka.TabMASUKANFILE[idx] = masukanFile.TabMASUKANFILE[c];
    idx ++;
  }
  *nama = masukanNama;
  *angka = masukanFileToInt(masukanAngka);
}

void bacaDraf(ListDinKicauan* listKicauan, MASUKAN namaFile, ListStatik listPengguna){
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile,namaFile);
  int n;
  n = masukanFileToInt(masukanFile);
  int i;
  for ( i = 0; i < n; i++)
  {
    bacaLanjutFile(&masukanFile);
    MASUKANFILE tempAuthor;
    int count;
    MASUKANFILEToStrAndInt(masukanFile,&tempAuthor,&count);
    char* nama = MASUKANToStr(masukanFileToMasukan(tempAuthor));
    User author;
    boolean authorFound;
    authorFound = false;
    int b = 0;
    while(b < listLength(listPengguna) && !authorFound){
      if(USERNAME(listPengguna,b) == nama){
        authorFound = true;
        author = listPengguna.contents[b];
      }else{
        b ++;
      }
    }
    Stack s;
    CreateEmptyStack(&s);
    int a;
    for ( a = 0; a < count; a++)
    {
      bacaLanjutFile(&masukanFile);
      char* text;
      text = MASUKANToStr(masukanFileToMasukan(masukanFile));
      bacaLanjutFile(&masukanFile);
      int HH = charToInt(masukanFile.TabMASUKANFILE[11])*10 + charToInt(masukanFile.TabMASUKANFILE[12]);
      int MM = charToInt(masukanFile.TabMASUKANFILE[14])*10 + charToInt(masukanFile.TabMASUKANFILE[15]);
      int SS = charToInt(masukanFile.TabMASUKANFILE[17])*10 + charToInt(masukanFile.TabMASUKANFILE[18]);
      int DD = charToInt(masukanFile.TabMASUKANFILE[0])*10 + charToInt(masukanFile.TabMASUKANFILE[1]);
      int BB = charToInt(masukanFile.TabMASUKANFILE[3])*10 + charToInt(masukanFile.TabMASUKANFILE[4]);
      int YYYY = charToInt(masukanFile.TabMASUKANFILE[6])*1000 + charToInt(masukanFile.TabMASUKANFILE[7])*100 + charToInt(masukanFile.TabMASUKANFILE[8])*10 + charToInt(masukanFile.TabMASUKANFILE[9]);
      DATETIME datetime;
      CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);
      Draf tempDraf;
      CreateDraf(&tempDraf, text,datetime);
      PushStack(&s,tempDraf);
    }
    Stack fs;
    ReverseStack(s,&fs);
    DRAF(listPengguna,b) = fs;
  }
  
}