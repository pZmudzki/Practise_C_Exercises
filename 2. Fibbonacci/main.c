#include <stdio.h>
#include <stdlib.h>

int main(){
    int dlugosc;
    printf("Podaj ile liczb z ciagu fibbonacciego wypisac:\n >");
    scanf("%d", &dlugosc);

    int pierwszy = 1;
    int drugi = 1;
    printf("%d, %d,", pierwszy, drugi);

    for(int i = 1; i <= dlugosc - 2; i++){
        int nastepny = pierwszy + drugi;
        printf(" %d,", nastepny);
        pierwszy = drugi;
        drugi = nastepny;
    }
    return 0;
}
