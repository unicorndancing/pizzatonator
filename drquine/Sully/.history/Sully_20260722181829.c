#include <stdio.h>
#include <stdlib.h>

#define SOURCE "#include <stdio.h>%c#include <stdlib.h>%c%c#define SOURCE %c%s%c%cint main()%c{%c    int x = %d;%c    char file[64];%c    char cmd1[64];%c    char cmd2[64];%c    FILE *f;%c    if(x==0) return(1);%c%c    sprintf(file, %cSully_%cd.c%c, x - 1);%c    sprintf(cmd1, %ccc Sully_%cd.c -o Sully_%cd%c, x - 1, x - 1);%c    sprintf(cmd2, %c./Sully_%cd%c, x - 1);%c    f = fopen(file, %cw%c);%c    if (!f)%c    {%c        return 1;%c    }%c%c    fprintf(f, SOURCE,10,10,10,34,SOURCE,34,10,10,10,x-1,10,10,10,10,10,10,10,34,37,34,10,34,37,37,34,10,34,37,34,10,34,34,10,10,10,10,10,10,10,10,10,10,10,10,10,10);%c%c    fclose(f);%c%c    system(cmd1);%c    system(cmd2);%c    return 0;%c}%c"

int main()
{
    int x = 9999999;
    char file[64];
    char cmd1[64];
    char cmd2[64];
    FILE *f;
    if(x==0) return(1);

    sprintf(file, "Sully_%d.c", x - 1);
    sprintf(cmd1, "cc Sully_%d.c -o Sully_%d", x - 1, x - 1);
    sprintf(cmd2, "./Sully_%d", x - 1);

    f = fopen(file, "w");
    if (!f)
        return 1;

    fprintf(f, SOURCE,10,10,10,34,SOURCE,34,10,10,10,x-1,10,10,10,10,10,10,10,34,37,34,10,34,37,37,34,10,34,37,34,10,34,34,10,10,10,10,10,10,10,10,10,10,10,10,10,10);

    fclose(f);


    system(cmd1);
    system(cmd2);
    return 0;
}
