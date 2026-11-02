/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:29:27 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/20 16:42:22 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"
#include "../includes/debug.h"

short verif_line_ended(t_parse *parse)
{
    int i = 0;
    short important_token = 0;

    while (parse[i].begining_word)
    {
        if (parse[i].token == QUOTES || parse[i].token == SINGLE_QUOTES)
            important_token
        i++;
    }
}