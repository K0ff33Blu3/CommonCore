#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define DEFAULT_BUFFER_SIZE 1024
#define BUFFER_SIZE DEFAULT_BUFFER_SIZE
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);

#endif
