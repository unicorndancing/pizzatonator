#include "includes/tokenizer.h"
#include "includes/arena.h"
#include "includes/debug.h"



int main(int argc, char **argv)
{
    if (argc == 1)
        return 0;
    Arena arena = arena_init(ARENA_SIZE);
    tokenizer(argv[1], &arena);
    print_arena(arena);
}