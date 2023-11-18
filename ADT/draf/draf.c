#include "draf.h"

void createDraf(Draf *Draf, char *text, DATETIME datetime){
  // Datetime
  DATETIME(*Draf) = datetime;

  // Text
  strcpy(TEXT(*Draf), text);
}

//BLM
void prosesDraf(Stack* DrafStack, Draf DrafInfo){
  Draf TempDraf;
  printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
  // case-sensitive commands
  if (isSame(currentWord, "HAPUS;")){
    // jika mengakses Top, dari lihatDraf
    if (DrafInfo == InfoTop(*DrafStack)) {
      Pop(DrafStack, &TempDraf);
    }
    printf("Draf telah berhasil dihapus!");
  } else if (isSame(currentWord, "SIMPAN;")){
    // jika dari buatDraf, butuh fungsi cek kesamaan id
    if (DrafInfo != InfoTop(*DrafStack)) {
      Push(DrafStack, DrafInfo);
    }
    printf("Draf telah berhasil disimpan!");
  } else if (isSame(currentWord, "TERBIT")){
    // buatCuitan
    printf("Selamat! Draf Draf telah diterbitkan!");
  } else if (isSame(currentWord, "KEMBALI;")){
    // do nothing
  } else {
    // handle commands tidak sesuai
  }
}

void tampilkanDraf(Draf DrafInfo){
  // Tanggal
  printf("| ");
  TulisDATETIME(DATETIME(DrafInfo));
  printf("\n");

  // Pesan
  printf("| %s\n", TEXT(DrafInfo));
}

//BLM
void buatDraf(Stack* DrafStack){
    // Validasi sudah masuk atau belum
  // TODO: CONNECT WITH GLOBAL VAR CURRENT USER
  boolean isUserLoggedIn = true;
  if (!isUserLoggedIn)
  {
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // ID Draf paling terakhir
  int idDrafTerakhir = listDinDrafLength(listDraf);
  int idDrafBaru = idDrafTerakhir + 1;

  // Masukan pesan Draf
  printf("Masukkan Draf:\n");
  printf(">> ");
  MASUKAN DrafMasukan;
  baca(&DrafMasukan);
  char *DrafStr = "";
  MASUKANToStr(DrafMasukan, DrafStr);

  // Validasi masukan Draf
  if (isAllSpace(DrafMasukan))
  {
    printf("Draf tidak boleh hanya berisi spasi!\n");
    return;
  }

  // Dapatkan waktu dari library time.h
  DATETIME waktuDraf;
  GetCurrentLocalDATETIME(&waktuDraf);

  // Buat Draf baru
  Draf DrafBaru;

  // TO DO: CONNECT KE GLOBAL VARIABLE CURRENT USER
  CreateDraf(&DrafBaru, idDrafBaru, DrafStr, currentUser, waktuDraf);
  TreeDraf nodeDraf = newNodeDraf(DrafBaru);
  insertLastListDinDraf(&listDraf, nodeDraf);

  // Cetak pesan
  printf("Selamat! Draf telah diterbitkan!\n");
  printf("Detil Draf:\n");
  printDetailDraf(DrafBaru);


  printf("Masukkan draf:\n");
  ADVWORD();
  // Draf.id = incrementor;
  Draf DrafInfo;
  // DrafInfo.id = incrementor;
  DrafInfo.text = currentWord;
  DrafInfo.like = 0;
  // DrafInfo.author = CurrentPengguna;
  // DrafInfo.time = ... // include datetime;
  prosesDraf(DrafStack, DrafInfo);
}

//BLM
void lihatDraf(Stack* DrafStack){
  // Kasus belum login apakah mending dihandle pada program utama
  if (IsEmpty(*DrafStack)){
    // Kasus tidak ada draf
    printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D");
  } else {
    Draf DrafOnTop = InfoTop(*DrafStack);

    printf("Ini draf terakhir anda:\n");
    infoDraf(DrafOnTop);

    // blum ada ubah, jangan pakai ini
    prosesDraf(DrafStack, DrafOnTop);
  }
}