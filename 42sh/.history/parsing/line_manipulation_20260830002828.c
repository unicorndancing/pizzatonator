/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:27:01 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/30 00:28:28 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"


static char *dollar_token(char *pos)
{
	if ((pos[1]) == '$' || (pos[1]) == '(' || (pos[1]) == '!' || (pos[1]) == '\'')
		return (pos + 2);
	else
	{
		while (*pos != '\0' && *pos != ' ')
		{
			pos++;
		}
		return (pos);
	}
}

static char *endword_rules(char *line, size_t i)
{
	char *endword;

	if (i == 0 && ((line[i] == '>' || line[i] == '<') && line[i + 1] == '&'))
		endword = &line[i + 2];
	else if (i == 0 && ((line[i] == '>' || line[i] == '<') && line[i + 1] == '('))
		endword = &line[i + 2];
	else if (i == 0 && line[i] == '$')
		endword = dollar_token(&line[i]);
	else if (i == 0 && (line[i + 1] == line[i]) && ft_strchr("<>", line[i]))
		endword = &line[i + 2];
	else if (i == 0)
		endword = &line[i + 1];
	else if (i == 0 && line[i + 0] == '2' && line[i + 1] == '>' && line[i + 2] == '>')
	{
		printf("tsst\n");
		endword = &line[i + 3];
	}
	else
		endword = &line[i];
	return (endword);
}

static char	*get_end_word(char *line)
{
	int		i;
	char	*endword;

	i = 0;
	endword = NULL;
	while (line && line[i] && endword == NULL)
	{
		if (ft_strchr("\t <>|()\"\'$\t\v\f\r\n;2", line[i]))
		{
			endword = endword_rules(line, i);
		}
		i++;
	}
	if (endword == NULL)
		endword = &line[i];
	return (endword);
}

void	*getentity(char *line)
{
	char	*endword;

	if (!line || line[0] == '\0')
		return (NULL);
	endword = get_end_word(line);
	return (endword);
}
