/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:39:33 by rlaforge          #+#    #+#             */
/*   Updated: 2022/08/30 16:26:22 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_node *head_a, t_node *head_b)
{
    t_node	*tmp;

    tmp = head_a;
    ft_printf("***Printing the stacks***\n\n");
    ft_printf("Stack A :  ");
	while (tmp->next != NULL)
    {
        ft_printf("%d * ", tmp->data);
		tmp = tmp->next;
    }
    ft_printf("%d\n\n", tmp->data);
    tmp = head_b;
    ft_printf("Stack B :  ");
	while (tmp->next != NULL)
    {
        ft_printf("%d * ", tmp->data);
		tmp = tmp->next;
    }
    ft_printf("%d\n\n", tmp->data);
}

t_node	*newnode(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node)
	{
		node->data = data;
		node->next = NULL;
	}
	return (node);
}

void	pushfront(t_node **head, t_node **new)
{
    t_node	*tmp;
    tmp = (*new)->next;
	(*new)->next = *head;
	*head = *new;
    *new = tmp;
}

void	addback(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!head || !*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	swapstacks(t_node **head_a, t_node **head_b)
{
    while ((*head_a)->next != NULL)
        pushfront(head_b, head_a);
}

int main(int ac, char **av)
{
	t_stacks	stacks;
	int	i;

	i = 1;
    stacks.len = ac;
    stacks.a_head = newnode(ft_atoi(av[1]));
    stacks.b_head = newnode(0);
	while (++i != stacks.len)
        addback(&stacks.a_head, newnode(ft_atoi(av[i])));
    print_stack(stacks.a_head, stacks.b_head);
    swapstacks(&stacks.a_head, &stacks.b_head);
    print_stack(stacks.a_head, stacks.b_head);
    swapstacks(&stacks.b_head, &stacks.a_head);
    print_stack(stacks.a_head, stacks.b_head);
}