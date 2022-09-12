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

int check_args(char **tab)
{
    int i;
    int j;
    int x;

    i = 0;
	while (tab[++i])
    {
        if(ft_atol(tab[i]) < INT_MIN || ft_atol(tab[i]) > INT_MAX)
            return (1);
        j = -1;
        while (tab[i][++j])
            if(!ft_isdigit(tab[i][j]))
                return (1);
        x = i;
        while (tab[--x] && x > 0)
            if(ft_atoi(tab[x]) == ft_atoi(tab[i]))
                return (1);
    }
    return (0);
}

void    create_list(t_stacks *stacks, char **tab)
{
    int	i;

    i = 0;
    stacks->a_head = newnode(ft_atoi(tab[i]), 0);
    stacks->b_head = NULL;
	while (tab[++i])
        addback(&stacks->a_head, newnode(ft_atoi(tab[i]), 0));
    get_num_id(stacks);
}

char	*strjoin_ps(char *s1, char *s2)
{
	char	*tab;
	int		longueur;

	longueur = ft_strlen(s1) + ft_strlen(s2) + 2;
	tab = malloc(sizeof(char) * longueur);
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s1, longueur);
	if (s1[0] != '\0')
		ft_strlcat(tab, " ", longueur);
	ft_strlcat(tab, s2, longueur);
	free(s1);
	return (tab);
}

int	ft_lstsize_ps(t_node *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	parse(t_stacks *stacks, char **av)
{
	char	*str;
	char	**tab;
    int     i;

    i = 0;
    str = ft_calloc(sizeof(char), 1);
	while (av[++i])
		str = strjoin_ps(str, av[i]);
	tab = ft_split(str, ' ');
    free(str);
    if (check_args(tab))
    {
        write(2, "Error\n", 6);
	    exit (0);
    }
    create_list(stacks, tab);
    stacks->len = ft_lstsize_ps(stacks->a_head);
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