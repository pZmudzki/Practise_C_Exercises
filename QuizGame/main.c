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
    Question question5 = {"What is the largest mammal in the world?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 1};
    Question question6 = {"Who wrote \"Romeo and Juliet\"?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "Mark Twain"}, 0};
    Question question7 = {"What is the chemical formula for water?", {"H2O", "CO2", "NaCl", "CH4"}, 0};
    Question question8 = {"What is the largest desert in the world?", {"Sahara Desert", "Gobi Desert", "Antarctica", "Arabian Desert"}, 2};
    Question question9 = {"Which gas do plants primarily use for photosynthesis?", {"Oxygen", "Carbon Dioxide", "Nitrogen", "Hydrogen"}, 1};
    Question question10 = {"Who is known as the father of modern physics?", {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"}, 1};

    Question question11 = {"What is the capital of France?", {"Madrid", "Rome", "Berlin", "Paris"}, 3};
    Question question12 = {"Who wrote the play 'Hamlet'?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "Mark Twain"}, 0};
    Question question13 = {"What is the chemical symbol for iron?", {"Fe", "Ag", "Au", "Hg"}, 0};
    Question question14 = {"Which is the smallest planet in our solar system?", {"Mars", "Venus", "Mercury", "Earth"}, 2};
    Question question15 = {"What is the fastest land animal?", {"Cheetah", "Lion", "Giraffe", "Zebra"}, 0};
    Question question16 = {"Who discovered penicillin?", {"Marie Curie", "Alexander Fleming", "Louis Pasteur", "Robert Koch"}, 1};
    Question question17 = {"What is the currency of Japan?", {"Yuan", "Euro", "Yen", "Dollar"}, 2};
    Question question18 = {"What is the chemical formula for table salt?", {"NaCl", "KCl", "CaCl2", "MgCl2"}, 0};
    Question question19 = {"What is the largest bird in the world?", {"Eagle", "Ostrich", "Albatross", "Condor"}, 1};
    Question question20 = {"Who painted the ceiling of the Sistine Chapel?", {"Leonardo da Vinci", "Raphael", "Donatello", "Michelangelo"}, 3};

    Question question21 = {"What is the boiling point of water in Celsius?", {"100°C", "0°C", "-100°C", "50°C"}, 0};
    Question question22 = {"Who is the author of 'The Great Gatsby'?", {"F. Scott Fitzgerald", "Ernest Hemingway", "Mark Twain", "John Steinbeck"}, 0};
    Question question23 = {"What is the chemical symbol for sodium?", {"So", "Na", "S", "No"}, 1};
    Question question24 = {"Which planet is known as the Red Planet?", {"Mars", "Venus", "Jupiter", "Mercury"}, 0};
    Question question25 = {"What is the largest organ in the human body?", {"Heart", "Liver", "Brain", "Skin"}, 3};
    Question question26 = {"Who developed the theory of relativity?", {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Stephen Hawking"}, 1};
    Question question27 = {"What is the tallest tree species on Earth?", {"Redwood", "Sequoia", "Douglas Fir", "Eucalyptus"}, 0};
    Question question28 = {"What is the chemical formula for methane?", {"CH4", "CO2", "H2O", "NH3"}, 0};
    Question question29 = {"What is the largest reptile in the world?", {"Komodo Dragon", "Alligator", "Crocodile", "Anaconda"}, 1};
    Question question30 = {"Who wrote 'To Kill a Mockingbird'?", {"Harper Lee", "Mark Twain", "Charles Dickens", "F. Scott Fitzgerald"}, 0};

    Question question31 = {"What is the capital of Canada?", {"Ottawa", "Toronto", "Vancouver", "Montreal"}, 0};
    Question question32 = {"Who was the first woman to win a Nobel Prize?", {"Marie Curie", "Rosalind Franklin", "Rita Levi-Montalcini", "Dorothy Hodgkin"}, 0};
    Question question33 = {"What is the chemical symbol for silver?", {"Si", "Sr", "Ag", "Sv"}, 2};
    Question question34 = {"Which is the second largest planet in our solar system?", {"Mars", "Saturn", "Jupiter", "Neptune"}, 2};
    Question question35 = {"What is the hardest natural substance on Earth?", {"Iron", "Gold", "Diamond", "Platinum"}, 2};
    Question question36 = {"Who wrote '1984'?", {"George Orwell", "Aldous Huxley", "Ray Bradbury", "J.R.R. Tolkien"}, 0};
    Question question37 = {"What is the largest flower in the world?", {"Sunflower", "Rose", "Titan Arum", "Lily"}, 2};
    Question question38 = {"What is the chemical formula for hydrogen peroxide?", {"H2O2", "HCl", "NaOH", "NH3"}, 0};
    Question question39 = {"What is the largest fish in the ocean?", {"Great White Shark", "Blue Whale", "Giant Squid", "Whale Shark"}, 3};
    Question question40 = {"Who painted 'Starry Night'?", {"Pablo Picasso", "Vincent van Gogh", "Claude Monet", "Leonardo da Vinci"}, 1};

    Question question41 = {"What is the speed of light in a vacuum?", {"299,792,458 m/s", "300,000,000 m/s", "150,000,000 m/s", "100,000,000 m/s"}, 0};
    Question question42 = {"Who wrote 'Pride and Prejudice'?", {"Emily Bronte", "Jane Austen", "Charlotte Bronte", "Louisa May Alcott"}, 1};
    Question question43 = {"What is the chemical symbol for potassium?", {"K", "Ka", "Po", "Pt"}, 0};
    Question question44 = {"Which is the coldest planet in our solar system?", {"Mars", "Saturn", "Jupiter", "Uranus"}, 3};
    Question question45 = {"What is the smallest bone in the human body?", {"Stapes", "Femur", "Tibia", "Ulna"}, 0};
    Question question46 = {"Who formulated the theory of evolution by natural selection?", {"Isaac Newton", "Charles Darwin", "Gregor Mendel", "Albert Einstein"}, 1};
    Question question47 = {"What is the largest animal on Earth?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 1};
    Question question48 = {"What is the chemical formula for carbon dioxide?", {"CO2", "CH4", "O2", "H2O"}, 0};
    Question question49 = {"What is the fastest bird in the world?", {"Peregrine Falcon", "Swift", "Eagle", "Ostrich"}, 0};
    Question question50 = {"Who wrote 'The Catcher in the Rye'?", {"J.D. Salinger", "F. Scott Fitzgerald", "Ernest Hemingway", "Mark Twain"}, 0};

    Question questions[] = {
        question1,  question2,  question3,  question4,  question5,
        question6,  question7,  question8,  question9,  question10,
        question11, question12, question13, question14, question15,
        question16, question17, question18, question19, question20,
        question21, question22, question23, question24, question25,
        question26, question27, question28, question29, question30,
        question31, question32, question33, question34, question35,
        question36, question37, question38, question39, question40,
        question41, question42, question43, question44, question45,
        question46, question47, question48, question49, question50
    };


    // round - variable keeping track of a round, round 0 is the first round
    // rightAns, wrongAns - variables keeping track of bad and good answers
    // gameStarted - 1 = game is on, 0 = game has ended
    // currSelected - keeps the value of currently selected answer
    int round, maxRounds, currSelected, rightAns, wrongAns, gameStarted;

    start: // goto pointer

    round = 0;
    maxRounds = sizeof(questions) / sizeof(questions[0]);
    rightAns = wrongAns = 0;
    gameStarted = 1;

    currSelected = 0;

    printf("Question %d/%d\n\n", round + 1, maxRounds);
    OutputOptions(currSelected, questions[round]); // output first question

    while (gameStarted == 1) {
        if (kbhit()) { // for each key press render new view
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
                printf("Question %d/%d\n\n", round + 1, maxRounds);
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
        //restart = 0;
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
