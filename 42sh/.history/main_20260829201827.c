#include "includes/tokenizer.h"
#include "includes/arena.h"
#include "includes/debug.h"


int main(int argc, char **argv)
{
    t_parse *parse;
    if (argc == 1)
        return 0;
    t_arena arena = arena_init(ARENA_SIZE);
    parse = tokenizer(argv[1], &arena);
    root(parse, &arena);
    // print_arena(arena);
    
}