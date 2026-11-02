/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:10:08 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/29 20:31:55 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

static int is_redirection(short token)
{
    return (token == REDIR_IN
        || token == REDIR_OUT
        || token == REDIR_IN_WITH_AND
        || token == REDIR_OUT_WITH_AND);
}

static int is_command_end(short token)
{
    return (token == PIPE
        || token == AND
        || token == OR
        || token == OPEN_PARENTHESIS
        || token == CLOSE_PARENTHESIS
        || token == EOF);
}

char *extract_word(t_arena *arena, char *begin, char *end)
{
    char *word;

    word = arena_alloc(arena, end - begin, alignof(char *));
    ft_memmove(word, begin, end - begin);
    word[end - begin] = '\0';
    return word;
}

Node *command(t_parse *parse, t_arena *arena)
{
    Node *myNode;

    int i = 0, j = 0, v = 0;
    int last_token = 0;

    myNode = arena_alloc(arena, sizeof(*myNode), alignof(Node *));
    myNode->type = AST_COMMAND;
    while (!is_command_end(parse[i].token) || !parse[i].begining_word)
    {
        if (is_redirection(last_token) && parse[i].token == WORD)
        {
            myNode->data.command.redir[j] = extract_word(arena, parse[i].begining_word, parse[i].begining_word);
            myNode->data.command.redir_type[j] = parse[i].token;
            j++;
        }
        else if (parse[i].token == WORD && myNode->data.command.argv[0] == NULL)
            myNode->data.command.argv[0] = extract_word(arena, parse[i].begining_word, parse[i].endword);
        else if (parse[i].token == WORD && myNode->data.command.argv[0] != NULL)
        {
            myNode->data.command.argv[v] = extract_word(arena, parse[i].begining_word, parse[i].endword);
            v++;
        }
        last_token = parse[i].token;
    }
    return (myNode);
}

Node *root(t_parse *parse, t_arena *arena)
{
    command(parse, arena);
    return (NULL);
}



