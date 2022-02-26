/*
 * sec2hms.c - code that takes, as an argument, the number of seconds since midnight, and returns the time of day
 *
 * Noah Robinson
 * Feb 2022
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct time 
{
    int hr ;
    int min ;
    int sec ;
};

/* sec2hms.c - function that takes, as an argument, the number of seconds since midnight, and returns the time of day
 * Note: use real possible seconds so no negatives... only positive ints
 */
struct time sec2hms( int secs )
{
    struct time new;

    new.hr = floor(secs/3600);
    secs = secs - (new.hr * 3600);
    new.min = floor(secs/60);
    secs = secs - (new.min * 60);
    new.sec = secs;

    return new;
}
int main()
{
    int secs = -100;
    struct time data;
    data = sec2hms(secs);
    printf("\nHours: %d\nMins: %d\nSeconds: %d\n", data.hr, data.min, data.sec);

    return 0 ;
}
