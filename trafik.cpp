
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100
int main() {
    FILE* file;
    int kod, inputCode;
    char sehir[30];
    int found = 0;

    file = fopen("trafikkodlari.txt", "r");
    if (file == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }

    printf("Bir trafik kodu girin: ");
    if (scanf("%d", &inputCode) != 1) {
        printf("Geçersiz Giriş!\n");
        return 1;
    }
    //rewind(file);  // Dosyanın başa sarıldığından emin ol
    while (fscanf(file, "%d %29[^\n]", &kod, sehir) != EOF) {
        if (kod == inputCode) {
            printf("%s Doğu Karadeniz bölgesinde yer alır.\n", sehir);
            found = 1;
            break;
        }
    }

    if (!found) printf("Hatalı Kod Girdiniz!\n");

    fclose(file);
    return 0;
}
