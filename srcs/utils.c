#include "push_swap.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		exit(1);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
}

void	del(void *content)
{
	free(content);
}
