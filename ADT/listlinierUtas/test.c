#include <stdio.h>

#define MAX_CHAR 180

void copyText(char textIn[MAX_CHAR], char textOut[MAX_CHAR])
{
    for (int i = 0; i < 180; i++)
    {
        (textOut)[i] = textIn[i];
    }
}

int main()
{
    char text[MAX_CHAR] = "ADUUUUUU";
    char text2[MAX_CHAR];

    copyText(text, text2);
    printf("%s", text2);
}