/*
* Piotr ¯mudzki
* Zajêcia: 2024.03.06
* Temat: Program obliczajacy wynik dzialania dwoch zmiennych
*/

#include <stdio.h>

// funkcja zwracajaca wartosc dzialania liczb a i b zaleznie od wbranej opcji
int Calculate(int a, int b, int option){
    /*
        1 - addition
        2 - subtraction
        3 - multiplication
        4 - division
    */
    switch(option){
        case 1:
            return a + b;
        case 2:
            return a - b;
        case 3:
            return a * b;
        case 4:
            return a / b;
    }
}

int main(){
    char operators[4] = "+-*/";
    while(1){
        int a, b, option;
        printf("Kalkulator liczb calkowitych:\n\ta [dzialanie] b = wynik\n\nWybierz dzialanie: [1] +  [2] -  [3] *  [4] /\t\t[0] zakoncz\n");
        // pobieranie opcji od uzytkownika
        while(1){
            printf("> ");
            scanf("%d", &option);
            // jezeli wartosc jest zgodna to program opuszcza petle
            if(option==1||option== 2||option== 3||option== 4||option== 0){
                break;
            }
            printf("Podane dzialanie nie istnieje, wybierz jeszcze raz:\n");
        }
        if(option == 0){ // jezeli wybrana opcja jest rowna 0 to program opuszcza petle
            break;
        }
        printf("a = ");
        scanf("%d", &a);
        printf("b = ");
        scanf("%d", &b);
        printf("Obliczenie to:\n%d %c %d = %d\n\n", a, operators[option - 1], b, Calculate(a, b, option));

    }
    return 0;
}
