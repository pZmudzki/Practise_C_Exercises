#include <stdio.h>
#include <string.h>

#include "include/auth.h"

#define MAX_NICKNAME_LENGTH 11
#define MAX_PASSWORD_LENGTH 11

void auth(){

    printf("\nuser id: %d\n", loginUser());
    registerUser();


}


int loginUser(){
    int error = 0;

    while(1){
        //system("@cls||clear");

        char nickname[MAX_NICKNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        if(error){
            printf("Wrong nickname or password, try again!\n\n");
        } else {
            printf("Please Log into your account\n\n");
        }

        printf("Nickname: ");
        scanf("%10s", &nickname);

        printf("Password: ");
        scanf("%10s", &password);

        int userID = checkCredentials(nickname, password);
        if(userID != 0){
            return userID;
        }
        error = 1;
    }

    return 0;
}


int registerUser(){
}


int checkCredentials(char nickname[], char password[]){
    FILE *fp;
    int row_length = MAX_NICKNAME_LENGTH + MAX_PASSWORD_LENGTH + 10;
    char row[row_length];
    char *token;

    fp = fopen("./storage/users.csv","r");

    while(!feof(fp)){
        fgets(row, row_length, fp);

        char foundNickname[MAX_NICKNAME_LENGTH];
        char foundPassword[MAX_PASSWORD_LENGTH];
        int id;

        token = strtok(row, ",");
        int column = 0;
        while(token != NULL){
            switch(column){
                case 0:
                    strncpy(foundNickname, token, MAX_NICKNAME_LENGTH);
                    break;
                case 1:
                    strncpy(foundPassword, token, MAX_PASSWORD_LENGTH);
                    break;
                case 2:
                    id = atoi(token);
                    break;
            }

            token = strtok(NULL, ",");
            column++;
        }

        if(strcmp(foundNickname, nickname) == 0 && strcmp(foundPassword, password) == 0){
            return id;
        }
    }

    return 0;
}






