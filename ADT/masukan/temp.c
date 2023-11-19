#include <stdio.h>
#include "masukanFile.h"
#include "masukan.h"
int main() {
    MASUKAN masukan;
    baca(&masukan);
    displayMASUKAN(masukan);
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