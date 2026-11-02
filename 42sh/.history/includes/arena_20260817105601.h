/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:50:10 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 10:56:01 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define ARENA_SIZE 1e

typedef struct s_Arena
{
    unsigned char *buffer;
    size_t capacity;
    size_t offset;      
} Arena;

Arena arena_init(size_t capacity);
void *arena_alloc(Arena *a, size_t size);
void arena_free(Arena *a);
