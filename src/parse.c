/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:52:29 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/13 15:52:31 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int check_digit(char *tab)
{
    int i;

    i = -1;

    if (tab[0] == '\0' || !tab)
		return (1);
	while (tab[++i])
	{
		if (tab[i] == ' ' && tab[i + 1] == ' ')
			i++;
		else if ((tab[i] == '-' || tab[i] == '+')
			&& (tab[i + 1] < 48 || tab[i + 1] > 57))
			return (1);
		else if ((tab[i] < 48 || tab[i] > 57)
			&& (tab[i] != '-' && tab[i] != '+') && tab[i] != ' ')
			return (1);
		else if ((tab[i] >= 48 && tab[i] <= 57)
			&& (tab[i + 1] == '-' || tab[i + 1] == '+'))
			return (1);
	}
    return (0);
}

int check_args(char **tab)
{
    int i;
    int x;

    i = 0;
	while (tab[++i])
    {
        if(ft_atol(tab[i]) < INT_MIN || ft_atol(tab[i]) > INT_MAX)
            return (1);
        if(check_digit(tab[i]))
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
