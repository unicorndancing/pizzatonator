/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:29:27 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/26 21:10:59 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"
#include "../includes/debug.h"

short verif(bool singlequote, bool doublequote, int paren_depth, int last)
{
    printf("\n%i double quotes\n", doublequote);
    if (singlequote || doublequote)
        return QUOTES;
    else if (paren_depth != 0)
        return OPEN_PARENTHESIS;
}

short verif_line_ended(t_parse *parse)
{
    int     paren_depth = 0;
    bool     singlequote = 0;
    bool     doublequote = 0;
    int     i = 0;
    int     last = 0;

    while (parse[i].token)
    {
        if (parse[i].token == SINGLE_QUOTES && !doublequote)
            singlequote = !singlequote;
        else if (parse[i].token == QUOTES && !singlequote)
            doublequote = !doublequote;
        else if (parse[i].token == OPEN_PARENTHESIS || parse[i].token == SUBSHELL)
            paren_depth++;
        else if (parse[i].token == CLOSE_PARENTHESIS)
            paren_depth--;
        else if (parse[i].token == MATH)
            paren_depth += 2;
        i++;
    }
    return (verif(singlequote, doublequote, paren_depth, last));
}
