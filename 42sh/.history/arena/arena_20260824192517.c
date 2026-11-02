/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:54:49 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/24 19:25:17 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/arena.h"

size_t arena_align(size_t offset, short align)
{
    return (offset + align - 1) & ~(align - 1);
}

t_arena arena_init(size_t capacity) 
{
    t_arena a;
    a.buffer = malloc(capacity);
    ft_bzero(a.buffer, capacity);
    a.capacity = capacity;
    a.offset = 0;
    return a;
}

void *arena_alloc(t_arena *a, size_t size, short align) 
{
    size_t alignement;

    alignement = arena_align(a->offset, align);

    if (a->offset + size > a->capacity) 
    {
        return NULL;
    }
    
    void *ptr = &a->buffer[a->offset];
    a->offset += size;
    return ptr;
}

void arena_reset(t_arena *a)
{
    a->offset = 0;
}

void arena_tini(t_arena *a) 
{
    free(a->buffer);
    a->buffer = NULL;
    a->capacity = 0;
    a->offset = 0;
}
