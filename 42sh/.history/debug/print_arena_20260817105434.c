/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:53:48 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 10:54:34 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void print_arena(Arena arena)
{
    for(int i = 0; i < ARENA_SIZE; i++)
    {
        if (arena.buffer[i] == '\0' && i + 1 < ARENA_SIZE && arena.buffer[i + 1] != '\0')
            printf("\n");
        printf("%c", arena.buffer[i]);
    }
}