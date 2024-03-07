#include <stdio.h>
#include <stdlib.h>

// funkcja zadeklarowana przed main(), poniewaz gdyby bylo na odwrot to
// main() odwolujac sie do Calculate() domyslnie zalozy, ze zwraca int co
// powoduje niespojnosci typow danych
float Calculate(int a, int b, int option){
    float result;
    switch(option){
        case 1:
            result = a + b;
            break;
        case 2:
            result = a - b;
            break;
        case 3:
            result = (float) a * (float) b;
            break;
        case 4:
            result = (float) a / (float) b;
            break;
    }
    return result;
}


int main(){
    float result;
    int a, b, running, selectedActivity;
    running = 1;
    while(running){
        printf("Wybierz dzialanie: [1] +   [2] -   [3] *   [4] /\t[0] zakoncz\n> ");
        scanf("%d", &selectedActivity);
        printf("%d", selectedActivity);
        if(selectedActivity!= 0){
            a:
            printf("\nPodaj liczbe a: ");
            if(!scanf("%d", &a) != 1){
                goto a;
            }
            b:
            printf("\nPodaj liczbe b: ");
            if(!scanf("%d", &b)){
                goto b;
            }
            result = Calculate(a, b, selectedActivity);
            system("@cls||clear");
            printf("\nWynik dzialania: %.2f\n\n=========================\n\n", result);
        }
    }
    return 0;
}
