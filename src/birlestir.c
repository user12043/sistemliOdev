//
// Created by user12043 on 04.04.2019.
//

#include <birlestir.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

// ismin icinde "/" karakteri varsa asil ismi al
void sadeIsimAl(char *isim, char *yeniIsim) {
    int index = -1;
    int i;
    for (i = strlen(isim); i > -1; --i) {
        if (isim[i] == '/') {
            index = i;
            break;
        }
    }

    if (index != -1) {
        strcpy(yeniIsim, &isim[index + 1]);
    }
}

void birlestir(char **arguments, int oIndis) {
    char *cikisDosyasiIsmi;
    if (arguments[oIndis + 1] != NULL) {
        cikisDosyasiIsmi = arguments[oIndis + 1];
    } else {
        cikisDosyasiIsmi = DEFAULT_OUT_FILE_NAME;
    }
    Girdiler g;
    int i;
    for (i = 0; i + 2 < oIndis; ++i) {
        g.dosya_isimleri[i] = arguments[i + 2];
        struct stat s;
        stat(arguments[i + 2], &s);
        g.dosya_boyutlari[i] = s.st_size;
        g.dosya_izinleri[i] = s.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    }

    // cikti dosyasini ac
    FILE *cikis = fopen(cikisDosyasiIsmi, "w");
    if (cikis == NULL) {
        fprintf(stderr, "could not open output file: %s\n", cikisDosyasiIsmi);
        exit(1);
    }
    // i tane dosya var
    // ilk bolumu yaz
    fseek(cikis, 10, SEEK_SET);
    for (int j = 0; j < i; ++j) {
        char dosyaIsmi[strlen(g.dosya_isimleri[j])];
        sadeIsimAl(g.dosya_isimleri[j], dosyaIsmi);
        fprintf(cikis, "|%s,%o,%lu", dosyaIsmi, g.dosya_izinleri[j], g.dosya_boyutlari[j]);
    }
    fprintf(cikis, "|");
    // ilk bolum boyutunu yaz
    int ilkBolumBoyutu = ftell(cikis);
    fseek(cikis, 0, SEEK_SET);
    fprintf(cikis, "%0*d", 10, ilkBolumBoyutu);

    // dosya iceriklerini yaz
    fseek(cikis, 0, SEEK_END);
    for (int k = 0; k < i; ++k) {
        FILE *dosya = fopen(g.dosya_isimleri[k], "r");
        if (dosya == NULL) {
            fprintf(stderr, "could not open input file: %s\n", g.dosya_isimleri[k]);
            exit(1);
        }
        char ch;
        for (int j = 0; j < g.dosya_boyutlari[k]; ++j) {
            fread(&ch, 1, 1, dosya);
            fwrite(&ch, 1, 1, cikis);
        }
    }
    fclose(cikis);
}
