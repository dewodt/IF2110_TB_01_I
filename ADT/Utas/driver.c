#include "./ADTUsed/datetime/datetime.h"
#include "./ADTUsed/time/time.h"
#include <time.h>

#include <stdio.h>

DATETIME getCurrTime()
{
    DATETIME datetime;
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    Year(datetime) = date.tm_year + 1900;
    Month(datetime) = date.tm_mon + 1;
    Day(datetime) = date.tm_mday;
    Hour(Time(datetime)) = date.tm_hour;
    Minute(Time(datetime)) = date.tm_min;
    Second(Time(datetime)) = date.tm_sec;

    return datetime;
}

void displayTime(DATETIME time)
{
    int day, month, year, hour, minute, second;
    day = Day(time);
    month = Month(time);
    year = Year(time);
    hour = Hour(Time(time));
    minute = Minute(Time(time));
    second = Second(Time(time));

    printf("%d/%d/%d %d:%d:%d", day, month, year, hour, minute, second);
}

int main()
{
    DATETIME t = getCurrTime();
    displayTime(t);
}