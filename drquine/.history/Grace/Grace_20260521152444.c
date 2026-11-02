#define FT int main(){...}
#define FILE FILE *f = fopen("Grace_kid.c", "w");
#include <stdio.h>
int main() {
    //bijour
    FILE *f = fopen("Grace_kid.c", "w");
    char *s = "#include <stdio.h>%cint main() {%c    //bijour%c    FILE *f = fopen(%cGrace_kid.c%c, %cw%c);%c    char *s = %c%s%c;%c    fprintf(f,s,10,10,10,10,34,s,34,10,10,10,10,10);%c    return 0;%c}%c";
    fprintf(f,s,10,10,10,34,34,34,34,10,34,s,34,10,10,10,10);
    return 0;
}


