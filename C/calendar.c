#include <stdio.h>
#include <stdlib.h>



int main() {
    int rok = 0;
    int zaciatok = 0;
    int dnivMesiaci[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *nazvyMesacov[] = { "Januar", "Februar", "Marec", "April", "Maj", "Jun", "Jul", "August", "September", "Oktober", "November", "December"};
    char *skratkaDna[] = { "P", "U", "S", "S", "P", "S", "N"};

    //zadame rok a overime ci je to cislo ak hej ci je kladne
    printf("Zadaj rok, pre ktory chces kalendar:\n");
    int rokTest = scanf("%d", &rok);
    if(rokTest != 1 || rok < 1) {
        printf("Nespravne zadana hodnota roku");
        exit(0);
    }

    //overime si ci je rok priestupny a prepiseme pocet dni
    if (rok%4 == 0) dnivMesiaci[1] = 29;

    //zadame den overime ci je to cislo ak hej ci je v intervale 1-7
    printf("Zadaj den kedy bude 1.1.:");
    int denTest = scanf("%d", &zaciatok);
    if(denTest != 1 || zaciatok < 1 || zaciatok > 7){
        printf("Nespravne zadana hodnota dna");
        exit(0);
    }

    //vypiseme si rok
    printf("%14d\n", rok);

    //ciklus na vytvorenie kalendara na kazdy mesiac
    for (int mesiac = 0; mesiac <= 11; mesiac++){
        printf("\n%15s\n", nazvyMesacov[mesiac]);

        //vypiseme skratky dni a zalomime za poslednym
        for (int i = 0; i <= 6; ++i) {
            printf("%2s ", skratkaDna[i]);
        }
        printf("\n");

        //vypocitame medzeru na zaciatku mesiaca a vypiseme si ju
        int medzera = 3 * (zaciatok-1);
        for (int i = 0; i < medzera; ++i) {
            printf(" ");
        }

        //vypiseme dni v mesiaci
        for(int denVMesiaci = 1; denVMesiaci <= dnivMesiaci[mesiac]; denVMesiaci++){
            printf("%2d ", denVMesiaci);

            //enter na konci riadku pri 7 dni alebo na konci mesiaca
            if ((zaciatok + denVMesiaci - 1) % 7 == 0 || denVMesiaci == dnivMesiaci[mesiac]) printf("\n");
        }

        //vyratame zaciatok dalsieho mesiaca
        zaciatok = ((zaciatok + dnivMesiaci[mesiac]-1) % 7) + 1;
    }

}
