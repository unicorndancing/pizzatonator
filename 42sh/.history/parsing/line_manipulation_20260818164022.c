/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:27:01 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/18 16:40:22 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

static char *dollar_token(char *pos)
{
	if ((pos[1]) == '$')
		return (pos + 1);
	else if ((pos[1]) == '(')
		return (pos + 1);
	else if ((pos[1]) == '!')
		return (pos + 1);
	else
	{
		while (*pos != '\0' || *pos != ' ')
		{
			pos++;
		}
		return (pos);
	}
}

static char	*cpy(char *line, char *endword, int *size, t_arena *arena)
{
	int		i;
	char	*word;

	i = 0;
	word = arena_alloc(arena, endword - line + 1, alignof(char *));
	if (!word)
		return (NULL);
	while (line && line[i] && &line[i] != endword)
	{
		word[i] = line[i];
		i++;
	}
	word[i] = '\0';
	*size += i;
	return (word);
}

static char	*get_end_word(char *line)
{
	int		i;
	char	*endword;

	i = 0;
	endword = NULL;
	while (line && line[i] && endword == NULL)
	{
		if (ft_strchr("\t <>|()\"\'$", line[i]))
		{
			if (line[i] == '$')
				endword = dollar_token(&line[i]);
			else if (i == 0 && (line[i + 1] == line[i]) && ft_strchr("<>", line[i]))
				endword = &line[i + 2];
			else if (i == 0)
				endword = &line[i + 1];
			else
				endword = &line[i];
		}
		i++;
	}
	if (endword == NULL)
		endword = &line[i];
	return (endword);
}

char	*getentity(char *line, int *size, t_arena *arena)
{
	char	*word;
	char	*endword;

	if (!line || line[0] == '\0')
		return (NULL);
	endword = get_end_word(line);
	word = cpy(line, endword, size, arena);
	return (word);
}

int	ignore_whitespace(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ' || ((line[i] <= 13 && line[i] >= 9)))
		i++;
	return (i);
}