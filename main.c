#include <stdio.h>
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
        while ((ret = get_next_line(fd, &buff)) >= 0)
        {
            printf("|Return val: %i| Line #%i |%s|\n", ret, line++, buf);
            free(buff);
        }
        if (ret == -1)
            printf("      ERROR     \n");
        if (ret == 0)
            printf("      THE END      \n");
        close(fd);
    }
    if (ac == 1)
    {
        while ((ret = get_next_line(1, &buff)) >= 0)
            printf("|Return val: %i| Line #%i |%s|\n", ret, line++, buf);
        if (ret == -1)
            printf("      ERROR     \n");
        if (ret == 0)
            printf("      THE END      \n");
    }
    return (0);
}
