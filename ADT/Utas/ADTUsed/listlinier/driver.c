#include <stdio.h>
#include "../datetime/datetime.h"
#include "../listlinier/listlinierForUtas.h"
#include <time.h>


int main()
{
    DATETIME time;
    time = getCurrTime();
    displayTime(time);
}