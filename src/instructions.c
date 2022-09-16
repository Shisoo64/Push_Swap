/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:52:19 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/13 15:52:20 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dst, char stack_id)
{
	t_node	*tmp;

	ft_printf("p%c\n", stack_id);
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	swap(t_node **head, char stack_id)
{
	t_node	*tmp;

	if (ft_lstsize_ps(*head) < 2)
		return ;
	ft_printf("s%c\n", stack_id);
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
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

void	reverse(t_node **head, char stack_id)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (ft_lstsize_ps(*head) < 2)
		return ;
	ft_printf("rr%c\n", stack_id);
	tmp = *head;
	tmp2 = *head;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *head;
	*head = tmp;
}
