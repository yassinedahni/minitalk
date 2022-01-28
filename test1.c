#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void couvert(char c)
{
    int a;
    int b;
    
    a = 7;
    while (a >= 0)
    {
        b = ((c >> a) & 1);
        if (b == 1)
            ft_putchar(1);
        else
            ft_putchar(0);
        a--;
    }
}
int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            couvert(av[1][i]);
            i++;
        }
    }
}