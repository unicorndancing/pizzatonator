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

typedef struct s_parse
{
    void *begining_word;
    void *endword;
    int token;
} t_parse;

typedef enum e_token_type
{
    WORD = 1,
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
    QUOTES,
    SINGLE_QUOTES,
    WILDCARD,
    MATH,
    DOLLAR_SINGLE_QUOTE,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS
    

} token;

typedef struct s_Node Node;

typedef enum e_ast_type
{
    AST_COMMAND,
    AST_PIPE,
    AST_AND,
    AST_OR,
    AST_SUBSHELL
} ast_type;

typedef struct s_Redir
{
	char *redir_name;
	short *token;
} Redir;

typedef struct s_Command
{
    char 	**argv;
    char	**redir;
    int     **redir_type;
} Command;

typedef struct s_Binary
{
    Node *left;
    Node *right;
} Binary;

struct s_Node
{
    int type;

    union
    {
        Command command;
        Binary binary;
    } data;
};

typedef struct s_token_lookup
{
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
void parsing(void *begin, void *endword, t_parse *parse);


short verif_line_ended(t_parse *parse);

t_parse *tokenizer(char * line, t_arena *arena);

#endif
