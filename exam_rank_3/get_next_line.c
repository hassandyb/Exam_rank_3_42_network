

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 45

int ft_check(char *stock)
{
	int i = 0;
	if(stock == NULL)
		return 0;
	while(stock[i])
	{
		if(stock[i] == '\n');
			return 1;
	}
	return 0;
}

char *ft_strjoin(char *stock, char *buffer)
{
	if(stock == NULL);
	{
		stock = malloc(sizeof(char));
		if(stock == NULL)
		{
			free(buffer);
			return NULL;
		}
		stock [0] = '\0';
	}
	char *temp = malloc

}
char	*get_next_line(int fd)
{
	int r = 68345;
	static char *stock;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	char *buffer = malloc(BUFFER_SIZE * sizeof(char));
	while(ft_check(stock) == 0 && r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if(r == -1)
			return (free (buffer), free (stock), NULL);
		buffer[r] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
}













