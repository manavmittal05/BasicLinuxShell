#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>


#define COMMAND_SIZE 1024
#define input(command) fgets(command, COMMAND_SIZE, stdin)

void getTokens(char* s, char** tokens){
    int i = 0;
    char* token = strtok(s, " ");
    while(token != NULL){
        tokens[i] = token;
        i += 1;
        token = strtok(NULL, " ");
    }
    tokens[i-1][strlen(tokens[i-1])-1] = '\0';
    tokens[i] = '\0';
}

int main(){

    while(1){
        printf("shell@manavmittal2021538~:$");
        char* command = (char*)malloc(COMMAND_SIZE);
        input(command);

        char** tokens = (char**)malloc(COMMAND_SIZE);
        getTokens(command, tokens);

        pid_t pid, rwait;
        int exit_status;
        if(strcmp(tokens[0], "cd") == 0){
            if(strcmp(tokens[1], "--help") == 0){
                char str[] = "cd: cd [dir]\nChange the shell working directory.\nechos 'Invalid Directory name' if the directory os not found at the specified path.\n";
                printf("\n%s\n", str);
            }
            else if(strcmp(tokens[2], "\0") == 0){
                int check = chdir(tokens[1]);
                if(check == -1){
                    printf("Invalid Directory name!\n");
                }         
            }
        }
        else if(strcmp(tokens[0], "ls") == 0){
            pid = fork();
            if(pid < 0){
                printf("FATAL ERROR: Fork Fialed in 'ls'!\n");
            }
            else if(pid == 0){
                execv("/home/manav/Desktop/LinuxShell in C/ls", tokens);
            }
            else{
                rwait = wait(&exit_status);
                if(rwait < 0){
                    printf("ERROR Occurred in wait of ls!");
                }
            }
        }
        else if(strcmp(tokens[0], "echo") == 0){

            if(strcmp(tokens[1], "-n") == 0){
                int i = 2;
                while(strcmp(tokens[i],"\0") != 0){
                    printf("%s ", tokens[i]);
                    i += 1;
                }
            }
            else{
                int i = 1;
                while(strcmp(tokens[i],"\0") != 0){
                    printf("%s ", tokens[i]);
                    i += 1;
                }
                printf("\n");
            }
        }
        else if(strcmp(tokens[0], "mkdir") == 0){
            pid = fork();
            if(pid < 0){
                printf("FATAL ERROR: Fork Fialed in 'echo'!\n");
            }
            else if(pid == 0){
                execv("/home/manav/Desktop/LinuxShell in C/mkdir", tokens);
            }
            else{
                rwait = wait(&exit_status);
                if(rwait < 0){
                    printf("ERROR Occurred in wait of mkdir!");
                }
            }
        }
        else if(strcmp(tokens[0], "date") == 0){
            pid = fork();
            if(pid < 0){
                printf("FATAL ERROR: Fork Fialed in 'date'!\n");
            }
            else if(pid == 0){
                execv("/home/manav/Desktop/LinuxShell in C/date", tokens);
            }
            else{
                rwait = wait(&exit_status);
                if(rwait < 0){
                    printf("ERROR Occurred in wait of date!");
                }
            }
        }
        else if(strcmp(tokens[0], "cat") == 0){
            pid = fork();
            if(pid < 0){
                printf("FATAL ERROR: Fork Fialed in 'cat'!\n");
            }
            else if(pid == 0){
                execv("/home/manav/Desktop/LinuxShell in C/cat", tokens);
            }
            else{
                rwait = wait(&exit_status);
                if(rwait < 0){
                    printf("ERROR Occurred in wait of cat!");
                }
            }
        }
        else if(strcmp(tokens[0], "rm") == 0){
            pid = fork();
            if(pid < 0){
                printf("FATAL ERROR: Fork Fialed in 'rm'!\n");
            }
            else if(pid == 0){
                execv("/home/manav/Desktop/LinuxShell in C/rm", tokens);
            }
            else{
                rwait = wait(&exit_status);
                if(rwait < 0){
                    printf("ERROR Occurred in wait of rm!");
                }
            }
        }

        else if(strcmp(tokens[0], "pwd") == 0){
            if(strcmp(tokens[1], "--help") == 0){
                printf("pwd: pwd\nPrint the name of the current working directory.\n");
            }
            else{
                char *buff = NULL;
                printf("%s\n", getcwd(buff, PATH_MAX));
            }
        }
    }
}