//
// Created by user12043 on 04.04.2019.
//

#include <parametreIsle.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <birlestir.h>
#include <parcala.h>

void hataliParametre(char *argument, char *hataliParametre) {
    if (hataliParametre != NULL) {
        fprintf(stderr, "invalid param: %s\n\n", hataliParametre);
    }
    fprintf(stderr, "usage: \n"
                    "Compressing\n"
                    "\t%s -b <input_files> -o <output_file>\n"
                    "Extracting\n"
                    "\t%s -a <archive_file> <output_folder>\n", argument, argument);
    exit(EXIT_FAILURE);
}

void parametreIsle(int argCount, char **arguments) {
    if (argCount < 2) {
        hataliParametre(arguments[0], NULL);
    } else if (strcmp(arguments[1], "-b") == 0) {
        // -o parametresine bak
        int oIndis = -1; // -o parametresinin indisini tutacak
        for (int i = 1; i < argCount; ++i) {
            if (strcmp(arguments[i], "-o") == 0) {
                oIndis = i;
                break;
            }
        }

        // -o dan sonrası bossa yine -1 ver
        if (argCount - 1 == oIndis) {
            oIndis = -1;
            argCount--; // parametre sayisini azalt
        }

        if ((oIndis == -1 && argCount > (MAX_INPUT_FILE + 2))
            || (oIndis != -1 && argCount > (MAX_INPUT_FILE + 4))) {
            fprintf(stderr, "Max %d input file allowed!\n", MAX_INPUT_FILE);
            hataliParametre(arguments[0], NULL);
        }

        birlestir(arguments, (oIndis == -1) ? argCount : oIndis);
    } else if (strcmp(arguments[1], "-a") == 0) {
        // -a dan sonra 2 argument daha yoksa hata ver
        if (argCount < 4) {
            hataliParametre(arguments[0], NULL);
        }


        // hata yok devam et
        parcala(arguments[2], arguments[3]);
    } else {
        hataliParametre(arguments[0], arguments[1]);
    }
}
