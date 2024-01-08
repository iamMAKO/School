#include <stdio.h>

int main() {
    char *filename = "dataf.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Error: could not open file %s", filename);
        return 1;
    }
    printf("File found opening...\n");

    double n;
    double sum = 0.0;
    int count = 0;
    int uzcount = 0;

    while (fscanf(fp, "%lf", &n) == 1){
        if (n > 0) {
            count++;
            sum += n;
        } else
            uzcount++;
    }

    if (uzcount > 0) printf("Found %d bellow zero score in %s i do not count with this number/s\n", uzcount, filename);

    if (count > 0) {
        double average = sum / count;
        printf("average of scores in file %s is: %.2f", filename, average);
    } else
        printf("No scores found in file %s\n", filename);

    fclose(fp);

    return 0;
}
