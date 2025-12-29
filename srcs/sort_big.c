/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:18:17 by ayua              #+#    #+#             */
/*   Updated: 2025/12/29 14:42:09 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* 1. Dividir el monto de 100 índices en bloques de 5: 
-     de 0 a 19 - 20 a 39 - 40 a 59 - 60 a 79 - 80 a 99
 2. Buscar el índice mayor de este bloque y pasarlo a B con las reglas de Heap
 3. Repetir con todos los bloques hasta que A esté vacía
 4. Pasar B a A con la lógica del índice mayor y el menor número de movimientos.
*/
/*

indices stack: 0 ........ 99
indice chunk: 0 a 9

mientras i_chunk < 9
	busco el índice menor en el stack
	lo paso a B
	actualizo el indice menor.
	aumento el i_chunk;

*/


void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	i_chunk; // debe recorrer los índices cada 10 iteraciones
	int	index_min;
	while (stack_a->bottom != NULL)
	{
		index_min = set_index_min(stack_a);
		i_chunk = 0;
		while (i_chunk < 10)
		{
			min_moves(stack_a, stack_b, index_min);
			index_min = set_index_min(stack_a);
			i_chunk++;
		}
	}
	while (stack_b->top != NULL)
	{
		push(stack_b, stack_a);
	}
}
