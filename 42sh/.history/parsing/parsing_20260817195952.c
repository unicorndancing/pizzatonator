/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:49:16 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 19:59:52 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

short tree_lexicographic(char *word, t_arena *arena)
{

    if (ft_strlen(word) == 1)
    {
        return word[0];
    }
    else
    {
        
    }
    return 0;
}

Node *parsing(char *word, t_arena *arena)
{
    (void) arena;
    switch(tree_lexicographic(word, arena))
    {
        case REDIR_OUT:

        case REDIR_IN:

        case HEREDOC:

        case APPEND:

        case REDIR_OUT_WITH_AND:

        case APPEND_WITH_AND:

        case REDIR_IN_WITH_AND:

        case NODE_COMMAND:

        case 9:

        case 10:

        case 11:
        
        default :;
    }
    return NULL;
}