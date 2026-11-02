/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:29:27 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/20 17:17:23 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"
#include "../includes/debug.h"

short verif_line_ended(t_parse *parse)
{
    int     paren_depth;
    int     singlequote;
    int     doublequote;
    int     i = 0;
    int     last = 0;

    paren_depth = 0;
    quote = 0;

    while (parse[i].token)
    {
        last = parse[i].token;

        if (parse[i].token == SINGLE_QUOTES)
            singlequote = !singlequote;
        else if (parse[i].token == QUOTES)
            doublequote = !doublequote;
        else if (parse[i].token == OPEN_PARENTHESIS)
            paren_depth++;
        else if (parse[i].token == CLOSE_PARENTHESIS)
            paren_depth--;
        i++;
    }

    if (singlequote || doublequote)
        return QUOTES;
    if (paren_depth > 0)
        return OPEN_PARENTHESIS;
    return (0);
}
