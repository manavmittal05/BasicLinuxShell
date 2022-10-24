#include <stdio.h>
#include <string.h>


int main(int argc, char** argv){
    FILE *fileptr = fopen(argv[1], "r");
    if(fileptr == NULL){
        printf("File doesn't exist at the specified path!\n");
    }
    else{

        if(argv[2] == NULL){
            while(!feof(fileptr)){
                char c = fgetc(fileptr);
                if(c != '\n' && c!= EOF){
                    printf("%c", c);
                }
                else{
                    printf("\n");
                }
            }
        }


        else if(strcmp(argv[2], "-E") == 0){
            while(!feof(fileptr)){
                char c = fgetc(fileptr);
                if(c != '\n' && c!= EOF){
                    printf("%c", c);
                }
                else if(c == '\n'){
                    printf("$\n");
                }
            }
        }
        
        else{
            printf("Invalid Command!");
        }
        fclose(fileptr);
    }
    return 0;
}