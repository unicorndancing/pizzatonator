#include <stdio.h>
int main() {
    //bijour
    char *s = "#include <stdio.h>%cint main() {%c    //bijour%c    test()%c    char *s = %c%s%c;%c    printf(s,10,10,10,10,34,s,34,10,10,10,10,10);%c    return 0;%c}%c";
    printf(s,10,10,10,10,34,s,34,10,10,10,10,10);
    return 0;
}