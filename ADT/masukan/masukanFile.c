#include "stdio.h"
#include "stdlib.h"
#include "../boolean.h"
// #include "../modifiedliststatik/modifiedliststatik.h"
#include "masukanFile.h"
#include "../prioQueue/reqPertemanan.h"
#include "../matrixteman/matrixteman.h"

/* State Mesin MASUKANFILE */
boolean EndMASUKANFILE;
MASUKANFILE currentMASUKANFILE;
// boolean EOP;
// char currentChar;

void STARTMASUKANFILE(char *nameFile)
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

int masukanFileToInt(MASUKANFILE masukanFile)
{
  int hasil;
  hasil = 0;
  int i;
  for (i = 0; i < masukanFile.Length; i++)
  {
    hasil *= 10;
    hasil += masukanFile.TabMASUKANFILE[i] - 48;
  }
  return hasil;
}

int charToInt(char sebenarnyaInt)
{
  return sebenarnyaInt - 48;
}

void bacaAwalFile(MASUKANFILE *MASUKANFILE, MASUKAN namaFile, int x)
{

  char *str = MASUKANToStr(namaFile);
  if (x == 1)
  {
    // printf("%s\n", concatStr(concatStr("config/", str), "/pengguna.config"));
    STARTMASUKANFILE(concatStr(concatStr("config/", str), "/pengguna.config"));
  }
  else if (x == 2)
  {
    // printf("%s\n", concatStr(concatStr("config/", str), "/kicauan.config"));
    STARTMASUKANFILE(concatStr(concatStr("config/", str), "/kicauan.config"));
  }
  else if (x == 3)
  {
    // printf("%s\n", concatStr(concatStr("config/", str), "/balasan.config"));
    STARTMASUKANFILE(concatStr(concatStr("config/", str), "/balasan.config"));
  }
  else if (x == 4)
  {
    // printf("%s\n", concatStr(concatStr("config/", str), "/draf.config"));
    STARTMASUKANFILE(concatStr(concatStr("config/", str), "/draf.config"));
  }
  else if (x == 5)
  {
    // printf("%s\n", concatStr(concatStr("config/", str), "/utas.config"));
    STARTMASUKANFILE(concatStr(concatStr("config/", str), "/utas.config"));
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

MASUKAN masukanFileToMasukan(MASUKANFILE masukanFile)
{
  MASUKAN hasil;
  hasil.Length = masukanFile.Length;
  int i;
  for (i = 0; i < masukanFile.Length; i++)
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


void bacaConfig(){
  if(isUserLoggedIn()){
    printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
    return;
  }
  MASUKAN masukan;
  baca(&masukan);
  char* folderDir = concatStr("config/", MASUKANToStr(masukan));
  struct stat st = {0};
  if(stat(folderDir, &st) != 0 || !S_ISDIR(st.st_mode)){
    printf("Tidak ada folder yang dimaksud!\n");
    return;
  }
    bacaPengguna( masukan);
    bacaKicauan(masukan);
    bacaBalasan(masukan);
    // bacaUtas(listKicauan,masukan,listPengguna,&listUtas);
    bacaDraf(masukan);
    printf("Anda akan melakukan pemuatan dari Folder2.\n");
    printf("Mohon tunggu...\n");
    printf("1...\n");
    printf("2...\n");
    printf("3...\n");
    printf("Pemuatan selesai!\n");
}

void bacaInisialisasi(){
  MASUKAN masukan;
  baca(&masukan);
  char* folderDir = concatStr("config/", MASUKANToStr(masukan));
  struct stat st = {0};
  if(stat(folderDir, &st) != 0 || !S_ISDIR(st.st_mode)){
    printf("Tidak ada folder yang dimaksud!\n");
    return;
  }
    bacaPengguna( masukan);
    bacaKicauan(masukan);
    bacaBalasan(masukan);
    // bacaUtas(listKicauan,masukan,listPengguna,&listUtas);
    bacaDraf(masukan);
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}

// membaca pengguna.config
// status: done?
void bacaPengguna(MASUKAN namaFile)
{
  // Dapatkan jumlah user
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile, namaFile, 1);
  int n;
  n = masukanFileToInt(masukanFile);

  int i;
  // Looping per row pengguna
  for (i = 0; i < n; i++)
  {
    // Username
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int j;
    for (j = 0; j < masukanFile.Length; j++)
    {
      listUser.contents[i].username[j] = masukanFile.TabMASUKANFILE[j];
    }

    // Password
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int k;
    for (k = 0; k < masukanFile.Length; k++)
    {
      listUser.contents[i].password[k] = masukanFile.TabMASUKANFILE[k];
    }

    // Bio
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int l;
    for (l = 0; l < masukanFile.Length; l++)
    {
      listUser.contents[i].bio[l] = masukanFile.TabMASUKANFILE[l];
    }

    // Phone number
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    listUser.contents[i].phone_num = masukanFileToMasukan(masukanFile);

    // Weton
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int a;
    for (a = 0; a < masukanFile.Length; a++)
    {
      listUser.contents[i].weton[a] = masukanFile.TabMASUKANFILE[a];
    }

    // Acc type
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    if (isSame(masukanFileToMasukan(masukanFile), "Privat"))
    {
      IS_PRIVATE(listUser, i) = true;
    }
    else
    {
      IS_PRIVATE(listUser, i) = false;
    }

    // Profile picture
    int c;
    // Loop row
    for (c = 0; c < 5; c++)
    {
      // Loop column
      bacaLanjutFile(&masukanFile);
      // displayMASUKANFILE(masukanFile);
      int d;
      for (d = 0; d < 10; d++)
      {
        ELMT_MTX(listUser.contents[i].profile, c, d) = masukanFile.TabMASUKANFILE[2 * (d)];
      }
    }
  }

  // displayMatrixTeman(RelasiPertemanan);
  // Input relasi pertemanan
  // note: ada n user
  int e;
  for (e = 0; e < n; e++)
  {
    bacaLanjutFile(&masukanFile);
    int f;
    for (f = 0; f < n; f++)
    {
      ELMT_MTX(RelasiPertemanan, e, f) = masukanFile.TabMASUKANFILE[2 * f] - 48;
    }
  }
  // printf("\n");
  // displayMatrixTeman(RelasiPertemanan);

  // Input relasi follow
  bacaLanjutFile(&masukanFile);
  int g;
  g = masukanFileToInt(masukanFile);

  // Looping per row prioqueue
  int h;
  for (h = 0; h < g; h++)
  {
    bacaLanjutFile(&masukanFile);
    int x;
    int numTemp, num1, num2;
    numTemp = 0;
    num1 = -1;
    num2 = -1;
    for (x = 0; x < masukanFile.Length; x++)
    {
      if (num1 == -1 || num2 == -1)
      {
        if (masukanFile.TabMASUKANFILE[x] != 32)
        {
          numTemp *= 10;
          numTemp += masukanFile.TabMASUKANFILE[x] - 48;
        }
        else
        {
          if (num1 == -1)
          {
            num1 = numTemp;
            numTemp = 0;
          }
          else
          {
            num2 = numTemp;
          }
        }
      }
    }
    ELMT_MTX(RelasiPertemanan, num1, num2) = 1;
  }
}

// membaca kicauan.config
// status: done?
void bacaKicauan(MASUKAN namaFile)
{
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile, namaFile, 2);
  int n;
  n = masukanFileToInt(masukanFile);

  Kicauan tempKicauan;
  int i;

  for (i = 0; i < n; i++)
  {

    // id
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int id;
    id = masukanFileToInt(masukanFile);

    // text
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    char *text = MASUKANToStr(masukanFileToMasukan(masukanFile));

    // like
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int like;
    like = masukanFileToInt(masukanFile);

    // author
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    MASUKAN tempMasukan;
    tempMasukan = masukanFileToMasukan(masukanFile);
    // displayMASUKAN(tempMasukan);

    int idx = 0;
    searchID_Pengguna(tempMasukan, &idx);
    User *author;
    author = &listUser.contents[0];
    // datetime
    bacaLanjutFile(&masukanFile);
    // displayMASUKANFILE(masukanFile);
    int HH = charToInt(masukanFile.TabMASUKANFILE[11]) * 10 + charToInt(masukanFile.TabMASUKANFILE[12]);
    int MM = charToInt(masukanFile.TabMASUKANFILE[14]) * 10 + charToInt(masukanFile.TabMASUKANFILE[15]);
    int SS = charToInt(masukanFile.TabMASUKANFILE[17]) * 10 + charToInt(masukanFile.TabMASUKANFILE[18]);
    int DD = charToInt(masukanFile.TabMASUKANFILE[0]) * 10 + charToInt(masukanFile.TabMASUKANFILE[1]);
    int BB = charToInt(masukanFile.TabMASUKANFILE[3]) * 10 + charToInt(masukanFile.TabMASUKANFILE[4]);
    int YYYY = charToInt(masukanFile.TabMASUKANFILE[6]) * 1000 + charToInt(masukanFile.TabMASUKANFILE[7]) * 100 + charToInt(masukanFile.TabMASUKANFILE[8]) * 10 + charToInt(masukanFile.TabMASUKANFILE[9]);
    DATETIME datetime;
    CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);

    CreateKicauan(&tempKicauan, id, text, like, author, datetime);
    AddressKicauan addKicauan;
    addKicauan = newNodeKicauan(tempKicauan);
    insertLastListDinKicauan(&listKicauan, addKicauan);
  }
}

