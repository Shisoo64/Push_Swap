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

long	ft_atol(const char *nptr)
{
	long	nbr;
	int	neg;
	int	i;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		i++;
		neg = -neg;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		nbr = nbr * 10 + (nptr[i++] - '0');
	return (nbr * neg);
}

void print_stack(t_stacks *stacks)
{
    t_node	*tmp;

    tmp = stacks->a_head;
    ft_printf("\n***Printing the stacks***\n");
    ft_printf("Stack A : * ");
	while (tmp)
    {
        ft_printf("%d * ", tmp->data);
		tmp = tmp->next;
    }
    tmp = stacks->b_head;
    ft_printf("\nStack B : * ");
	while (tmp)
    {
        ft_printf("%d * ", tmp->data);
		tmp = tmp->next;
    }
    ft_printf("\n*************************\n\n");
}

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
        }
        tmpb = stacks->b_head;
        while (tmpb)
        {
            pushfront(&stacks->b_head, &stacks->a_head, 'a');
            tmpb = stacks->b_head;
        }
        print_stack(stacks);
    } 
    ft_printf("\n************************\n");
}

void Sort_int(int *num, int ac)
{
    int i;
    int j;
    int temp;

    i = -1;
    while (++i < ac)
    {
        j = -1;
        while (++j < ac - i)
        {
            if (num[j] > num[j + 1])
            {
                temp = num[j + 1];
                num[j + 1] = num[j];
                num[j] = temp;
            }
        }
    }
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

void    create_list(t_stacks *stacks, int ac, char **av)
{
    int	i;
    int *num;
    //int *id_list;

    // put the numbers in an int array
	i = -1;
    stacks->len = ac - 1;
    num = malloc(sizeof(int) * (stacks->len));
    //id_list = malloc(sizeof(int) * (stacks->len));
    while (++i != stacks->len)
        num[i] = ft_atoi(av[i + 1]);
    // sort the int array
    Sort_int(num, stacks->len - 1);
    // put the numbers and id in a linked-list
    i = 0;
    stacks->a_head = newnode(ft_atoi(av[i + 1]), i);
    stacks->b_head = NULL;
	while (++i != stacks->len)
        addback(&stacks->a_head, newnode(ft_atoi(av[i + 1]), i));
    free(num);
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
    print_stack(&stacks);
}