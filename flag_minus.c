/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:03:42 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/15 21:06:46 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precision(const char **format, t_vars *vars, va_list args)
{
	(*format)++;
	vars->isprecision = 1;
	while (**format == '0')
		(*format)++;
	if (ft_isdigit(**format))
	{
		vars->prec = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		vars->prec = va_arg(args, int);
		(*format)++;
	}
	else
		vars->prec = 0;
	if (vars->prec < 0)
		vars->prec = -1;
}

void			flag_minus(const char **format, t_vars *vars, va_list args)
{
	(*format)++;
	while (**format == '0' || **format == '-')
		(*format)++;
	vars->isnegative = 1;
	if (ft_isdigit(**format))
	{
		vars->wdth = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		vars->wdth = va_arg(args, int);
		if (vars->wdth < 0)
			vars->wdth *= -1;
		(*format)++;
	}
	if (**format == '.')
		ft_precision(format, vars, args);
}
