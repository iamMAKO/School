#include <stdio.h>

int main() {
    double suma, splatka;

    printf("Zadajte vysku pozicky: ");
    scanf("%lf", &suma);

    if (suma < 20000) {
        splatka = 0.01 * suma;
        printf("Pri schvaleni pozicky %.2lfEur je vasa prva splatka %.2lfEur.", suma, splatka);
        return 0;
    } else if (suma >= 20000 && suma < 50000){
        splatka = (suma - 20000) * 0.02 + 200;
        printf("Pri schvaleni pozicky %.2lfEur je vasa prva splatka %.2lfEur.", suma, splatka);
        return 0;
    } else if (suma >= 50000 && suma <= 150000){
        splatka = (suma - 50000) * 0.03 + 800;
        printf("Pri schvaleni pozicky %.2lfEur je vasa prva splatka %.2lfEur.", suma, splatka);
        return 0;
    } else {
        printf("Pozicku nad 150 000Eur neposkytujeme");
        return 0;
    }
}
