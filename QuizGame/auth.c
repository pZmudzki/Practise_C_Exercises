#include "include/auth.h"

void auth(){
    char correctNickname[20] = "pioter";
    char correctPassword[20] = "zaq1@WSX";

    char nickname[20];
    char password[20];

    printf("Nickname: ");
    scanf("%20s", &nickname);
    printf("Password: ");
    char c;
    while(1){
        if(kbhit()){
            c = getchar();
            putchar("*");
        }
    }
}
