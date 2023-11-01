#include "../wordmachine/wordmachine.c"
#include "../charmachine/charmachine.c"
#include "../boolean.h"

void baca(Word *kata){
    /* 
    // Menerima input string dan disimpan ke dalam string dengan format:
    - Spasi awal akan diingnore
    - Char yang akan disimpan adalah karakter pertama bukan spasi hingga karakter sebelum ;
    - Mungkin char pertama diisi "\n" karena ketika ngebaca input menggunakan enter
    
    Contoh:
    "Tuan;" -> [T, u, a, n]
    "Tuan;" -> [\n, T, u, a, n]
    "   Tuan;" -> [\n, T, u, a, n]
    "Tuan Hak;" -> [\n, T, u, a, n,  , H, a, k]
    "   Tuan Hak;" -> [\n, T, u, a, n,  , H, a, k]
    */
    printf(">>");
    STARTWORD();
    *kata = currentWord;
}

boolean isSame(Word kata1, char fungsi[]){
    // Membandingkan Kata dengan array of char
    boolean hasil;
    hasil = true;
    int i;
    i = 0;
    while ((i < kata1.Length) && hasil)
    {
        if(kata1.TabWord[i] != fungsi[i]){
            hasil = false;
        }
        i ++;
    }
    return hasil;
}

void displayKata(Word kata){
    // Menampilkan isi kata
    int i;
    for ( i = 0; i < kata.Length; i++)
    {
        printf("%c,", kata.TabWord[i]);
    }
    
}