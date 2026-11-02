#include "includes/tokenizer.h"




int main(int argc, char **argv)
{
    if (argc == 1)
        return 0;
    Arena arena = arena_init(10000000);
    tokenizer(argv[1], &arena);
    print_arena(arena);
}