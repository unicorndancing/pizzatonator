/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:54:49 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 10:49:01 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/arena.h"

size_t arena_align(size_t offset)
{
    return (offset + __BIGGEST_ALIGNMENT__ - 1) & ~(__BIGGEST_ALIGNMENT__ - 1);
}

Arena arena_init(size_t capacity) 
{
    Arena a;
    a.buffer = malloc(capacity);
    a.capacity = capacity;
    a.offset = 0;
    return a;
}

void *arena_alloc(Arena *a, size_t size) 
{
    size_t alignement;

    alignement = arena_align(a->offset);
    if (a->offset + size > a->capacity) 
    {
        return NULL;
    }
    void *ptr = &a->buffer[a->offset];
    a->offset += size;
    return ptr;
}

void arena_reset(Arena *a)
{
    a->offset = 0;
}

void arena_free(Arena *a) 
{
    free(a->buffer);
    a->buffer = NULL;
    a->capacity = 0;
    a->offset = 0;
}