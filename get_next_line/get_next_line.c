#include "get_next_line.h"

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

char	*get_next_buffer(char *current_buffer, char *new_line, unsigned long len)
{
	char	*new_buffer;

	new_buffer = ft_substr(current_buffer, len, ft_strlen(new_line));
	printf("current_buffer: %s\n", current_buffer);
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
	static char		*buffer;
	char			*line;
	char			*new_line;
	unsigned long	nl_position;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	new_line = ft_strchr(buffer, '\n');
	printf("buffer: %s\n", buffer);
	if (new_line)
	{
		printf("new_line: %s\n", new_line);
		nl_position = new_line - buffer;
		line = ft_substr(buffer, 0, nl_position + 1);
		printf("nl_position: %i\n", nl_position);
		buffer = get_next_buffer(buffer, new_line, nl_position);
		printf("buffer..: %s\n", buffer);
	}
	else
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

int	main()
{
	int fd = open("test1.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("string: %s", line);
		free(line);
	}
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
