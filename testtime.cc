#include <stdio.h>
#include <time.h>

int main()
{
    time_t t = time(NULL);
    struct tm *tm_ptr = localtime(&t);
    char *str_time = asctime(tm_ptr);
    printf("%s\n", str_time);
    return 0;
}