#include <stdio.h>
#include <string.h>

struct question{  // structure for question
    char question[50];
    char answers[4][50];
    int rightAnswer; // idx of answers arr
};
typedef struct question Question;

int main() {
    //initialize questions
    Question question1 = {"What is the capital of Poland?", {"Gdansk", "Warsaw", "Berlin", "Paris"}, 1};
    Question question2 = {"Which number is equal to dozen?", {"10", "50", "11", "12"}, 3};
    Question question3 = {"Which planet in our solar system has the most moons?", {"Mars", "Saturn", "Jupiter", "Neptun"}, 3};
    Question question4 = {"What is the world's largest ocean?", {"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"}, 2};

    Question questions[] = {question1, question2, question3, question4};

    // round - variable keeping track of a round, round 0 is the first round
    // rightAns, wrongAns - variables keeping track of bad and good answers
    // gameStarted - 1 = game is on, 0 = game has ended
    // currSelected - keeps the value of currently selected answer
    int round, maxRounds, currSelected, rightAns, wrongAns, gameStarted;

    round = 0;
    maxRounds = sizeof(questions) / sizeof(questions[0]);
    rightAns = wrongAns = 0;
    gameStarted = 1;

    currSelected = 0;

    start: // goto pointer

    OutputOptions(currSelected, questions[round]); // output first question

    while (gameStarted == 1) {
        if (kbhit()) {
            int pressed_key = CheckKey(); // check what key has been pressed
            switch(pressed_key){
                case 0: // up key
                    if(currSelected > 0){
                        currSelected--;
                    }
                    break;
                case 1: // down key
                    if(currSelected < 3){
                        currSelected++;
                    }
                    break;
                case 2: // enter key
                    if(questions[round].rightAnswer == currSelected){
                        rightAns++;
                    } else {
                        wrongAns++;
                    }
                    round++;
                    break;
            }
            system("@cls||clear"); // clean console
            if(round == maxRounds){
                gameStarted = 0;
            } else {
                OutputOptions(currSelected, questions[round]); // if game is on display options after each key press
            }
        }
    }
    // output ending screen with an option to restart
    if(OutputEnd(rightAns, wrongAns) == 1){
        round = 0;
        rightAns = wrongAns = 0;
        gameStarted = 1;
        system("@cls||clear");
        goto start;
    }
}

//function for displaying options and add > to option that user is pointing to
void OutputOptions(int selected, Question q){
    char options[] = "abcd";
    printf("%s\n", q.question);
    for(int i = 0; i <= 3; i++){ // list options
        if(selected == i){
            printf("> %c. %s\n", options[i], q.answers[i]);
        } else {
            printf("  %c. %s\n", options[i], q.answers[i]);
        }
    }
}

// function displaying endgame screen with an option to restart it
int OutputEnd(int rigth, int wrong){
    char restart; // for input value of y/Y or n/N
    printf("Rigth answers: %d\nWrong answers: %d\n\nWanna play next game? (y/n): ", rigth, wrong);
    scanf("%c", &restart);
    int helper = getchar(); // this clause protects from skipping scanf
    if(restart == 89 || restart == 121){
        return 1; // means restart
    } else {
        printf("\nThanks for playing!");
        return 0; // end game
    }
}

//function returning which key has been pressed
int CheckKey(void) {
    // 0 = up
    // 1 = down
    // 2 = enter
int key;
if (kbhit()) {
    key=getch();
    if(key == 13){
        return 2;
    }
    if (key == 224) {
        do {
            key=getch();
        } while(key==224);
        switch (key) {
            case 72:
                return 0;
                break;
            case 80:
                return 1;
                break;
        }
    }
}
}
