#include "include/CheckKey.h"

//function returning key code that has been pressed
int CheckKey() {
    int key;
    if (kbhit()) {
        key=getch();
        if (key == 224) {
            do {
                key=getch();
            } while(key==224);

            return key;
        }
    }
}
