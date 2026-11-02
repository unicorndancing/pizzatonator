#include "includes/tokenizer.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        return 0;
    Arena arena = arena_init(10000000);
    tokenizer(argv[1], &arena);
    for(int i = 0; i < 10000000; i++)
    {
        if (arena.buffer[i] == '\0' && i + 1 < 10000000 && arena.buffer[i + 1] != '\0')
            printf("\n");
        printf("%c", arena.buffer[i]);
    }
}