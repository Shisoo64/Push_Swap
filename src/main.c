/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:39:33 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/12 18:42:03 by rlaforge         ###   ########.fr       */
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
	if (!*head)
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

    ft_printf("\n*** SORTING THE STACKS ******\n\n");
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
        print_stack(stacks);
        tmpb = stacks->b_head;
        while (tmpb)
        {
            push(&stacks->b_head, &stacks->a_head, 'a');
            tmpb = stacks->b_head;
        }
        print_stack(stacks);
    }
    ft_printf("\n\n*** STACKS ARE SORTED ********\n\n");
}

int main(int ac, char **av)
{
	t_stacks	stacks;

    if (ac < 2)
        return (1);
    parse(&stacks, av);
    print_stack(&stacks);
    sort(&stacks);
}
