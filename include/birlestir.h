//
// Created by user12043 on 31.03.2019.
//

#ifndef SISTEMLIODEV_BIRLESTIR_H
#define SISTEMLIODEV_BIRLESTIR_H

#include "parametreIsle.h"

#define DEFAULT_OUT_FILE_NAME "a.sau"
#define SIZE_LIMIT 209715200 // 25MB max size

void birlestir(char **arguments, int oIndis);

typedef struct {
    // dosya bilgilerini tutacak degiskenler
    int dosya_izinleri[MAX_INPUT_FILE];
    unsigned long dosya_boyutlari[MAX_INPUT_FILE];
    char *dosya_isimleri[MAX_INPUT_FILE];
} Girdiler;

#endif //SISTEMLIODEV_BIRLESTIR_H
