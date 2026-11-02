#include <stdio.h>
#include <stdlib.h>

#define SOURCE "#include <stdio.h>%c#include <stdlib.h>%c%c#define SOURCE %c%s%c%cint main()%c{%c    int x = %c;%c    char file[64];%c    char file1[64];%c    char file2[64];%c    FILE *f;%c%c    sprintf(file, %cSully_%cd.c%c, x - 1);%c  sprintf(file1, %ccc Sully_%cd.c -o Sully_%cd%c, x - 1, x - 1);%c    sprintf(file2, %c./Sully_%cd%c, x - 1);%c    f = fopen(file, %cw%c);%c    if (!f)%c    {%c        return 1;%c    }%c%c    fprintf(f, SOURCE,10,10,10,34,SOURCE,34,10,10,10,x-1 + 48,10,34,x-1+48,x-1+48,34,10,34,x-1+48,34,10,10,10,10,10,34,37,34,10,10,34,34,10,10,10,10,10,10,10,10,10,10,34,x-1+48,x-1+48,34,10,34,x-1+48,34,10,10,10);%c%c    fclose(f);%c%c    system(%ccc Sully_%c.c -o Sully_%c%c);%c    system(%c./Sully_%c%c);%c    return 0;%c}%c"
int main()
{
    int x = 4;
    char file[64];
    char file1[64];
    char file2[64];
    FILE *f;

    sprintf(file, "Sully_4d.c", x - 1);
  sprintf(file1, "cc Sully_
d.c -o Sully_
d
, x - 1, x - 1);"    sprintf(file2, %./Sully_"d
, x - 1);
    f = fopen(file, "w");
    if (!f)
    {
        return 1;
    }

    fprintf(f, SOURCE,10,10,10,34,SOURCE,34,10,10,10,x-1 + 48,10,34,x-1+48,x-1+48,34,10,34,x-1+48,34,10,10,10,10,10,34,37,34,10,10,34,34,10,10,10,10,10,10,10,10,10,10,34,x-1+48,x-1+48,34,10,34,x-1+48,34,10,10,10);

    fclose(f);

    system("cc Sully_4.c -o Sully_4");
    system("./Sully_4");
    return 0;
}
