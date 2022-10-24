#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    if(argv[2] == NULL){
        int check = remove(argv[1]);
        if(check != 0){
            printf("file named '%s' doesn't exists!\n", argv[1]);
        }
    }


    else if(strcmp(argv[2], "-i") == 0){
        char confirmation[5];
        printf("Do you really want to delete %s:", argv[1]);
        scanf("%s",confirmation);
        if(strcmp(confirmation, "yes") == 0 || strcmp(confirmation, "y") == 0 || strcmp(confirmation, "YES") == 0 || strcmp(confirmation, "Y") == 0){
            int check = remove(argv[1]);
            if(check != 0){
                printf("file named '%s' doesn't exists!\n", argv[1]);
            }
        }
    }
    
    else{
        printf("Invalid Command!\n");
    }
    return 0;
}