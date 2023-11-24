#include "pcolor.h"
#include <stdio.h>

int main()
{
    printf("(1) Output Merah, (2) Output Hijau, (3) Output Biru\n");
    printf(">> ");
    int color;
    char text;

    scanf("%d", &color);

    while ((getchar()) != '\n')
        ;

    printf("> INPUT CHARACTER > ");
    scanf("%c", &text);

    switch (color)
    {
    case 1:
        print_red(text);
        break;
    case 2:
        print_green(text);
        break;
    case 3:
        print_blue(text);
        break;
    default:
        break;
    }

    return 0;
}
