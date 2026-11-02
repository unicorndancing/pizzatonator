/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:49:16 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/18 18:27:06 by mlapique         ###   ########.fr       */
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
    {"$$", DOLLAR_DOUBLE},
    {"$(", SUBSHELL},
    };
    i = 0;
    while (i < sizeof(tokens) / sizeof(tokens[0]))
    {
        if (strcmp(word, tokens[i].str) == 0)
            return (tokens[i].token);
        i++;
    }
    if (word[0] == '$')
        return (DOLLAR);
    return (WORD);
}

t_parse *parsing(char *word, t_arena *arena)
{
    (void) arena;
    (void) word;
    
    // return NULL;
}
