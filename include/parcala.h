//
// Created by user12043 on 31.03.2019.
//

#ifndef SISTEMLIODEV_PARCALA_H
#define SISTEMLIODEV_PARCALA_H

#include "stdlib.h"
#include "stdio.h"
#define BUFFERSIZE 6553600 + 500 //32 file * 200 mb + first part approximately

FILE *fp;//file pointer for arshive file
char buffer[BUFFERSIZE]; //the buffer for arshive file 
int  fp2; // file pointer for extracting files
int sizes[204800];//file sizes integer max 200 mb
int permisions[5];//permissions octal array 
char fullpath[250] = "";
struct file
{
    char name[100];
    char permissions[5];
    char size[204800];
    char text[204800];
    
}files[32];//max 32 file
void parcala(char *archiveFile, char *outputFolder);

#endif //SISTEMLIODEV_PARCALA_H
