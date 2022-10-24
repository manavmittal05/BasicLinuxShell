#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv){
    DIR* directory;
    struct dirent *file;
    char path[PATH_MAX];
    directory = opendir(getcwd(path, PATH_MAX));

    if(argv[1] == NULL){
        while(file = readdir(directory)){
            if(file->d_name[0] != '.'){
                printf("%s\n", file->d_name);
            }
        }
        return 0;
    }
    else if(strcmp(argv[1], "-a") == 0){
        while(file = readdir(directory)){
            printf("%s\n", file->d_name);
        }
        return 0;

    }
    else{
        printf("INVALID COMMAND!\n");
        return 0;
    }
}