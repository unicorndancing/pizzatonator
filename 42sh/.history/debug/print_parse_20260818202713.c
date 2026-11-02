/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:48:42 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/18 20:27:13 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

void print_parse(t_parse *parse)
{
    for (int i = 0; i < NB_TOKEN_MAX; i++)
    {
        printf("word is : **");
        for(int j = 0; parse[i].begining_word + j != parse[i].endword; j++)
		{
			printf("%c", (char)*parse[i].begining_word + j);
		}
        printf("**\n");
        switch (parse[i].token)
        {
            case WORD:
                printf("WORD");

            case DOLLAR:
                printf("DOLLAR");

            case DOLLAR_DOUBLE:
                printf("DOLLAR_DOUBLE");

            case SUBSHELL:
                printf("SUBSHELL");

            case REDIR_OUT:
                printf("REDIR_OUT");

            case REDIR_IN:
                printf("REDIR_IN");

            case HEREDOC:
                printf("HEREDOC");

            case APPEND:
                printf("APPEND");

            case REDIR_OUT_WITH_AND:
                printf("REDIR_OUT_WITH_AND");

            case APPEND_WITH_AND:
                printf("APPEND_WITH_AND");

            case REDIR_IN_WITH_AND:
                printf("REDIR_IN_WITH_AND");

            case PIPE:
                printf("PIPE");

            case AND:
                printf("AND");

            case OR:
                printf("OR");

            case SEMILOCON:
                printf("SEMILOCON");

            case WHITESPACE:
                printf("WHITESPACE");

        }
        printf("\n\n\n");
        
    }
}