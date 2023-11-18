#include "draf.h"


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
    printf("Selamat! Draf kicauan telah diterbitkan!");
  } else if (isSame(currentWord, "KEMBALI;")){
    // do nothing
  } else {
    // handle commands tidak sesuai
  }
}

void infoDraf(Draf DrafInfo){
  printf("Ini draf terakhir anda:");
  // printDatetime();
  // printText();
}

void buatDraf(Stack* DrafStack){
  printf(">> ");
  ADVWORD();
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

void lihatDraf(Stack* DrafStack){
  printf(">> ");
  ADVWORD();
  if (IsEmpty(*DrafStack)){
    printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D");
  } else {
    Draf DrafOnTop = InfoTop(*DrafStack);
    infoDraf(DrafOnTop);
    prosesDraf(DrafStack, DrafOnTop);
  }
}