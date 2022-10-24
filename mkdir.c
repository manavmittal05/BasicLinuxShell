#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char** argv){
    char* dir_name = argv[1];

    if(argv[2] == NULL){
        mkdir(dir_name, 0777);
        return 0;
    }
    else if(strcmp(argv[2], "--verbose") == 0){
        mkdir(dir_name, 0777);
        printf("mkdir: created directory '%s'\n", dir_name);
        return 0;
    }
    else{
        printf("Invalid use options: %s option is not found!\n", argv[2]);
        return 0;
    }
}