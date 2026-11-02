/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:45:18 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/12 14:29:17 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef tokenizer_H
# define tokenizer_H

# include "../libft/libft.h"
# include "stdbool.h"
# include "stdio.h"
# include "stdlib.h"
# include "arena.h"


typedef enum e_tokens
{
	ERROR_EXPAND = -10,
	EXPAND_NULL = -9,
	REDIR_IN = 0,
	REDIR_HEREDOC = 1,
	REDIR_OUT = 2,
	REDIR_APPENDS_TO_FILE = 3,
	REDIR_HEREDOC_MODE_IN_QUOTES = 4,
	PIPE = 5,
	SINGLE_QUOTES = 39,
	DOUBLE_QUOTES = 34
}		t_grammar;

// line manipulation
char	*get_end_word(char *line);
char	*getentity(char *line, int *size, Arena *arena);
int	ignore_whitespace(char *line);
int	blitzgrieg(char *line, int i, char *endword);
int	go_end(char *line, char c);
char	*cpy(char *line, char *endword, int *size, Arena *arena);


int tokenizer(char * line, Arena *arena);

#endif
