#include <stdio.h>

#define FILENAME "Grace_kid.c"
#define SOURCE "#include <stdio.h>%c%c#define FILENAME %cGrace_kid.c%c%c#define SOURCE %c%s%c%c#define MAIN int main(){%c%c%cFILE *f=fopen(FILENAME,%cw%c);%c%c%cfprintf(f,SOURCE,10,10,34,34,10,34,SOURCE,34,10,34,34,10,10,10,10);fclose(f);return 0;}%c%c//bijour%c%cMAIN"
#define MAIN int main(){\
    FILE *f=fopen(FILENAME,"w");\
    fprintf(f,SOURCE,10,10,34,34,10,34,SOURCE,34,10,92,10,9,34,34,92,10,9,10,10,10,10);fclose(f);return 0;}

//bijour

MAIN