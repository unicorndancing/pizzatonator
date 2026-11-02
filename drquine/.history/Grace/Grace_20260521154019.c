#include <stdio.h>

#define FILENAME "Grace_kid.c"
#define SOURCE "#include <stdio.h>%c%c#define FILENAME %cGrace_kid.c%c%c#define SOURCE %c%s%c%c#define MAIN int main(){%cFILE *f=fopen(FILENAME,%cw%c);fprintf(f,SOURCE,10,10,34,34,10,34,SOURCE,34,10,34,34,10,10,10,10);fclose(f);return 0;}%c%c//bijour%c%cMAIN"
#define MAIN int main(){\
    FILE *f=fopen(FILENAME,"w");fprintf(f,SOURCE,10,10,34,34,10,34,SOURCE,34,10,34,34,134,10,10,10,10);fclose(f);return 0;}

//bijour

MAIN