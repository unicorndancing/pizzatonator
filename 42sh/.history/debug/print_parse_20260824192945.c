/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:48:42 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/24 19:29:45 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"


void print_token(int token)
{
    switch (token)
    {
        case WORD:
            printf("WORD");
            break;

        case DOLLAR:
            printf("DOLLAR");
            break;

        case DOLLAR_DOUBLE:
            printf("DOLLAR_DOUBLE");
            break;

        case SUBSHELL:
            printf("SUBSHELL");
            break;

        case REDIR_OUT:
            printf("REDIR_OUT");
            break;

        case REDIR_IN:
            printf("REDIR_IN");
            break;

        case HEREDOC:
            printf("HEREDOC");
            break;

        case APPEND:
            printf("APPEND");
            break;

        case REDIR_OUT_WITH_AND:
            printf("REDIR_OUT_WITH_AND");
            break;

        case APPEND_WITH_AND:
            printf("APPEND_WITH_AND");
            break;

        case REDIR_IN_WITH_AND:
            printf("REDIR_IN_WITH_AND");
            break;

        case PIPE:
            printf("PIPE");
            break;

        case AND:
            printf("AND");
            break;

        case OR:
            printf("OR");
            break;

        case SEMILOCON:
            printf("SEMILOCON");
            break;

        case WHITESPACE:
            printf("WHITESPACE");
            break;
        case QUOTES:
            printf("QUOTES");
            break;
        case SINGLE_QUOTES:
            printf("SINGLE_QUOTES");
            break;
        case OPEN_PARENTHESIS:
            printf("OPEN_PARENTHESIS");
            break;
        case CLOSE_PARENTHESIS:
            printf("CLOSE_PARENTHESIS");
            break;
    }
}




void print_parse(t_parse *parse)
{
    for (int i = 0; i < NB_TOKEN_MAX; i++)
    {
        if (parse[i].begining_word != NULL)
        {
            char word[parse[i].endword - parse[i].begining_word];
            ft_memmove(word, parse[i].begining_word, parse[i].endword - parse[i].begining_word);
            word[parse[i].endword - parse[i].begining_word] = '\0';

            printf("\nword is : **%s**\n", word);
            print_token(parse[i].token);
            printf("\n");
            
        }
    }
}