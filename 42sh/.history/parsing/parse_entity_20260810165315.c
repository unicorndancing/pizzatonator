/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entity_20260810165315.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:34:11 by mlapique          #+#    #+#             */
/*   Updated: 2026/08/17 17:57:44 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

int parse_entity(char *entity, Arena *arena)
{
    entity[ft_strlen(entity)] = '\0';
    tokenizer(entity + 1, arena);
    return 0;
}