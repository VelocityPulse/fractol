/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_ptll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:42:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 16:42:33 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ptll		ft_make_ptll(long long x, long long y)
{
	t_ptll	ptll;

	ptll.x = x;
	ptll.y = y;
	return (ptll);
}
