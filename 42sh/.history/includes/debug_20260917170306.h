/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:52:47 by mlapique          #+#    #+#             */
/*   Updated: 2026/09/17 17:03:06 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "arena.h"
#include "tokenizer.h"
#include <stdio.h>

void print_arena(t_arena arena);
void print_parse(t_parse *parse);
void print_token(int token);
void print_node(Node *node);

#endif