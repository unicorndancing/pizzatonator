#include <stdio.h>
//bijour
void test(){}
int main() {
    //bijour
    test();
    char *s = "#include <stdio.h>\n//bijour\nvoid test(){}\nint main() {\n    //bijour\n    test()\n    char *s = \n%s\n;\n    printf(s,10,10,10,10,10,10,34,s,34,10,10,10,10,10,10,10);\n    return 0;\n}\n";
    printf(s,10,10,10,10,10,10,34,s,34,10,10,10,10,10,10,10);
    return 0;
}