/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:26:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:57:42 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (!fd)
		return ;
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-nb, fd);
	}	
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}

/* int main(void)
{
    ft_putnbr_fd(-0, 1);
	printf("\n");
	ft_putnbr_fd(0, 1);
	printf("\n");
	printf("\n");
	ft_putnbr_fd(-5, 1);
	printf("\n");
	ft_putnbr_fd(5, 1);
	printf("\n");
	printf("\n");
	ft_putnbr_fd(-19, 1);
	printf("\n");
	ft_putnbr_fd(19, 1);
	printf("\n");
	printf("\n");
	ft_putnbr_fd(-42, 1);
	printf("\n");
	ft_putnbr_fd(42, 1);
	printf("\n");
	printf("\n");
	ft_putnbr_fd(-7826, 1);
	printf("\n");
	ft_putnbr_fd(7826, 1);
	printf("\n");
	printf("\n");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n");
} */