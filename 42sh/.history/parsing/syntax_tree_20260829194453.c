/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:10:08 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/29 19:44:53 by mlapique         ###   ########.fr       */
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
        || token == CLOSE_PARENTHESIS);
}

char *extract_word(char *begin, char *end, t_arena *arena)
{
    char *word;

    arena_alloc(arena, end - begin, alignof(char *));
    
    word[end - begin] = '\0';
    return word;
}

Node *root(t_parse *parse, t_arena arena)
{

    return (NULL);
}

Node *command(t_parse *parse, t_arena *arena)
{
    Node *myNode;

    int i = 0, j = 0, v = 0;
    int last_token = 0;

    printf("is at 0 maybe %d %d %d", i, j, v);
    myNode = arena_alloc(arena, sizeof(*myNode), alignof(*myNode));
    myNode->type = AST_COMMAND;
    while (!is_command_end(parse[i].token))
    {
        if (is_redirection(last_token) && parse[i].token == WORD)
        {
            myNode->data.command.redir->redir_name[j] = extract_word(parse[i].begining_word, parse[i].begining_word);
            myNode->data.command.redir->token[j] = parse[i].token;
            j++;
        }
        else if (parse[i].token == WORD && myNode->data.command.argv[0] == NULL)
            myNode->data.command.argv[0] = extract_word(parse[i].begining_word, parse[i].endword);
        else if (parse[i].token == WORD && myNode->data.command.argv[0] != NULL)
        {
            myNode->data.command.argv[v] = extract_word(parse[i].begining_word, parse[i].endword);
            v++;
        }
        last_token = parse[i].token;
    }
    return (myNode);
}

