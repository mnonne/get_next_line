#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include "get_next_line.h"

int     main(int ac, char **av)
{
    int     fd;
    int     ret;
    int     line;
    char    *buff;

    line = 1;
    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        while ((ret = get_next_line(fd, &buff)) > 0)
        {
            printf("|Return val: %i| Line #%i |%s|\n", ret, line++, buff);
            free(buff);
        }
        if (ret == 0)
            {
                printf("|Return val: %i| Line #%i |%s|\n", ret, line++, buff);
                free(buff);
                printf("      THE END     \n");
            }
        if (ret == -1)
            printf("      ERROR      \n");
        close(fd);
    }
    if (ac == 1)
    {
        while ((ret = get_next_line(1, &buff)) >= 0)
            printf("|Return val: %i| Line #%i |%s|\n", ret, line++, buff);
        if (ret == -1)
            printf("      ERROR     \n");
        if (ret == 0)
            printf("      THE END      \n");
    }
    return (0);
}

/*int 	main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);

	//Read abc and new line
	gnl_ret = get_next_line(p[0], &line);
	printf("%s\n", line);
	printf("%d", strcmp(line, "abc"));
	assert(gnl_ret == 1);
	assert(strcmp(line, "abc") == 0);

	//Read new line
	gnl_ret = get_next_line(p[0], &line);
	printf("%s\n", line);
	assert(gnl_ret == 1);
	assert(line == NULL || *line == '\0');

	//Read again, but meet EOF
	gnl_ret = get_next_line(p[0], &line);
	printf("%s\n", line);
	assert(gnl_ret == 0);
	assert(line == NULL || *line == '\0');

	//Let's do it once again
	gnl_ret = get_next_line(p[0], &line);
	printf("%s\n", line);
	assert(gnl_ret == 0);
	assert(line == NULL || *line == '\0');
}*/
