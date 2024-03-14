#include <stdio.h>
#include <stdlib.h>

#define SMILEY_FACE 1
#define NOTE_ASCII 14
// BORDERS
#define BORDER_HORIZONTAL 205
#define BORDER_VERTICAL 186
#define BORDER_CORNER_LEFT_DOWN 200
#define BORDER_CORNER_LEFT_UP 201
#define BORDER_CORNER_RIGTH_DOWN 188
#define BORDER_CORNER_RIGTH_UP 187

struct matrixConfig{
    // in matrix: 0 - open for user to move, 1 - maze collision border, 2 - finish
    int matrix[25][75];
    int defaultX;
    int defaultY;
    int matrix_height; // -1
    int matrix_width; // -1
};
typedef struct matrixConfig Matrix;

int main(){

    /*
    Matrix defaultMatrix = {{
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}}, 0, 0};
    */

    Matrix mazeMatrix = {{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, 1, 1, 8, 26};

    newGame(mazeMatrix);

    return 0;
}

void newGame(Matrix matrix){
    int gameState, clientX, clientY, deaths;

    gameState = 1;
    deaths = 0;
    // initialize user position
    clientX = matrix.defaultX;
    clientY = matrix.defaultY;

    // initial output
    printOutMatrix(matrix, deaths, clientX, clientY);
    while(gameState == 1){
    restart:
        if(kbhit()){
            system("@cls||clear");
            switch(CheckKey()){
            // keys: up - 72, down - 80, left - 75, right - 77
                case 72:
                    if(clientY == 0){
                        clientY = matrix.matrix_height;
                    } else {
                        clientY--;
                    }
                    break;
                case 80:
                    if(clientY == matrix.matrix_height){
                        clientY = 0;
                    } else {
                        clientY++;
                    }
                    break;
                case 75:
                    if(clientX == 0){
                        clientX = matrix.matrix_width;
                    } else {
                        clientX--;
                    }
                    break;
                case 77:
                    if(clientX == matrix.matrix_width){
                        clientX = 0;
                    } else {
                        clientX++;
                    }
                    break;
            }
            // check if player collided with a border
            if(matrix.matrix[clientY][clientX] == 1){
                deaths++;
                clientX = matrix.defaultX;
                clientY = matrix.defaultY;
            }
            // check if player got to the finish
            if(matrix.matrix[clientY][clientX] == 2){
                if(printOutFinish(deaths) == 0){
                    gameState = 0;
                } else {
                    clientX = matrix.defaultX;
                    clientY = matrix.defaultY;
                    deaths = 0;
                    goto restart;
                }
            } else {
                printOutMatrix(matrix, deaths, clientX, clientY);
            }
        }
    }
}

void printOutMatrix(Matrix matrix, int playerDeaths, int clientX, int clientY){
    printf("Collect %c to pass a maze!\n\n", NOTE_ASCII);

    for(int i = 0; i <= matrix.matrix_height; i++){
        for(int j = 0; j <= matrix.matrix_width; j++){
            if(matrix.matrix[i][j] == 1){
                // logic for placing border symbols
                generateBorders(i, j ,matrix );

            } else if(clientY == i && clientX == j){ // user position displayed as a smiley face
                printf("%c", SMILEY_FACE);

            } else if(matrix.matrix[i][j] == 2){ // maze finish displayed as a note
                printf("%c", NOTE_ASCII);

            } else if(matrix.matrix[i][j] != 3){
                printf(" ");

            }

        }
        printf("\n");
    }

    printf("\nYou died %d times\n", playerDeaths);
}

// logic for placing border symbols
void generateBorders(int i, int j, Matrix matrix){
    int a, x1, x2, y1, y2;
    a = matrix.matrix[i][j];
    /*
    grid visualization

     |     y1
     |  x1 a  x2
   i |     y2
     ----------------
     j

    */

    x1 = matrix.matrix[i][j - 1];
    x2 = matrix.matrix[i][j + 1];
    y1 = matrix.matrix[i - 1][j];
    y2 = matrix.matrix[i + 1][j];

    if(a == y2){
        if(a == y1){ // vertical line
            printf("%c", BORDER_VERTICAL);

        } else if(a == x2 ){ // lines going from bottom to right
             printf("%c", BORDER_CORNER_LEFT_UP);

        } else if(a == x1){ // lines going from bottom to left
            printf("%c", BORDER_CORNER_RIGTH_UP);

        }

    } else if(a == y1){
        if(a == x2){ // lines going from top to rigth
            printf("%c", BORDER_CORNER_LEFT_DOWN);

        } else if(a == x1 ){ // lines going from top to left
            printf("%c", BORDER_CORNER_RIGTH_DOWN);
        }

    } else {
        printf("%c", BORDER_HORIZONTAL);
    }
}

// returns 1 if user wants to play next
// returns 0 if user wants to exit
int printOutFinish(int deaths){
    printf("Huraay! You completed the maze!\nYou died %d times\n To play again press y/Y, otherwise n/N\n", deaths);
    int endState = 1;
    while(endState = 1){
        if(kbhit()){
            switch(CheckKey()){
                case 121: // y
                case 89: // y
                    endState = 0;
                    return 1;
                case 110: // N
                case 78: // n
                    endState = 0;
                    return 0;
            }
        }
    }
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
