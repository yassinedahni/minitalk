#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	unsigned long	r;
	int				i;
	int				c;

	i = 0;
	r = 0;
	c = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (r > 9223372036854775807 && c == -1)
		return (0);
	else if (r >= 9223372036854775807 && c == 1)
		return (-1);
	return (c * r);
}

void couvert(int pid, char c)
{
    int a;
    int b;
    
    a = 7;
    while (a >= 0)
    {
        b = ((c >> a) & 1);
        if (b == 1)
        {
            kill(pid, SIGUSR1);
        }

        else
        {
            kill(pid, SIGUSR2);
        }
        usleep(500);
        a--;
    }
}
int main(int ac, char **av)
{
    int i;

    i = 0;
    int pid;
    if (ac == 3)
    {
        pid = ft_atoi(av[1]);
        while (av[2][i])
        {
            couvert(pid, av[2][i]);
            i++;
        }
    }
    write(1, "\n", 1);
}