/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:34:32 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 13:50:46 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"


int tokenizer(char *line, t_arena *arena)
{
	int		i;
	void	*endword;
	int		nb_word = 0;

    printf("the line at begining is ** %s **\n", line);

	i = 0;
	if (!line || line[0] == '\0')
		return (1);
	while(line[i] != '\0')
	{
		endword = getentity(&line[i], &i, arena);
		if (!endword)
			return (1);
		for(int j = 0; line[j] != endword; j++)
		{
			
		}
		parsing(&line[i], endword, arena);
    }

    return 0;
}
