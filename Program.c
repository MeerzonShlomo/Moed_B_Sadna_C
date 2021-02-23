#include <stdio.h>
#include <stdlib.h>
#include "FileAccess.h"
//#include



int main()
{
    char* Path = NULL;
    printf("%s", "Please enter the file path .");
    scanfs("%s", Path);
    ChangeFile(Path);

}