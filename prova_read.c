#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main()
{
	char *buffer = (char *)malloc(1024 * sizeof(char));
	char c[1];
	int i = 0;
	int fd = open("prova.txt", O_RDONLY | O_EXCL);
	while (c[0] != '\n')
	{
		read(fd, c, 1);
		buffer[i] = c[0];
		printf("buffer: %s\n", buffer);
		i++;
	}
	printf("\nbuffer: %s\n", buffer);
	*buffer = 0;
	return 0;
}
