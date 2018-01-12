#include "get_next_line.h"

int     get_next_line(const int fd, char **line)
{
    static t_lst    *stack;
    char            *heap;

    if (!line || fd < 0 || !(heap = (char *)malloc(sizeof (char) * (BUFF_SIZE + 1))))
        return (-1);
    
}
