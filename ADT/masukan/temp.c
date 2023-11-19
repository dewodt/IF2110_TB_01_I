#include <stdio.h>
#include "masukanFile.h"
int main() {

    MASUKANFILE masukanFile;
    bacaAwalFile(&masukanFile);
    displayMASUKANFILE(masukanFile);

    int n;
    n = masukanFileToInt(masukanFile);
    printf("%d\n", n);
    // looping

    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    bacaLanjutFile(&masukanFile);
    displayMASUKANFILE(masukanFile);
    return 0;
}