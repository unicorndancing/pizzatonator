/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:49:16 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 20:02:11 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

short tree_lexicographic(char *word, t_arena *arena)
{
    
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

        case NODE_PIPE:

        case NODE_AND:

        case NODE_OR:
        
        default :;
    }
    return NULL;
}