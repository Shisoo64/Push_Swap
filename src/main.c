/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:39:33 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/13 18:47:21 by rlaforge         ###   ########.fr       */
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

int    get_bitnbr(int size)
{
    int bitnbr;
    int bit_pow;

    bit_pow = 1;
    bitnbr = 0;
    while ((size / bit_pow) != 0)
    {
        bit_pow *= 2;
        bitnbr++;
    }
    return (bitnbr);
}

void    sort(t_stacks *stacks)
{
	t_node	*tmpa;
	t_node	*tmpb;
    int x;
    int i;
    int bitnbr;

    bitnbr = get_bitnbr(stacks->len);
    x = -1;
    while (++x < bitnbr)
    {
        i = -1;
        tmpa = stacks->a_head;
        while (++i < stacks->len)
        {
            if (!tmpa)
                break;
            if ((tmpa->id >> x) & 1)
                rotate(&stacks->a_head, 'a');
            else
                push(&stacks->a_head, &stacks->b_head, 'b');
            tmpa = stacks->a_head;
        }
        tmpb = stacks->b_head;
        while (tmpb)
        {
            push(&stacks->b_head, &stacks->a_head, 'a');
            tmpb = stacks->b_head;
        }
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
    reset_index(stacks->a_head);
	pre_sort_id(stacks);
	sort_three(stacks);
    push(&stacks->b_head, &stacks->a_head, 'a');
    if (ft_lstsize_ps(stacks->a_head) == 5)
        return ; 
    push(&stacks->b_head, &stacks->a_head, 'a');
	if (stacks->a_head->id > stacks->a_head->next->id)
		swap(&stacks->a_head, 'a');
}

int main(int ac, char **av)
{
	t_stacks	stacks;

    if (ac < 3)
        return (1);
    parse(&stacks, av);
    if(ac > 6)
        sort(&stacks);
    else if (ac == 5 || ac == 6)
        sort_four_five(&stacks);
    else if (ac == 4)
        sort_three(&stacks);
    else if (stacks.a_head->data > stacks.a_head->next->data)
        rotate(&stacks.a_head, 'a');


    print_stack(&stacks);
}
