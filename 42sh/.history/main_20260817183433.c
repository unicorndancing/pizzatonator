#include "includes/tokenizer.h"
#include "includes/arena.h"
#include "includes/debug.h"

unsigned long
hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 0;
    t_arena arena = arena_init(ARENA_SIZE);
    tokenizer(argv[1], &arena);
    print_arena(arena);
    
    printf("")

}