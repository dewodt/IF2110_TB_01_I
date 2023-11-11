#include "./ADT/masukan/masukan.c"

MASUKAN strToMASUKAN(char str[], int len) {
    int i;
    MASUKAN kata;
    kata.Length = len;
    for (i = 0; i < len; i++)
    {
        kata.TabMASUKAN[i] = str[i];
    }
    return kata;
}

void MASUKANToStr(MASUKAN masukan, char *str) {
    int len = masukan.Length;
    int i;

    for (i = 0; i < len; i++) {
        // printf("%c\n", masukan.TabMASUKAN[i]);
        str[i] = masukan.TabMASUKAN[i];
    }
    str[len] = '\0';

}

int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

boolean isMASUKANEqual(MASUKAN word1, MASUKAN word2) {
    int i;
    if (word1.Length != word2.Length) {
        return false;
    }
    for (i = 0; i < word1.Length; i++)
    {
        if (word1.TabMASUKAN[i] != word2.TabMASUKAN[i]) {
            return false;
        }
    }
    return true;
}

char *strcpy(char *destination, const char *source) {
    char *dest_start = destination;
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return dest_start;
}

int compareString(const char *str1, const char *str2, size_t n) {
    while (n > 0 && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }

    if (n == 0) {
        return 0; // string sama hingga n karakter
    } else {
        return *(unsigned char *)str1 - *(unsigned char *)str2;
    }
}

void toLowerCase(char* str) {
    while (*str) {
        *str = (*str >= 'A' && *str <= 'Z') ? (*str + 32) : *str;
        str++;
    }
}