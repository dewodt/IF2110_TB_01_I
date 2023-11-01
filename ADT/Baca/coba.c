#include "baca.c"

int main(){
    Word kata;
    STARTWORD();
    kata = currentWord;
    while (!isSame(kata, "TUTUP_PROGRAM")){   
        if(isSame(kata, "DAFTAR;")){
            printf("ini DAFTAR\n");
        }else if(isSame(kata, "\nDAFTAR;")){
            printf("ini DAFTAR;\n");
        }
        STARTWORD   ();
        kata = currentWord;
    
    }
    
    return 0;
}