/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:49:16 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/19 18:51:36 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

token	get_token_type(char *word)
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
        {"\"",  QUOTES},
        {"\'",  SINGLE_QUOTES},
        {"*",  WILDCARD},
    };
    i = 0;
    printf("the word is **%s**\n", word);
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

void parsing(void *begin, void *endword, t_parse *parse)
{
    char word[endword - begin];

    ft_memcpy(word, begin, endword - begin);
    word[endword - begin] = '\0';
    parse->begining_word = begin;
    parse->endword = endword;
    parse->token = get_token_type(word);
}
