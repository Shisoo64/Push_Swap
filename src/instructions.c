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
