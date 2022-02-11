/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:28:57 by ydahni            #+#    #+#             */
/*   Updated: 2022/02/11 18:32:21 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
	}
}

void	frecuns(int c)
{
	static int	s;
	static int	i;

	if (c == SIGUSR1)
	{
		s += (1 << (7 - i));
	}
	i++;
	if (i == 8)
	{
		ft_putchar(s);
		i = 0;
		s = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, frecuns);
	signal(SIGUSR2, frecuns);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		;
}
