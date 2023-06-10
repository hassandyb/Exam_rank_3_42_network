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

void ft_putnbr_base10(int nbr, int base, int *len)
{
	long n;

	n = nbr;
	char *base_ref = "0123456789abcdef";
	if(n < 0)
	{
		n *= -1;
		*len += write(1, "-", 1);
	}
	if(n >= base)
		ft_putnbr_base10(n / base, base, len);
	*len = *len + write(1, &base_ref[n % base], 1);
}

void ft_putnbr_base16(unsigned int nbr, int base, int *len)
{
	long n;

	n = nbr;
	char *base_ref = "0123456789abcdef";
	if(n >= base)
		ft_putnbr_base16(n / base, base, len);
	*len = *len + write(1, &base_ref[n % base], 1);
}

int ft_printf(const char *str, ... )
{
	int len = 0;
	va_list args;
	va_start(args, str);
	int i = 0;
	while(str[i])
	{
		if(str[i] == '%' && (str[i+1] == 'x' || str[i+1] == 'd' || str[i+1] == 's'))
		{
			i++;
			if(str[i] == 's')
				ft_putstr(va_arg(args, char *), &len);
			if(str[i] == 'd')
				ft_putnbr_base10(va_arg(args, int), 10,&len);
			if(str[i] == 'x')
				ft_putnbr_base16(va_arg(args, unsigned int), 16, &len);
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
	
	va_end(args);
	return len;
}

// int main(int argc, char const *argv[])
// {
// 		ft_printf("%d\n", (int)-2147483649);
// 		printf("%d\n", (int)-2147483649);
// 	// ft_printf("%d\n", (int)-2147483648);
// 	return 0;
// }

