/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:48:42 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/19 16:25:46 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

void print_parse(t_parse *parse)
{
    for (int i = 0; i < NB_TOKEN_MAX; i++)
    {
        if (parse[i].begining_word != NULL)
        {
            char word[parse[i].endword - parse[i].begining_word + 1];
            word[parse[i].endword - parse[i].begining_word + 1] = '\0';
            ft_memcpy(word, parse[i].begining_word, parse[i].endword - parse[i].begining_word);
            
            printf("word is : **%s**", word);
            switch (parse[i].token)
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
    
            }
            printf("\n\n\n");
            
        }
    }
}