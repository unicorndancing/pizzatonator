/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:54:49 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/12 13:59:26 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/arena.h"

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