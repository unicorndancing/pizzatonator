/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:49:16 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/18 18:59:12 by mlapique         ###   ########.fr       */
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
        if (ft_strcmp(word, tokens[i].str) == 0)
            return (tokens[i].token);
        i++;
    }
    if (word[0] == '$')
        return (DOLLAR);
    else if (word[0] == ' ' || (word[0] >= 9 && word[0] <= 13))
        return (WHITESPACE);
    return (WORD);
}

t_parse *parsing(void *begin, void *endword, t_arena *arena)
{
    (void) arena;
    (void)begin;
    (void)endword;
    return NULL;
}
