#include <stdio.h>
#include "fillit.h"
#include <fcntl.h>

int main() {
	char line[21];
	int fd;

	fd = open("1",O_RDONLY);

	read(fd, line, 546);
	printf("%d\n",validation(line));
	close(fd);
    return 0;
}
