/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:49:16 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/18 17:17:48 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

token	get_token_type(const char *word)
{
    size_t	i;

    static const t_token_lookup tokens[] =
    {
    {">",  REDIR_OUT},
    {">>", APPEND},
    {"<",  REDIR_IN},
    {"<<", HEREDOC},
    {">&", REDIR_OUT_WITH_AND},
    {"<&", REDIR_IN_WITH_AND},
    {">>&", APPEND_WITH_AND},
    {"|",  PIPE},
    {";",  SEMILOCON},
    {"&&", AND},
    {"||", OR},
    {"$",  DOLLAR},
    {"$$", DOLLAR_DOUBLE},
    {"$(", SUBSHELL},
    };
    i = 0;
    while (i < sizeof(tokens) / sizeof(tokens[0]))
    {
        if (strcmp(word, tokens[i].str) == 0)
            return (tokens[i].type);
        i++;
    }
    return (WORD);
}


short lookup(char *word, t_arena *arena)
{
    return 0;
}

Node *parsing(char *word, t_arena *arena)
{
    (void) arena;
    (void) word;
    switch(BST(word, arena))
    {
        case WORD :

        case DOLLAR :
            
        case DOLLAR_DOUBLE :
            
        case SUBSHELL :
            
        case REDIR_OUT :
            
        case REDIR_IN :
            
        case HEREDOC :
            
        case APPEND :
            
        case REDIR_OUT_WITH_AND :
            
        case APPEND_WITH_AND :
            
        case REDIR_IN_WITH_AND :
            
        case NODE_COMMAND :
            
        case NODE_PIPE :
            
        case NODE_AND :
            
        case NODE_OR :
            
        
        default :
            break;;
    }
    return NULL;
}
