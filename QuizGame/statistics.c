#include <stdio.h>
#include <stdlib.h>

#include "include/statistics.h"

void statistics(int userID){
    system("@cls||clear"); // initial console clear to prevent colliding with another locations

    int gamesCount = 0, rightAnswerCount = 0, wrongAnswerCount = 0;

    getStatsFromStorage(userID, &gamesCount, &rightAnswerCount, &wrongAnswerCount);

    printf("Games played: %d\nRight answers: %.1f %%\nWrong answers: %.1f %%\n\nPress ANY key to go back to Menu\n", gamesCount, ((float)rightAnswerCount / ((float)gamesCount * 10)) * 100,((float) wrongAnswerCount / ((float) gamesCount * 10)) * 100);

    while(1){
        if(kbhit()){
            break;
        }
    }
}

int getStatsFromStorage(int userID, int *gamesCount, int *rightAnswerCount, int *wrongAnswerCount){
    FILE *fp;
    char row[10];
    char *token;

    fp = fopen("./storage/games.csv","r");

    // row = game id, user id, right ans, wrong ans
    while(!feof(fp)){
        fgets(row, 10, fp);

        token = strtok(row, ",");

        // curr row
        int rightAns, wrongAns, user;
        int column = 0;

        while(token != NULL){
            switch(column){
                case 1:
                    user = atoi(token);
                    break;
                case 2:
                    rightAns = atoi(token);
                    break;
                case 3:
                    wrongAns = atoi(token);
                    break;
            }

            token = strtok(NULL, ",");
            column++;
        }

        if(user == userID){
            *gamesCount += 1;
            *rightAnswerCount += rightAns;
            *wrongAnswerCount += wrongAns;
        }
    }

    fclose(fp);
    return 0;
}
