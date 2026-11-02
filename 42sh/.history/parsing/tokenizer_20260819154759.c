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
#include "../includes/debug.h"



int tokenizer(char *line, t_arena *arena)
{
	int		i;
	int		j = 0;
	void	*endword;
	(void) arena;
	t_parse parse[NB_TOKEN_MAX];

	ft_bzero(parse, sizeof(t_parse) * NB_TOKEN_MAX);
    printf("the line at begining is ** %s **\n", line);

	i = 0;
	if (!line || line[0] == '\0')
		return (1);
	while(line[i] != '\0')
	{
		endword = getentity(&line[i]);
		// printf("%p    %p     %i\n", &line[i], endword, i);
		if (!endword)
			return (1);
		printf("\nline is >       **%s**\n diff is >      **", &line[i]);
		for(int j = i; line + j != endword; j++)
		{
			printf("%c", line[j]);
		}
		printf("**\n\n\n");
		parsing(&line[i], endword, &parse[j]);
		i += (char *)endword - &line[i];
		j++;
    }

	print_parse(parse);

    return 0;
}
