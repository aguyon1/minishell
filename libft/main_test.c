#include <fcntl.h>
#include <stdio.h>
#include <assert.h>
#include "../../inc/libft.h"

int main(void)
{
	int fd = open("test", O_RDONLY);
	char *line;

	assert(fd > 0);
	for (int i = 1; line = get_next_line(fd); i++)
	{
		printf("%i : %s", i, line);
		free(line);
	}
}
