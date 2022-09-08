/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:39:33 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/07 17:21:53 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*newnode(int data, int id)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node)
	{
		node->data = data;
        node->id = id;
		node->next = NULL;
	}
	return (node);
}

void	pushfront(t_node **src, t_node **dst, char stack_id)
{
    t_node	*tmp;


    ft_printf("p%c\n", stack_id);
    tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
    *src = tmp;
}

void	rotate(t_node **head, char stack_id)
{
    t_node	*tail;
    t_node	*tmp;

	if (!*head || !(*head)->next)
		return ;
    ft_printf("r%c\n", stack_id);
    tail = *head;
    tmp = *head;
    *head = (*head)->next;
    while (tail->next)
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
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
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
                pushfront(&stacks->a_head, &stacks->b_head, 'b');
            tmpa = stacks->a_head;
        }
        print_stack(stacks);
        tmpb = stacks->b_head;
        while (tmpb)
        {
            pushfront(&stacks->b_head, &stacks->a_head, 'a');
            tmpb = stacks->b_head;
        }
        print_stack(stacks);
    }
    ft_printf("\n\n*** STACKS ARE SORTED ********\n\n");
}

int check_args(int ac, char **av)
{
    int i;
    int j;
    int x;

    i = 0;
	while (++i != ac)
    {
        if(ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX)
            return (1);
        j = -1;
        while (av[i][++j])
            if(!ft_isdigit(av[i][j]))
                return (1);
        x = i;
        while (av[--x] && x > 0)
            if(ft_atoi(av[x]) == ft_atoi(av[i]))
                return (1);
    }
    return (0);
}

void    get_num_id(t_stacks *stacks)
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

void    create_list(t_stacks *stacks, int ac, char **av)
{
    int	i;

    i = 0;
    stacks->len = ac - 1;
    stacks->a_head = newnode(ft_atoi(av[i + 1]), 0);
    stacks->b_head = NULL;
	while (++i != stacks->len)
        addback(&stacks->a_head, newnode(ft_atoi(av[i + 1]), 0));
    get_num_id(stacks);
}

int main(int ac, char **av)
{
	t_stacks	stacks;
    
	if (check_args(ac, av))
    {
        ft_printf("Error\n");
        return (1);
    }
    create_list(&stacks, ac, av);
    print_stack(&stacks);
    sort(&stacks);
}