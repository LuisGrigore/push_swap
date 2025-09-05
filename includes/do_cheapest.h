/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cheapest.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:08:46 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 19:11:36 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_CHEAPEST_H
# define DO_CHEAPEST_H

# include "double_stack.h"

typedef struct s_cost
{
	int		cost_a;
	int		cost_b;
}			t_cost;

typedef struct s_current_cheapest
{
	t_cost	costs;
	int		cheapest_index;
}			t_current_cheapest;

void		do_cheapest(t_double_stack *stack);

#endif