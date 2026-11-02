/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:34:32 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 13:31:55 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"


int tokenizer(char * line, Arena *arena)
{
	int		i;
	char	*word;
	bool	b_error;

    printf("the line at beginig is ** %s **\n", line);

	i = 0;
    b_error = 0;
	if (!line || line[0] == '\0')
		return (1);
	do{
		i += ignore_whitespace(&line[i]);
		word = getentity(&line[i], &i, arena);
		if (!word)
			return (1);
		if (b_error == true)
			return (1);
		// tokenizer(word, arena);
    }while(line[i] != '\0');

    return 0;
}
