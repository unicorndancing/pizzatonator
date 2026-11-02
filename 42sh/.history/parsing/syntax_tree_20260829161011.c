/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:10:08 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/29 16:10:11 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

Node *root(t_parse *parse, t_arena arena)
{

    return (NULL);
}

Node *command(t_parse *parse)
{
    int i = 0;
    int last_token = 0;
    while (!is_command_end(parse[i].token))
    {
        if (is_redirection(last_token) && parse[i].token == WORD)
            

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


static int is_word(short token)
{
    return (token == WORD);
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
