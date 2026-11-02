/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:49:16 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/18 16:48:13 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

short BST(char *word, t_arena *arena)
{
    (void) arena;
    (void) word;
    return 0;
}

Node *parsing(char *word, t_arena *arena)
{
    (void) arena;
    (void) word;
    switch(BST(word, arena))
    {
        case REDIR_OUT:

        case REDIR_IN:

        case HEREDOC:

        case APPEND:

        case REDIR_OUT_WITH_AND:

        case APPEND_WITH_AND:

        case REDIR_IN_WITH_AND:

        case NODE_COMMAND:

        case NODE_PIPE:

        case NODE_AND:

        case NODE_OR:
        
        default :
            break;;
    }
    return NULL;
}