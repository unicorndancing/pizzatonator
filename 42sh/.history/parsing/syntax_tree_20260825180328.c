/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:10:08 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/25 18:03:28 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

Node *root(t_parse *parse, t_arena arena)
{

    return (NULL);
}
short token_word(short token, short previous)
{
    if (token == WORD && (previous == WORD || previous == 0))
       return (AST_COMMAND);
    else if (previous == REDIR_IN || previous == REDIR_IN_WITH_AND || previous == REDIR_OUT || previous == REDIR_OUT_WITH_AND)
        return (555);
    else
        return 666;
}

Node *command(t_parse *parse, Node *mynode)
{
    size_t i = 0;
    short j = 0;
    short token = 0;
    short previous_token = 0;

    mynode->type = AST_COMMAND;
    while (parse)
    {
        token = parse[i].token;
        parse[i].token = token_word(token, previous_token);
        previous_token = token;
    }
}