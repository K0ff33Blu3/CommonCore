/*					---		CONFRONTO TRA BUFFERSIZE		---							*/
/**/

#include "get_next_line.h"

char	*get_buffer(int fd, char *buffer)
{
	char	*tmp;
	int	bytes_read;
	
	buffer = ft_strdup("");
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(tmp, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*extract_line(static char *buffer)
{
	char	*line;
	
	while(buffer[i] != '\n')
		i++;
	line = ft_memcpy(line)
	
		
		

char	*get_next_line(int fd)
{
	static char	*buffer;
	//char	*line;
	
	if (fd == -1 || fd == 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	return (buffer);
}

int	main()
{
	int	fd;
	char	*line;
	
	fd = open("prova.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	printf("test\n");
	line = get_next_line(fd);
	printf("line: %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line: %s\n", line);
	return 0;
}