void splitMasukanFileJadi2(MASUKANFILE masukanFile, MASUKANFILE *hasil1, MASUKANFILE *hasil2, boolean *neg)
{
  boolean spaceFound = false;
  hasil1->Length = 0;
  hasil2->Length = 0;
  int a, b;
  a = 0;
  b = 0;
  boolean isNeg = false;
  if (masukanFile.TabMASUKANFILE[0] == 45)
  {
    isNeg = true;
  }
  int i;
  for (i = 0; i < masukanFile.Length; i++)
  {
    if (isNeg && i == 0)
    {
    }
    else if (masukanFile.TabMASUKANFILE[i] == ' ')

    {
      spaceFound = true;
    }
    else
    {
      if (spaceFound)
      {
        hasil2->TabMASUKANFILE[b] = masukanFile.TabMASUKANFILE[i];
        hasil2->Length += 1;
        b++;
      }
      else
      {
        hasil1->TabMASUKANFILE[a] = masukanFile.TabMASUKANFILE[i];
        hasil1->Length += 1;
        a++;
      }
    }
  }
  (*neg) = isNeg;
}

// membaca balasan.config
// status: done?
void bacaBalasan(MASUKAN namaFile)
{
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile, namaFile, 3);
  int n;
  n = masukanFileToInt(masukanFile);

  int i;
  for (i = 0; i < n; i++)
  {

    bacaLanjutFile(&masukanFile);
    int id;
    id = masukanFileToInt(masukanFile);

    bacaLanjutFile(&masukanFile);
    int m;
    m = masukanFileToInt(masukanFile);

    int j;
    for (j = 0; j < m; j++)
    {
      bacaLanjutFile(&masukanFile);
      // displayMASUKANFILE(masukanFile);
      // parent, id balasan
      MASUKANFILE mP, mQ;
      boolean neg;
      splitMasukanFileJadi2(masukanFile, &mP, &mQ, &neg);
      // displayMASUKANFILE(mP);
      // displayMASUKANFILE(mQ);
      int p, q;
      p = 0;
      q = 0;
      p = masukanFileToInt(mP);
      q = masukanFileToInt(mQ);
      if (neg)
      {
        p *= -1;
      }


      // text
      bacaLanjutFile(&masukanFile);
      char *text = MASUKANToStr(masukanFileToMasukan(masukanFile));

      // author
      bacaLanjutFile(&masukanFile);
      // displayMASUKANFILE(masukanFile);
      MASUKAN tempMasukan;
      tempMasukan = masukanFileToMasukan(masukanFile);

      int idx = 0;
      searchID_Pengguna(tempMasukan, &idx);

      User* author;
      author = &listUser.contents[idx];

      // datetime
      bacaLanjutFile(&masukanFile);
      int HH = charToInt(masukanFile.TabMASUKANFILE[11]) * 10 + charToInt(masukanFile.TabMASUKANFILE[12]);
      int MM = charToInt(masukanFile.TabMASUKANFILE[14]) * 10 + charToInt(masukanFile.TabMASUKANFILE[15]);
      int SS = charToInt(masukanFile.TabMASUKANFILE[17]) * 10 + charToInt(masukanFile.TabMASUKANFILE[18]);
      int DD = charToInt(masukanFile.TabMASUKANFILE[0]) * 10 + charToInt(masukanFile.TabMASUKANFILE[1]);
      int BB = charToInt(masukanFile.TabMASUKANFILE[3]) * 10 + charToInt(masukanFile.TabMASUKANFILE[4]);
      int YYYY = charToInt(masukanFile.TabMASUKANFILE[6]) * 1000 + charToInt(masukanFile.TabMASUKANFILE[7]) * 100 + charToInt(masukanFile.TabMASUKANFILE[8]) * 10 + charToInt(masukanFile.TabMASUKANFILE[9]);
      DATETIME datetime;
      CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);

      Balasan infoBalasan;
      CreateBalasan(&infoBalasan, q, text, author, datetime); // masukan to str
      // CetakDetailBalasan(infoBalasan, false, 0);

      TreeKicauan tempTree = ELMT_LDK(listKicauan, id - 1);
      if (p == -1)
      {
        balasKicauan(tempTree, infoBalasan);
      }
      else
      {
        AddressBalasan balasanNode = getBalasan(tempTree, p);
        balasBalasan(balasanNode, infoBalasan);
      }
    }
  }
}

