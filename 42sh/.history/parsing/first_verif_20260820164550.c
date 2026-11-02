/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:29:27 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/20 16:45:50 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"
#include "../includes/debug.h"

short verif_line_ended(t_parse *parse)
{
    int i = 0;
    // short open = 0;

    while (parse[i].begining_word)
    {
        // if (parse[i].token == QUOTES || parse[i].token == SINGLE_QUOTES)
        //     open = parse[i].token
        i++;
    }
}