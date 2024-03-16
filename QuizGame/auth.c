#include <stdio.h>
#include <string.h>

#include "include/auth.h"

void auth(){
    int error;
    char errorMessage[] = "Wrong nickname or password, try again!";
    char correctNickname[10] = "pioter";
    char correctPassword[10] = "zaq1@WSX";

    while(1){
        system("@cls||clear");

        char nickname[10];
        char password[10];
        if(error){
            printf("Wrong nickname or password, try again!\n\n");
        } else {
            printf("Please Log into your account\n\n");
        }
        printf("Nickname: ");
        gets(nickname);
        printf("Password: ");
        gets(password);
        if(strcmp(correctNickname, nickname) == 0 && strcmp(correctPassword, password) == 0){
            break;
        }
        error = 1;
    }

}
