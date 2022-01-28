#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_putnbr(int nbr)
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


void frecuns(int c)
{
    static int s;
    static int i;

    if (c == SIGUSR1)
        s += (1 << (7 - i));
    i++;
    if (i == 8)
    {
        ft_putchar(s);
        i = 0;
        s = 0;
    }
}

int main()
{
    signal(SIGUSR1, frecuns);
    signal(SIGUSR2, frecuns);
    ft_putnbr(getpid());
    while (1);
    return 0;
}