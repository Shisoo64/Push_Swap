/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:31:06 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/19 17:41:06 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	t_node	*tmp;
	int		x;
	int		i;
	int		bitnbr;

	bitnbr = get_bitnbr(stacks->len);
	x = -1;
	while (++x < bitnbr)
	{
		i = -1;
		while (++i < stacks->len)
		{
			tmp = stacks->a_head;
			if (!tmp)
				break ;
			if ((tmp->id >> x) & 1)
				rotate(&stacks->a_head, 'a');
			else
				push(&stacks->a_head, &stacks->b_head, 'b');
		}
		sort_ext(stacks);
	}
}

void	sort_ext(t_stacks *stacks)
{
	t_node	*tmp;

	tmp = stacks->b_head;
	while (tmp)
	{
		push(&stacks->b_head, &stacks->a_head, 'a');
		tmp = stacks->b_head;
	}
}

void	sort_three(t_stacks *stacks)
{
	t_node	*tmp;

	tmp = stacks->a_head;
	if (tmp->id == 1 && tmp->next->id == 0)
		swap(&stacks->a_head, 'a');
	else if (tmp->id == 2 && tmp->next->id == 1)
	{
		swap(&stacks->a_head, 'a');
		reverse(&stacks->a_head, 'a');
	}
	else if (tmp->id == 2 && tmp->next->id == 0)
		rotate(&stacks->a_head, 'a');
	else if (tmp->id == 1 && tmp->next->id == 2)
		reverse(&stacks->a_head, 'a');
	else if (tmp->id == 0 && tmp->next->id == 2)
	{
		swap(&stacks->a_head, 'a');
		rotate(&stacks->a_head, 'a');
	}
}

void	sort_four_five(t_stacks *stacks)
{
	while (ft_lstsize_ps(stacks->a_head) > 3)
	{
		if (stacks->a_head->id == 0 || stacks->a_head->id == 1)
			push(&stacks->a_head, &stacks->b_head, 'b');
		else
			rotate(&stacks->a_head, 'a');
	}
	reset_index (stacks->a_head);
	pre_sort_id(stacks);
	sort_three(stacks);
	push (&stacks->b_head, &stacks->a_head, 'a');
	if (stacks->len > 4)
		push (&stacks->b_head, &stacks->a_head, 'a');
	if (stacks->a_head->data > stacks->a_head->next->data)
		swap(&stacks->a_head, 'a');
}
