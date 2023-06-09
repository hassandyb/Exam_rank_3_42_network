#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void ft_putstr(char *str, int *len)
{
	int i = 0;
	if(str == NULL)
	{
		char *s = "(null)";
		while(s[i])
		{
			*len = *len + write(1, &s[i], 1);
			i++;
		}
		return ;
	}
	while(str[i])
	{
		*len = *len + write(1, &str[i],1);
		i++;
	}
}

void ft_putnbr_base(int nbr, int base, int *len)
{
	char *base_ref = "0123456789abcdef";
	if(nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if(nbr >= base)
		ft_putnbr_base(nbr / base, base, len);
	*len = *len + write(1, &base_ref[nbr % base], 1);
}

int ft_printf(const char *str, ... )
{
	int len = 0;
	va_list args;
	va_start(args, str);
	va_end(args);
	int i = 0;
	while(str[i])
	{
		if(str[i] == '%' && (str[i+1] == 'x' || str[i+1] == 'd' || str[i+1] == 's'))
		{
			i++;
			if(str[i] == 's')
				ft_putstr(va_arg(args, char *), &len);
			if(str[i] == 'd')
				ft_putnbr_base(va_arg(args, int), 10,&len);
			if(str[i] == 'x')
				ft_putnbr_base(va_arg(args, int), 16, &len);
		}
		else if(str[i] == '\0')
			break ;
		else
		{
			write(1, &str[i],1);
			len++;
		}
		i++;
	}
	return len;
}

int main ()
