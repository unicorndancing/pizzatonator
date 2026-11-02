/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:49:16 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 19:51:30 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

short tree_(char *word, t_arena *arena)
{
    (void) word;
    (void) arena;

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
    switch(my_racist_function(word, arena))
    {
        case 1:

        case 2:

        default :;
    }
    return NULL;
}