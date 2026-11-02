#include <stdio.h>
//bijour
void test(){}
int main() {
    //bijour
    test();
    char *s = "#include <stdio.h>%c//bijour%cvoid test(){}%cint main() {%c    //bijour%c    test()%c    char *s = %c%s%c;%c    printf(s,10,10,10,34,s,34,10,10);%c    return 0;%c}%c";

    printf(s,10,10,10,10,10,10,34,s,34,10,10,10,10,10,10,10);
    return 0;
}