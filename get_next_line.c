#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	//static char	*cumulative_buffer;
	char	c[1];
	int	i;
	int	bytes_read;
	
	i = 0;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	c[0] = '0';
	while (c[0] != '\n')
	{
		while (i < BUFFER_SIZE)
		{
			bytes_read = read(fd, c, 1);
			if(bytes_read == -1)
			{
				printf("%d\n", bytes_read);
				free(buffer);
				return (NULL);
			}
			if (bytes_read == 0)
				break ;
			buffer[i++] = c[0];
		}
		if (i >= BUFFER_SIZE)
		{
			bytes_read = read(fd, c, 1);
			if(bytes_read == -1)
			{
				printf("%d\n", bytes_read);
				free(buffer);
				return (NULL);
			}
			if (bytes_read == 0)
				break ;
			buffer[i++] = c[0];
		}
	}
	if (i == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = 0;
	return (buffer);
}

int	main()
{
	int fd = open("prova.txt", O_RDONLY);
	char *buffer = get_next_line(fd); 
	printf("%s", buffer);
	free(buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	free(buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	free(buffer);
	//printf("%s", get_next_line(fd));
	//printf("%d", i);
	return 0;
}
