#include "./ADT/Baca/baca.c"

Word strToWord(char str[], int len) {
    int i;
    Word kata;
    kata.Length = len;
    for (i = 0; i < len; i++)
    {
        kata.TabWord[i] = str[i];
    }
    return kata;
}

void wordToStr(Word word, char *str) {
    int len = word.Length;

    for (int i = 0; i < len; i++) {
        str[i] = word.TabWord[i];
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

boolean isWordEqual(Word word1, Word word2) {
    int i;
    if (word1.Length != word2.Length) {
        return false;
    }
    for (i = 0; i < word1.Length; i++)
    {
        if (word1.TabWord[i] != word2.TabWord[i]) {
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