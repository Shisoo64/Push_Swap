/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:39:33 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/19 17:27:02 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	nbr;
	int		neg;
	int		i;

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

void	reset_index(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		tmp->id = 0;
		tmp = tmp->next;
	}
}

char	*strjoin_ps(char *s1, char *s2)
{
	char	*tab;
	int		longueur;

	if (!s2[0])
	{
		write(2, "Error\n", 6);
		free(s1);
		exit(0);
	}
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
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	freestacks(t_stacks *stacks)
{
	t_node	*tmp;

	while (stacks->a_head)
	{
		tmp = stacks->a_head;
		stacks->a_head = stacks->a_head->next;
		free(tmp);
	}
	while (stacks->b_head)
	{
		tmp = stacks->b_head;
		stacks->b_head = stacks->b_head->next;
		free(tmp);
	}
	exit(0);
}
