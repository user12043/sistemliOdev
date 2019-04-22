//
// Created by user12043 on 04.04.2019.

#include <parcala.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

void parcala(char *archiveFile, char *outputFolder) {

    char output[200] = "";
    char fullpath[250] = "";

    DIR *output_dir = opendir(outputFolder);
    if (output_dir == NULL) {
        mkdir(outputFolder, 0752);
    }
    strcat(output, outputFolder);
    strcat(output, "/");


    fp = fopen(archiveFile, "r");

    if (fp == NULL) {
        fprintf(stderr, "this file is not occured!");
        exit(1);
    }

    fread(buffer, 10, BUFFERSIZE, fp);


    char sub[10];
    //ilk 10 bit okunuyor ve bir array a atanıyor     
    for (int i = 0; i < 10; i++) sub[i] = buffer[i];

    int descSize = atoi(sub);//array deki string integer a çevriliyor

    //printf("%d", descSize);

    int partIndex = 0;
    int fileCount = 0;
    int descCursor = 11;
    int objIndex = 0;
    //birinci bölüm | nesnelere atama 
    for (int i = 11; i < descSize; i++) {
        //switch-case 
        if (buffer[i] == '|') {
            fileCount++;
            int partNo = 1;
            partIndex = 0;


            for (int j = descCursor; j < i; j++) {
                if (buffer[j] == ',') {
                    partNo++;
                    j++;
                    partIndex = 0;
                    descCursor++;
                }

                if (partNo == 1) {
                    //name
                    files[objIndex].name[partIndex] = buffer[descCursor];
                    partIndex++;
                    descCursor++;
                } else if (partNo == 2) {
                    //permission
                    files[objIndex].permissions[partIndex] = buffer[descCursor];
                    partIndex++;
                    descCursor++;
                } else if (partNo == 3) {
                    //Size
                    files[objIndex].size[partIndex] = buffer[descCursor];
                    partIndex++;
                    descCursor++;
                }
            }
            descCursor = i + 1;
            objIndex++;
        }
    }

    int sayac = descSize;
    for (int i = 0; i < fileCount; i++) { //text selection part
        for (int j = 0; j < atoi(files[i].size); j++) {
            files[i].text[j] = buffer[j + sayac];
        }
        sayac += atoi(files[i].size);
    }


    for (int i = 0; i < fileCount; i++) {

        // printf("name: %s   Permission: %s   Size: %s\n Text: %s \n\n", files[i].name, files[i].permissions, files[i].size, files[i].text);

        sizes[i] = atoi(files[i].size);
        permisions[i] = strtol(files[i].permissions, NULL, 8);


        strcpy(fullpath, output);
        strcat(fullpath, files[i].name);

        fp2 = open(fullpath, O_CREAT | O_WRONLY | O_TRUNC, permisions[i]);

        if (fp < 0) {
            fprintf(stderr, "Error: %s", strerror(errno));
            exit(1);
        }
        write(fp2, files[i].text, sizes[i]);


        close(fp2);

    }

}
