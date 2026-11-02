/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:10:08 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/25 18:27:57 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

Node *root(t_parse *parse, t_arena arena)
{

    return (NULL);
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
    return (token == TOKEN_EOF
        || token == PIPE
        || token == AND
        || token == OR);
}
