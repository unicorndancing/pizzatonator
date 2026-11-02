/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:45:18 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 16:33:31 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef tokenizer_H
# define tokenizer_H

# include "../libft/libft.h"
# include "stdbool.h"
# include "stdio.h"
# include "stdlib.h"
# include "arena.h"
# include <stdalign.h>
# include <stddef.h>

typedef struct s_Redir
{
	char *redir_name;
	short token;
} Redir;

typedef enum e_redir_type
{
    REDIR_OUT,
    REDIR_IN,
    HEREDOC,
    APPEND,
    
} redir_type;

typedef enum e_node_type
{
    NODE_COMMAND,
    NODE_PIPE,
    NODE_AND,
    NODE_OR
} typenod;

typedef struct s_Node Node;

typedef struct s_Command
{
    char 	**argv;
    Redir	*redir;
} Command;

typedef struct s_Binary
{
    Node *left;
    Node *right;
} Binary;

struct s_Node
{
    typenod type;

    union
    {
        Command command;
        Binary binary;
    } data;
};

// __LINE MANIPULATION__
// char	*get_end_word(char *line);
// int	blitzgrieg(char *line, int i, char *endword);
// int	go_end(char *line, char c);
// char	*cpy(char *line, char *endword, int *size, Arena *arena);
char	*getentity(char *line, int *size, Arena *arena);
int	ignore_whitespace(char *line);
Node *tokenizer(char *word, Arena *arena);


int tokenizer(char * line, Arena *arena);

#endif
