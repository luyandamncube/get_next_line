
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>
#include <string.h>

int		main(int ac, char *av[])
{
	int		fd;
	int		strbuf;
	char	*line;
	int i = 0;

	(void) ac;
	fd = open(av[1], O_RDONLY, 0700);
	line = NULL;
	while ((strbuf = get_next_line(fd, &line)) == 1)
	{
		//printf("%d\n", strbuf);
		printf("\n|%d| <%s>\n",i, line);
		i++;
	}
	//	strbuf = get_next_line(fd, &line);
	//	printf("%s\n", line);
	close(fd);
	return 0;
}