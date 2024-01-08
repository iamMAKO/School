#include <stdio.h>
#include <stdlib.h>

// Funkcia na zistenie počtu znakov ("čísel") v súbore
int pocet_slov(FILE* subor) {
    int count = 0;
    int number;
    while (fscanf(subor, "%d", &number) == 1) {
        count++;
    }
    rewind(subor); // Vráti ukazovateľ v súbore na začiatok
    return count;
}

// Funkcia na alokáciu dynamického poľa na základe počtu slov
int* alokuj_pole(int pocet_slov) {
    return (int*)malloc(pocet_slov * sizeof(int));
}

// Funkcia na načítanie textu zo súboru do poľa
void load(FILE* subor, int* text, int pocet_slov) {
    for (int i = 0; i < pocet_slov; i++) {
        fscanf(subor, "%d", &text[i]);
    }
}

// Funkcia preloženia textu pomocou kľúča a zápis do súboru
void preloz(int kluc[], int *text, int pocet, FILE* out) {
    for (int i = 0; i < pocet; i++) {
        fprintf(out, "%c", kluc[text[i]]);
    }
}

int main() {
    //otvrim si subory
    FILE *textFile = fopen("text.txt", "r");
    FILE *keyFile = fopen("kluc.txt", "r");
    FILE *translatedFile = fopen("preklad.txt", "w");

    //zistim ci sa podarilo vsetky subory otvorit
    if (textFile == NULL || keyFile == NULL || translatedFile == NULL) {
        perror("Chyba pri otváraní súborov");
        return -1;
    }

    //ulozim si di premennych pocet znakov a alokujem si pole
    int pocet = pocet_slov(textFile);
    int *text = alokuj_pole(pocet);

    //zistim ci sa mi podarilo alkovoat pole
    if (text == NULL) {
        printf("Chyba pri alokácii pamäti");
        fclose(textFile);
        fclose(keyFile);
        fclose(translatedFile);
        return -1;
    }

    //nacitam si vsetky znaky do pola
    load(textFile, text, pocet);

    int kluc[26];

    int key;
    char letter;
    while (fscanf(keyFile, "%d %c\n", &key, &letter) == 2) {
        kluc[key] = letter;
    }

    preloz(kluc, text, pocet, translatedFile);

    fclose(textFile);
    fclose(keyFile);
    fclose(translatedFile);

    free(text); // Uvoľníme alokovanú pamäť

    printf("Preklad bol úspešne dokončený. Výsledok je v súbore 'preklad.txt'\n");
    return 0;
}