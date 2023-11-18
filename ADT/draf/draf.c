#include "draf.h"
#include "wordmachine.h"

// Datatype Draf = ADT Kicauan
typedef struct {
  int id; // auto-increment mulai 1
  Word text; // max: 280 char
  int like; // draf reload to 0 or sesuai kicauan sebelumnya?
  // Pengguna author;
  // Time datetime;
} Draf;

void prosesDraf(Stack* DrafStack, Draf DrafInfo){
  Draf TempDraf;
  printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
  // switch (currentWord)
  // case-sensitive commands
  // paksain dulu
  Word Hapus; Hapus.Length = 5;
  Word Simpan; Simpan.Length = 6;
  Word Terbit; Terbit.Length = 6;
  Word Kembali; Kembali.Length = 7;
  if (areSameWords(currentWord, Hapus)){
    // jika mengakses Top, dari lihatDraf
    if (DrafInfo == InfoTop(*DrafStack)) {
      Pop(DrafStack, &TempDraf);
    }
    printf("Draf telah berhasil dihapus!");
  } else if (areSameWords(currentWord, Simpan)){
    // jika dari buatDraf, butuh fungsi cek kesamaan id
    if (DrafInfo != InfoTop(*DrafStack)) {
      Push(DrafStack, DrafInfo);
    }
    printf("Draf telah berhasil disimpan!");
  } else if (areSameWords(currentWord, Terbit)){
    // buatCuitan
    printf("Selamat! Draf kicauan telah diterbitkan!");
  } else if (areSameWords(currentWord, Kembali)){
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