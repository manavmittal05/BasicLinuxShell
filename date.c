#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char** argv){

    char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    char* month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};


    time_t t = time(NULL);
    struct tm  *time;

    if(argv[1] == NULL){
        time = localtime(&t);
    }
    else if(strcmp(argv[1], "-u") == 0){
        time = gmtime(&t);
    }
    else{
        printf("Invalid Command!\n");
        return 0;
    }
    printf("%s %.2d %s %.2d:%.2d:%.2d %s %d\n",days[time->tm_wday], time->tm_mday, month[time->tm_mon], time->tm_hour, time->tm_min, time->tm_sec, time->tm_zone, time->tm_year+1900);
    return 0;
}