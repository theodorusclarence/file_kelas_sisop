#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Size 50

int main() {
    time_t t;
    struct tm *tmp;
    char MY_TIME[Size];
    time(&t);

    // localtime() uses the time pointed by t ,
    // to fill a tm structure with the
    // values that represent the
    // corresponding local time.

    tmp = localtime(&t);

    // using strftime to display time
    strftime(MY_TIME, sizeof(MY_TIME), "%d-%m-%Y_%H:%M:%S", tmp);

    printf("Formatted date & time : %s\n", MY_TIME);

    // printf("hi");

    char dir[100] = "/home/clarence/file_kelas_sisop/modul-1/";
    strcat(dir, MY_TIME);
    printf("%s", dir);

    return (0);
}