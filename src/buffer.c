
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define BUFFERSIZE 2000000000
FILE *fp;
char buffer[BUFFERSIZE];

struct file
{
    char name[100];
    char permissions[5];
    char size[1000];

    char text[10000];
};

int main(int argc, char const *argv[])
{

    fp = fopen("arsiv.sau", "r");

    if (fp == NULL)
    {
        fprintf(stderr, "this file is not occured!");
        exit(1);
    }

    fread(buffer, 10, BUFFERSIZE, fp);

    char sub[10];
    for (int i = 0; i < 10; i++)
    {
        sub[i] = buffer[i];
    }
    int descSize = atoi(sub);
    printf("%d", descSize);

    struct file files[32];

    int partIndex = 0;
    int i = 11;
    int fileCount = 0;
    int descCursor = 11;
    int textCursor = descSize;
    int objIndex = 0;
    for (int i = 11; i < descSize; i++)
    {
        if (buffer[i] == '|')
        {
            fileCount++;
            int partNo = 1;
            partIndex = 0;

            //        char fileName[100];
            //      char filePermission[3];
            //    char fileSize[10];

            for (int j = descCursor; j < i; j++)
            {
                if (buffer[j] == ',')
                {
                    partNo++;
                    j++;
                    partIndex = 0;
                    descCursor++;
                }
                if (partNo == 1)
                {
                    //name
                    files[objIndex].name[partIndex] = buffer[descCursor];
                    partIndex++;
                    descCursor++;
                }
                else if (partNo == 2)
                {
                    //permission
                    files[objIndex].permissions[partIndex] = buffer[descCursor];
                    partIndex++;
                    descCursor++;
                }
                else if (partNo == 3)
                {
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
    for (int i = 0; i < fileCount; i++)
    {
        for (int j = 0; j < atoi(files[i].size); j++)
        {
            files[i].text[j] = buffer[j + sayac];
        }
        sayac += atoi(files[i].size);
    }

    for (int i = 0; i < fileCount; i++)
    {

        printf("name: %s   Permission: %s   Size: %s\n Text: %s \n\n", files[i].name, files[i].permissions, files[i].size, files[i].text);
    }

    fclose(fp);
    return 0;
}
