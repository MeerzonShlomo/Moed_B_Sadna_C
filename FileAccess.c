#include "FileAccess.h"
#include <stdlib.h>

int ChangeFile(char* Path)
{
    FILE* fp = NULL;

    char ch[] = "Hello, ";

    fp = fopens(Path, "r+");

    if (fp == NULL)
    {
        printf_s("%s", "Couldn't open file" );
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    long int fileLength = ftell(fp);

    char* res = (char*) malloc(fileLength + sizeof(ch) + 2);
    int count = sizeof(ch);
    strcpys(res, ch);
    char tmp;
    while ((tmp=fgetc(fp))!=EOF)
    {
        res[count] = tmp;
        count++;
    }

    res[count] = '!';

    fflush(fp);
 
    fgets(res, count + 1, fp);

    fclose(fp);
    free(res);


}
