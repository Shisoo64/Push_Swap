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