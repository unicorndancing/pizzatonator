/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:10:08 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/29 18:19:42 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

Node *root(t_parse *parse, t_arena arena)
{

    return (NULL);
}

Node *command(t_parse *parse, t_arena *arena)
{
    Node *myNode;
    int i = 0;
    int j = 0;
    int last_token = 0;
    myNode = arena_alloc(arena, sizeof(*myNode), alignof(*myNode));
    while (!is_command_end(parse[i].token))
    {
        if (is_redirection(last_token) && parse[i].token == WORD)
            myNode->data.command.redir->redir_name[j] = extract_word(parse[i].begining_word, parse[i].begining_word);
        else if (parse[i].token == WORD && myNode->data.command.argv[0] != NULL)
            myNode->data.command.argv[0] = extract_word(parse[i].begining_word, parse[i].endword);
        
            
        last_token = parse[i].token
    }
}

static Redir *new_redir(t_parse *parse, int nb)
{
    Redir *redir;

    redir = malloc(sizeof(Redir));
    if (!redir)
        return (NULL);

    redir->token[nb] = parse[0].token;
    redir->redir_name[nb] = get_word(&parse[1]);
    redir = NULL;

    if (!redir->redir_name)
    {
        free(redir);
        return (NULL);
    }

    return (redir);
}

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
