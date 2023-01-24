/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quatmath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsusanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:48:14 by fsusanna          #+#    #+#             */
/*   Updated: 2023/01/23 11:12:04 by fsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_quaternion	q_add(t_quaternion q1, t_quaternion q2)
{
	q1.r += q2.r;
	q1.i += q2.i;
	q1.j += q2.j;
	q1.k += q2.k;
	return (q1);
}

t_quaternion	q_by(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	ret;

	ret.r = q1.r * q2.r - q1.i * q2.i - q1.j * q2.j - q1.k * q2.k;
	ret.i = q1.r * q2.i + q1.i * q2.r + q1.j * q2.k - q1.k * q2.j;
	ret.j = q1.r * q2.j + q1.j * q2.r + q1.k * q2.i - q1.i * q2.k;
	ret.k = q1.r * q2.k + q1.k * q2.r + q1.i * q2.j - q1.j * q2.i;
	return (ret);
}

t_quaternion	q_star(t_quaternion q)
{
	q.i *= -1;
	q.j *= -1;
	q.k *= -1;
	return (q);
}

t_quaternion	q_by_scalar(t_quaternion q1, double s)
{
	q1.r *= s;
	q1.i *= s;
	q1.j *= s;
	q1.k *= s;
	return (q1);
}

double	norm2(t_quaternion z)
{
	return (z.r*z.r + z.i * z.i);
}

void	iter(t_quaternion *zc)
{
	t_quaternion	tmp;

	tmp = *zc;
	zc->r = tmp.r * tmp.r - tmp.i * tmp.i + tmp.j;
	zc->i = tmp.r * tmp.i * 2 + tmp.k;
}
