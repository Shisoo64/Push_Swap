/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:39:33 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/01 16:23:11 by rlaforge         ###   ########.fr       */
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
    ft_printf("*** Printing the stacks ******\n");
    ft_printf("*** A : * ");
	while (tmp)
    {
        ft_printf("%d * ", tmp->data);
		tmp = tmp->next;
    }
    tmp = stacks->b_head;
    ft_printf("\n*** B : * ");
	while (tmp)
    {
        ft_printf("%d * ", tmp->data);
		tmp = tmp->next;
    }
    ft_printf("\n******************************\n");
}

/* ALGO DE OUF :

i = -1;
x = -1;

    while (++x < 32)
    {
        while (++i != number of items)
        {
            if (item[i] >> x) & 1
                PB;
            else
                RA;
        }
        while (ya des item dans B)
            PA;
    }
    

*/
/*
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
    int bitnbr;

    ft_printf("\n***SORTING THE STACKS***\n\n");
    bitnbr = get_bitnbr(stacks->len);
    tmpa = stacks->a_head;
    x = -1;
    while (++x < bitnbr)
    {
        while (tmpa->next != NULL)
        {
            if ((tmpa->id >> x) & 1)
                pushfront(&stacks->a_head, &stacks->b_head, 'b');
            else
                rotate(&stacks->a_head, 'a');
            tmpa = stacks->a_head;
            print_stack(stacks);
        }
        tmpb = stacks->b_head;
        while (tmpb->next != NULL)
        {
            pushfront(&stacks->b_head, &stacks->a_head, 'a');
            tmpb = tmpb->next;
        }
        print_stack(stacks);
    }
    ft_printf("\n************************\n");
}
*/