#include <stdio.h>
#include <stdlib.h>

int main(){
    int matrix[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int clientX, clientY;
    clientX = clientY = 0;

    // initial output
    outputMatrix(matrix, clientX, clientY);


    while(1){
        if(kbhit()){
            system("@cls||clear");
            switch(CheckKey()){
            // keys: up - 72, down - 80, left - 75, right - 77
                case 72:
                    if(clientY == 0){
                        clientY = 8;
                    } else {
                        clientY--;
                    }
                    break;
                case 80:
                    if(clientY == 8){
                        clientY = 0;
                    } else {
                        clientY++;
                    }
                    break;
                case 75:
                    if(clientX == 0){
                        clientX = 8;
                    } else {
                        clientX--;
                    }
                    break;
                case 77:
                    if(clientX == 8){
                        clientX = 0;
                    } else {
                        clientX++;
                    }
                    break;
            }
            outputMatrix(matrix, clientX, clientY);
        }
    }
    return 0;
}

void outputMatrix(int matrix[9][9], int x, int y){
    for(int i = 0; i <= 8; i++){
        for(int j = 0; j <= 8; j++){
            if(y == i && x == j){
                printf(" %s ", "@");
            } else {
                printf(" %s ", ".");
            }
        }
        printf("\n");
    }
    printf("\nX: %d\nY: %d\n", x, y);
}

int CheckKey(){
    int key;
    if(kbhit()){
        key = getch();
        if(key == 224){
            do{
                key = getch();
            } while(key == 224);
            return key;
        }
    }
}
