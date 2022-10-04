/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:39:33 by rlaforge          #+#    #+#             */
/*   Updated: 2022/10/04 16:10:55 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	newnode(t_node **head, int data, int id)
{
	t_node	*node;
	t_node	*tmp;

	node = malloc(sizeof(t_node));
	if (node)
	{
		node->data = data;
		node->id = id;
		node->next = NULL;
	}
	if (!*head || !head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

int	get_bitnbr(int size)
{
	int	bitnbr;
	int	bit_pow;

	bit_pow = 1;
	bitnbr = 0;
	while ((size / bit_pow) != 0)
	{
		bit_pow *= 2;
		bitnbr++;
	}
	return (bitnbr);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	sorted(int ac, char **av)
{
	int	i;

	i = -1;
	while (++i != ac - 1)
		if (ft_atol(av[i]) > ft_atol(av[i + 1]))
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		return (1);
	if (sorted(ac, av))
		return (0);
	parse(&stacks, av);
	if (!stacks.a_head->next)
		freestacks(&stacks);
	if (stacks.len > 5)
		sort(&stacks);
	else if (stacks.len == 5 || stacks.len == 4)
		sort_four_five(&stacks);
	else if (stacks.len == 3)
		sort_three(&stacks);
	else if (stacks.a_head->data > stacks.a_head->next->data)
		rotate(&stacks.a_head, 'a');
	freestacks(&stacks);
}
