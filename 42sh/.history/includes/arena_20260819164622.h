/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:50:10 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/19 16:46:22 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H


#include <stdlib.h>

#define ARENA_SIZE (1.e7)

typedef struct s_Arena
{
    unsigned char *buffer;
    size_t capacity;
    size_t offset;
    void *usable_memory_list;
    size_t *usable_memory_size_list;
} t_arena;

t_arena arena_init(size_t capacity);
void *arena_alloc(t_arena *a, size_t size, short align);
void arena_free(t_arena *a);

#endif