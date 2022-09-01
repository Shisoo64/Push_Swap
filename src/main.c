/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:39:33 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/01 17:14:54 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stacks *stacks)
{
    t_node	*tmp;

    tmp = stacks->a_head;
    ft_printf("\n***Printing the stacks***\n");
    ft_printf("Stack A : * ");
	while (tmp != NULL)
    {
        ft_printf("%d * ", tmp->data);
		tmp = tmp->next;
    }
    tmp = stacks->b_head;
    ft_printf("\nStack B : * ");
	while (tmp != NULL)
    {
        ft_printf("%d * ", tmp->data);
		tmp = tmp->next;
    }
    ft_printf("\n*************************\n\n");
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

void	pushfront(t_node **src, t_node **dst, char id)
{
    t_node	*tmp;


    ft_printf("p%c\n", id);
    tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
    *src = tmp;
}

void	rotate(t_node **head, char id)
{
    t_node	*tail;
    t_node	*tmp;

	if (!*head || !(*head)->next)
		return ;
    ft_printf("r%c\n", id);
    tail = *head;
    tmp = *head;
    *head = (*head)->next;
    while (tail->next != NULL)
		tail = tail->next;
    tmp->next = NULL;
    tail->next = tmp;
}

void	addback(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	swapstacks(t_node **head_a, t_node **head_b)
{
    while (*head_a != NULL)
        pushfront(head_a, head_b, 'b');
}

void    sort(t_stacks *stacks)
{
	t_node	*tmpa;
	t_node	*tmpb;
    int x;
    int i;


    ft_printf("\n***SORTING THE STACKS***\n\n");
    x = -1;
    while (++x < 32)
    {
        i = -1;
        tmpa = stacks->a_head;
        while (++i < stacks->len)
        {
            if (!tmpa)
                break;
            if ((tmpa->data >> x) & 1)
                rotate(&stacks->a_head, 'a');
            else   
                pushfront(&stacks->a_head, &stacks->b_head, 'b');
            tmpa = stacks->a_head;
            print_stack(stacks);
        }
        tmpb = stacks->b_head;
        while (tmpb != NULL)
        {
            pushfront(&stacks->b_head, &stacks->a_head, 'a');
            tmpb = stacks->b_head;
        }
        print_stack(stacks);
    }
    ft_printf("\n************************\n");
}

int main(int ac, char **av)
{
	t_stacks	stacks;
	int	i;

	i = 1;
    stacks.len = ac;
    stacks.a_head = newnode(ft_atoi(av[1]));
    stacks.b_head = NULL;
	while (++i != stacks.len)
        addback(&stacks.a_head, newnode(ft_atoi(av[i])));
    print_stack(&stacks);
    /*swapstacks(&stacks.a_head, &stacks.b_head);
    print_stack(&stacks);
    swapstacks(&stacks.b_head, &stacks.a_head);
    print_stack(&stacks);
    rotate(&stacks.a_head, 'a');
    print_stack(&stacks);*/
    sort(&stacks);
    print_stack(&stacks);
}