//
// Created by user12043 on 04.04.2019.
//

#include <parametreIsle.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        // TODO birlestir
    } else if (strcmp(arguments[1], "-a") == 0) {
        // TODO parcala
    } else {
        hataliParametre(arguments[0], arguments[1]);
    }
}
