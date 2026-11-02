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



t_parse *tokenizer(char *line, t_arena *arena)
{
	int		i;
	int		j = 0;
	void	*endword;
	t_parse *parse;

	parse = arena_alloc(arena, sizeof(t_parse) * NB_TOKEN_MAX, alignof(t_parse *));
    printf("the line at begining is ** %s **\n", line);

	i = 0;
	if (!line || line[0] == '\0')
		return (NULL);
	while(line[i] != '\0')
	{
		endword = getentity(&line[i]);
		if (!endword)
			return (NULL);
		parsing(&line[i], endword, &parse[j]);
		i += (char *)endword - &line[i];
		j++;
    }

	print_parse(parse);
	// print_token(verif_line_ended(parse));

    return parse;
}
