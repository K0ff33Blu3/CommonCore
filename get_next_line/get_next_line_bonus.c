#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;
	unsigned int	j;
	size_t			max_len;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	max_len = ft_strlen(s) - start;
	if (max_len > len)
		max_len = len;
	dst = (char *)malloc (sizeof(char) * (max_len + 1));
	if (!dst)
		return (NULL);
	while (s[i] && i < (unsigned char)start)
		i++;
	while (j < max_len)
	{
		dst[j] = s[i + j];
		j++;
	}
	dst[j] = 0;
	return (dst);
}

static char	*write_buffer(char *current_buffer, char *src)
{
	char	*new_buffer;

	if (!current_buffer)
	{
		new_buffer = ft_strdup(src);
		if (!new_buffer)
			return (free(src), NULL);
		return (new_buffer);
	}
	new_buffer = ft_strjoin(current_buffer, src);
	if (!new_buffer)
		return (free(src), current_buffer);
	free(current_buffer);
	return (new_buffer);
}

static char	*get_buffer(int fd, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	tmp = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	*tmp = '\0';
	while (!ft_strchr(tmp, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == 0)
			return (free(tmp), buffer);
		if (bytes_read < 0)
			return (free(tmp), free(buffer), NULL);
		tmp[bytes_read] = 0;
		buffer = write_buffer(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_next_buffer(char *current_buffer, char *new_line, unsigned int len)
{
	char	*new_buffer;

	new_buffer = ft_substr(current_buffer, len, ft_strlen(new_line));
	if (!*new_buffer)
	{
		free(new_buffer);
		new_buffer = NULL;
	}
	free(current_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[1024];
	char			*line;
	char			*new_line;
	unsigned int	len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = get_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	new_line = ft_strchr(buffer[fd], '\n');
	if (new_line)
	{
		new_line++;
		len = ft_strlen(buffer[fd]) - ft_strlen(new_line);
		line = ft_substr(buffer[fd], 0, len);
		buffer[fd] = get_next_buffer(buffer[fd], new_line, len);
	}
	else
	{
		line = ft_strdup(buffer[fd]);
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
/*
int main ()
{
	int fd_1 = open("test1.txt", O_RDONLY);
	int fd_2 = open("test2.txt", O_RDONLY);
	char	*line_1;
	char	*line_2;
	//int fd_3 = open("../files/43_no_nl.txt", O_RDONLY);
	int	i;

	i = 0;	
	while (1)
	{
		i++;
		printf("%i\n", i);
		if (i % 2)
		{
			line_1 = get_next_line(fd_1);
			printf("1: %s", line_1);
			if (!line_1)
			{
				free(line_1);
				//free(line_2);
				break;			
			}
			free(line_1);	
		}
		else
		{
			line_2 = get_next_line(fd_2);
			printf("2: %s", line_2);
			if (!line_2)
			{
				//free(line_1);
				free(line_2);
				break;			
			}
			free(line_2);	
		}
	}
	line_2 = get_next_line(fd_2);
	printf("2: %s", line_2);
	free(line_2);
	//line_2 = get_next_line(fd_2);
	//printf("2: %s", line_2);
	//free(line_2);
	return 0;
}
*/