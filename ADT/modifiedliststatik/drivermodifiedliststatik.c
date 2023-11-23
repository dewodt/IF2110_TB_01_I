#include <stdio.h>
#include "modifiedliststatik.h"

int main() {
    ListStatik userList;
    CreateListStatik(&userList);
    printf("Initial userlist: ");
    printList(&userList);
    printf("\n");

    boolean private = false;
    Matrix profile;
    printf("Masukkan foto profile: \n");
    readMatrixMasukan(&profile, 5, 10);

    strcpy(ELMT(userList, 0).username, "USER 1");
    SetBio(&userList, 0, "BIO");
    SetWeton(&userList, 0, "WETON");
    SetProfile(&userList, 0, &profile);
    SetIsPrivate(&userList, 0, &private);

    printf("Userlist now: ");
    printList(&userList);

    printf("\n");
    printf("User 1's bio: %s\n", ELMT(userList, 0).bio);
    printf("User 1's weton: %s\n", ELMT(userList, 0).weton);
    printf("User 1's profile: \n");
    displayProfile(ELMT(userList, 0).profile);

    return 0;
}

// RUN DALAM FOLDER MODIFIEDLISTSTATIK
// gcc drivermodifiedliststatik.c ../modifiedliststatik/modifiedliststatik.c ../modifiedmatrix/modifiedmatrix.c ../masukan/masukan.c ../charmachine/charmachine.c ../pcolor/pcolor.c ../stackdraf/stackdraf.c