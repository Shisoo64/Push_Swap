#include "push_swap.h"

void    pre_sort_id(t_stacks *stacks)
{
    t_node	*tmp;
    t_node	*tmpx;

    tmp = stacks->a_head;
    tmpx = stacks->a_head->next;
    while(tmp)
    {
        while(tmpx)
        {
            if(tmp->data > tmpx->data)
                tmp->id++;
            tmpx = tmpx->next;
        }
        tmp = tmp->next;
        tmpx = stacks->a_head;
    }
}

int check_args(char **tab)
{
    int i;
    int j;
    int x;

    i = 0;
	while (tab[++i])
    {
        if(ft_atol(tab[i]) < INT_MIN || ft_atol(tab[i]) > INT_MAX)
            return (1);
        j = -1;
        while (tab[i][++j])
            if(!ft_isdigit(tab[i][j]))
                return (1);
        x = i;
        while (tab[--x] && x > 0)
            if(ft_atoi(tab[x]) == ft_atoi(tab[i]))
                return (1);
    }
    return (0);
}

void    create_list(t_stacks *stacks, char **tab)
{
    int	i;

    i = -1;
    stacks->b_head = NULL;
	while (tab[++i])
        newnode(&stacks->a_head, ft_atoi(tab[i]), 0);
    pre_sort_id(stacks);
}

void	parse(t_stacks *stacks, char **av)
{
	char	*str;
	char	**tab;
    int     i;

    i = 0;
    str = ft_calloc(sizeof(char), 1);
	while (av[++i])
		str = strjoin_ps(str, av[i]);
	tab = ft_split(str, ' ');
    free(str);
    if (check_args(tab))
    {
        write(2, "Error\n", 6);
	    exit (0);
    }
    create_list(stacks, tab);
    stacks->len = ft_lstsize_ps(stacks->a_head);
}
