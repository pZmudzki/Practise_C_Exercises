#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iloscOcen = 10;
    int iloscOcenNdst = 0;
    float sumaOcen;
    printf("Podaj ilosc ocen: ");
    pobieranie_ilosci: scanf("%d", &iloscOcen);
    if(iloscOcen <= 0){
        printf("Nieprawidlowa ilosc ocen! Podaj ponownie:");
        goto pobieranie_ilosci;
    }
    for(int i = 1; i <= iloscOcen; i++){
        float ocena;
        printf("Ocena nr %d: ", i);
        scanf("%f", &ocena);
        sumaOcen += ocena;
        if(ocena == 2){
            iloscOcenNdst++;
        }
    }
    printf("Ilosc ocen \'ndst\' = %d, srednia z ocen = %.2f \n", iloscOcenNdst, sumaOcen / iloscOcen);
    return 0;
}
