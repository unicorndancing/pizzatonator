/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:48:42 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/18 20:20:51 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

void print_parse(t_parse *parse)
{
    for (int i = 0; i < NB_TOKEN_MAX; i++)
    {
        printf("word is : **");
        for(int j = 0; parse[i].begining_word + j != parse[i].endword; j++)
		{
			printf("%c", parse[i].begining_word + j);
		}
        printf("**\n");
        switch (parse[i].token)
        {
            
        }
        
    }
}