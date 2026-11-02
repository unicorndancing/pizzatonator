/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:45:18 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 16:38:11 by mlapique         ###   ########.fr       */
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

# define NB_TOKEN_MAX 1024

typedef struct s_Redir
{
	char *redir_name;
	short token;
} Redir;

typedef struct s_parse
{
    void *begining_word;
    void *endword;
    short token;
} t_parse;

typedef enum e_token_type
{
    WORD,
    DOLLAR,
    DOLLAR_DOUBLE,
    SUBSHELL,
    REDIR_OUT,
    REDIR_IN,
    HEREDOC,
    APPEND,
    REDIR_OUT_WITH_AND,
    APPEND_WITH_AND,
    REDIR_IN_WITH_AND,
    PIPE,
    AND,
    OR,
    SEMILOCON,
    WHITESPACE,
} token;

// typedef enum e_redir_type
// {
//     REDIR_OUT,
//     REDIR_IN,
//     HEREDOC,
//     APPEND,
//     REDIR_OUT_WITH_AND,
//     APPEND_WITH_AND,
//     REDIR_IN_WITH_AND,
// } redir_type;

// typedef enum e_node_type
// {
//     NODE_COMMAND = 20,
//     NODE_PIPE,
//     NODE_AND,
//     NODE_OR,
//     WORD
// } typenod;

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
    token type;

    union
    {
        Command command;
        Binary binary;
    } data;
};

typedef struct s_token_lookup{
    char *str;
    int token;
} t_token_lookup;

// __LINE MANIPULATION__
// char	*get_end_word(char *line);
// int	blitzgrieg(char *line, int i, char *endword);
// int	go_end(char *line, char c);
// char	*cpy(char *line, char *endword, int *size, Arena *arena);
void	*getentity(char *line);
int	ignore_whitespace(char *line);
t_parse *parsing(void *begin, void *endword, t_arena *arena);


int tokenizer(char * line, t_arena *arena);

#endif
