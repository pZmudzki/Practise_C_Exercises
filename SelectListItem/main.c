#include <stdio.h>

int main() {
    int currSelected = 0;
    PrintOptions(currSelected);
    while (1) {
        if (kbhit()) {
            int pressed_key = CheckKey();
            switch(pressed_key){
            case 1:
                if(currSelected > 0){
                    currSelected--;
                }
                break;
            case 2:
                if(currSelected < 3){
                    currSelected++;
                }
                break;
            }
            system("@cls||clear");
            PrintOptions(currSelected);
        }
    }
}

void PrintOptions(int selected){
    char options[] = "abcd";
    for(int i = 0; i <= 3; i++){
        if(selected == i){
            printf("> %c\n", options[i]);
        } else {
            printf("  %c\n", options[i]);
        }
    }
}


int CheckKey(void) {
    // 1 = up
    // 2 = down
int key;
if (kbhit()) {
    key=getch();
    if (key == 224) {
        do {
            key=getch();
        } while(key==224);
        switch (key) {
            case 72:
                return 1;
                break;
            case 80:
                return 2;
                break;
        }
    }
}
}

