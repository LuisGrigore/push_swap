/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:44:39 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 20:50:19 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "double_stack.h"

void		ft_putstr(char *str);
long int	ft_atoi(const char *str);
int			abs(int nb);
int			is_digit(char c);
void		error(t_double_stack *stack);

#endif