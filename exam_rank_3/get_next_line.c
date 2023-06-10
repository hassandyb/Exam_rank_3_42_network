

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 45

int ft_strlen(char *str)
{
	int i = 0;
	while(str && str[i])
		i++;
	return i;
}

int ft_check(char *stock)
{
	int i = 0;
	if(stock == NULL)
		return 0;
	while(stock[i])
	{
		if(stock[i] == '\n')
			return 1;
	}
	return 0;
}

char *ft_strjoin(char *stock, char *buffer)
{
	if(stock == NULL)
	{
		stock = malloc(sizeof(char));
		if(stock == NULL)
			return NULL;
		stock [0] = '\0';
	}
	char *temp = malloc((ft_strlen(stock) + ft_strlen(buffer) + 1) * sizeof(char));
	if(temp == NULL)
		return NULL;
	int i = 0;
	while(stock[i])
	{
		temp[i] = stock[i];
		i++;
	}
	int j = 0;
	while(buffer[j])
	{
		temp[i] = buffer[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	free (stock);
	return temp;
	

}

int ft_linelen(char *stock)
{
	int i = 0;
	while(stock[i])
	{
		if(stock[i] == '\n')
		{
			i++;
			return i;
		}
		i++;
	}
	return i;
}

char *ft_get_befor_newline(char *stock)
{
	if(stock == NULL || *stock == '\0')
		return NULL;
	int len = ft_linelen(stock);
	char *line = malloc((len + 1) * sizeof(char));
	int i = 0;
	while(stock[i])
	{
		if(stock[i] == '\n')
		{
			line[i] = stock[i];
			i++;
			break;
		}
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return line;
}

int ft_afterlinelen(char *stock)
{
	int i = 0;
	while(stock[i])
	{
		if(stock[i] == '\n')
			break;
		i++;
	}
	i++;
	int j = 0;
	while(stock[i])
	{
		j++;
		i++;
	}
	return j;
}

char *ft_get_after_newline(char *stock)
{

	if(stock == NULL || *stock == '\0')
		return NULL;
	if(ft_linelen(stock) == ft_strlen(stock))
		return NULL;
	int len = ft_afterlinelen(stock);
	char *temp = malloc((len + 1) * sizeof(char));
	if(temp == NULL)
		return NULL;
	int i = 0;
	while(stock[i])
	{
		if(stock[i] == '\n')
			break;
		i++;
	}
	i++;
	int j = 0;
	while(stock[i])
	{
		temp[j] = stock [i];
		j++;
		i++;
	}
	temp[i] = '\0';
	free(stock);
	return(temp);
	

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
	free(buffer);
	char *line = ft_get_befor_newline(stock);
	stock = ft_get_after_newline(stock);
	return (line);
}

// int main ()
// {
// 	int fd = open 
// }