// membaca pengguna.config
// status: tinggal connectin thread
void bacaUtas(MASUKAN namaFile)
{
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile, namaFile, 5);
  // Banyak utas
  int n;
  // printf("BANYAK UTAS : %d\n", n);
  n = masukanFileToInt(masukanFile);

  int i;
  for (i = 0; i < n; i++)
  {
    // IDKICAUAN
    bacaLanjutFile(&masukanFile);
    int idKicau = masukanFileToInt(masukanFile);
    printf("%d", idKicau);

    // Jumlah sambungan
    bacaLanjutFile(&masukanFile);
    int countSambungan = masukanFileToInt(masukanFile);
    // printf("Jumlah Sambungan: %d\n", countSambungan);

    // Kicauan
    AddressKicauan kicauan = ELMT_LDK(listKicauan, idKicau - 1);

    UTAS utasUtama;
    CreateUtas(&utasUtama, kicauan, i + 1);

    // Loop jumlah sambungan
    int j;
    for (j = 0; j < countSambungan; j++)
    {
      //  Kalimat sambubnngan
      bacaLanjutFile(&masukanFile);
      char *text;
      text = MASUKANToStr(masukanFileToMasukan(masukanFile));
      // printf("TEKS: %s\n", text);

      // Author
      bacaLanjutFile(&masukanFile); // just for skipping author karena udah bs ambil author dari kicauan

      // Date
      bacaLanjutFile(&masukanFile);
      int HH = charToInt(masukanFile.TabMASUKANFILE[11]) * 10 + charToInt(masukanFile.TabMASUKANFILE[12]);
      int MM = charToInt(masukanFile.TabMASUKANFILE[14]) * 10 + charToInt(masukanFile.TabMASUKANFILE[15]);
      int SS = charToInt(masukanFile.TabMASUKANFILE[17]) * 10 + charToInt(masukanFile.TabMASUKANFILE[18]);
      int DD = charToInt(masukanFile.TabMASUKANFILE[0]) * 10 + charToInt(masukanFile.TabMASUKANFILE[1]);
      int BB = charToInt(masukanFile.TabMASUKANFILE[3]) * 10 + charToInt(masukanFile.TabMASUKANFILE[4]);
      int YYYY = charToInt(masukanFile.TabMASUKANFILE[6]) * 1000 + charToInt(masukanFile.TabMASUKANFILE[7]) * 100 + charToInt(masukanFile.TabMASUKANFILE[8]) * 10 + charToInt(masukanFile.TabMASUKANFILE[9]);
      DATETIME datetime;
      CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);

      // printf("\n");
      // displayTime(datetime);
      // printf("\n");

      // Insert thread

      insertLastThreadForConfig(utasUtama, text, datetime);
    }
    insertUtas(utasUtama, &listUtas);
  }
}

