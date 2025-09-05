/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:19:31 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 19:35:22 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COST_H
# define COST_H

# include "double_stack.h"

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
}		t_cost;

t_cost	get_costs(t_double_stack *stack, int position_b, int index_b);

#endif