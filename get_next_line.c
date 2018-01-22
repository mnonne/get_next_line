#include "get_next_line.h"

int		find_line(char **stack, char **line)
{
	char	*ptr;
	int		st;
	int		end;
	int		dif;

	st = 0;
	ptr = *stack;
	while (ptr[st] != '\n' && ptr[st] != '\0')
		st++;
	end = st;
	while (ptr[end] != '\0')
		end++;
	if (**stack != '\0')
	{
		*line = ft_strnew(st + 1);
		ft_memcpy(*line, *stack, st);
		if ((dif = end - st) == 0)
			ft_bzero(*stack, end);
		ft_memmove(*stack, *stack + st + 1, dif);
		while (dif++ < end)
			ptr[dif] = '\0';
		return (1);
	}
	return (0);
}

int		gnl_read(int fd, char **stack, char *heap, char **line)
{
	char	*tmp;
	int		ret;
	int		res;

	ft_bzero(heap, BUFF_SIZE + 1);
	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		if (*stack)
		{
			tmp = ft_strdup(*stack);
			free(*stack);
			*stack = ft_strjoin(tmp, heap);
			free(tmp);
		}
		else
			*stack = ft_strdup(heap);
		ft_bzero(heap, BUFF_SIZE + 1);
	}
	if (ret == -1)
		return (-1);
	res = find_line(stack, line);
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static char		*stack;
	char			*heap;
	int				ret;

	if (fd < 0 || !line || !(heap = (char *)malloc(sizeof(char) *
					BUFF_SIZE + 1)))
		return (-1);
	*line = NULL;
	ret = gnl_read(fd, &stack, heap, line);
	free(heap);
	return (ret);
}
