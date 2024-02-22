#include <stdio.h>
#include <stdlib.h>

int main(){
    int wyrazCiagu;
    printf("Wzor ciagu: an = 2^n * (n + 1)\nPodaj liczbe oznaczajaca wyraz ciagu do oblicznia\n > ");
    scanf("%d", &wyrazCiagu);
    printf("\n Wyraz ciagu a%d: %d", wyrazCiagu, obliczanieWyrazuCiagu(wyrazCiagu));
    return 0;
}

int obliczanieWyrazuCiagu(int wyrazCiagu){
    int result = aToThePowerOfB(2, wyrazCiagu) * (wyrazCiagu + 1);
    return result;
}

int aToThePowerOfB(int a, int b){
    int powerResult = a;
    for(int i = 1; i < b; i++){
        powerResult = powerResult * a;
    };
    return powerResult;
}
