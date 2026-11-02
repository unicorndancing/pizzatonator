/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:52:47 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/18 20:23:17 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "arena.h"
#include <stdio.h>

void print_arena(t_arena arena);
void print_parse(t_parse *parse);

#endif