void MASUKANFILEToStrAndInt(MASUKANFILE masukanFile, MASUKANFILE *nama, int *angka)
{
  int a;
  int idxLastSpace;
  idxLastSpace = -1;
  for (a = 0; a < masukanFile.Length; a++)
  {
    if (masukanFile.TabMASUKANFILE[a] == 32)
    {
      idxLastSpace = a;
    }
  }
  MASUKANFILE masukanAngka; // masukanNama
  // int b;
  // for ( b = 0; b < idxLastSpace + 1; b++)
  // {
  //   masukanNama.Length += 1;
  //   printf("%c\n", masukanFile.TabMASUKANFILE[b]);
  //   masukanNama.TabMASUKANFILE[b] = masukanFile.TabMASUKANFILE[b];
  // }
  int c;
  int idx;
  idx = 0;
  *angka = 0;
  for (c = idxLastSpace + 1; c < masukanFile.Length; c++)
  {
    masukanAngka.Length += 1;
    *angka *= 10;
    *angka += masukanFile.TabMASUKANFILE[c] - 48;
    idx++;
  }
  *nama = masukanFile;
  (*nama).Length = idxLastSpace;
}

void bacaDraf(MASUKAN namaFile)
{
  MASUKANFILE masukanFile;
  bacaAwalFile(&masukanFile, namaFile, 4);
  int n;
  n = masukanFileToInt(masukanFile);
  // printf("ini n %d\n", n);
  int i;
  for (i = 0; i < n; i++)
  {
    bacaLanjutFile(&masukanFile);
    MASUKANFILE tempAuthor;
    // displayMASUKANFILE(masukanFile);
    int count;
    MASUKANFILEToStrAndInt(masukanFile, &tempAuthor, &count);
    char *nama = MASUKANToStr(masukanFileToMasukan(tempAuthor));
    // User author;
    // boolean authorFound;
    // authorFound = false;
    // int b = 0;
    // while(b < listLength(listUser) && !authorFound){
    //   if(USERNAME(listUser,b) == nama){
    //     authorFound = true;
    //     printf("true");
    //     // author = listPengguna.contents[b];
    //   }else{
    //     b ++;
    //   }
    // }
    int b;
    b = 0;
    searchID_Pengguna(masukanFileToMasukan(tempAuthor),&b);
    Stack s;
    CreateEmptyStack(&s);
    int a;
    for (a = 0; a < count; a++)
    {
      bacaLanjutFile(&masukanFile);
      char *text;
      text = MASUKANToStr(masukanFileToMasukan(masukanFile));
      bacaLanjutFile(&masukanFile);
      int HH = charToInt(masukanFile.TabMASUKANFILE[11]) * 10 + charToInt(masukanFile.TabMASUKANFILE[12]);
      int MM = charToInt(masukanFile.TabMASUKANFILE[14]) * 10 + charToInt(masukanFile.TabMASUKANFILE[15]);
      int SS = charToInt(masukanFile.TabMASUKANFILE[17]) * 10 + charToInt(masukanFile.TabMASUKANFILE[18]);
      int DD = charToInt(masukanFile.TabMASUKANFILE[0]) * 10 + charToInt(masukanFile.TabMASUKANFILE[1]);
      int BB = charToInt(masukanFile.TabMASUKANFILE[3]) * 10 + charToInt(masukanFile.TabMASUKANFILE[4]);
      int YYYY = charToInt(masukanFile.TabMASUKANFILE[6]) * 1000 + charToInt(masukanFile.TabMASUKANFILE[7]) * 100 + charToInt(masukanFile.TabMASUKANFILE[8]) * 10 + charToInt(masukanFile.TabMASUKANFILE[9]);
      DATETIME datetime;
      CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);
      Draf tempDraf;
      CreateDraf(&tempDraf, text, datetime);
      PushStack(&s, tempDraf);
    }
    Stack fs;
    CreateEmptyStack(&fs);
    ReverseStack(s,&fs);
    DRAF(listUser,b) = fs;
  }
}