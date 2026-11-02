#define FT int main(){...}
#define OPEN FILE *f = fopen("Grace_kid.c", "w");
#include <stdio.h>
int main() {
    //bijour
    FILE *f = fopen("Grace_kid.c", "w");
    char *s = "#define FT int main(){...}%c#define OPEN FILE *f = fopen(%cGrace_kid.c%c, %cw%c);";
    fprintf(f,s,10,10,10,34,34,34,34,10,34,s,34,10,10,10,10);
    return 0;
}


