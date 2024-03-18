#include <stdio.h>
#include <string.h>

#include "include/game.h"
#include "include/menu.h"
#include "include/auth.h"

int main() {
    //game();
    auth();
    while(1){
        switch(menu()){
            case 0:
                game();
                break;
            case 1:
                statistics();
                break;
            case 2:
                printf("\nThanks for playing, see ya!\n");
                return 0;
        }
    }
}
