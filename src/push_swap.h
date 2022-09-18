/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <rlaforge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:10 by rlaforge          #+#    #+#             */
/*   Updated: 2022/09/16 15:38:15 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	int				data;
	int				id;
}				t_node;

typedef struct s_stacks
{
	t_node	*a_head;
	t_node	*b_head;
	int		len;
}				t_stacks;

void	push(t_node **src, t_node **dst, char stack_id);
void	swap(t_node **head, char stack_id);
void	reverse(t_node **head, char stack_id);
void	rotate(t_node **head, char stack_id);
long	ft_atol(const char *nptr);
void	print_stack(t_stacks *stacks);
void	parse(t_stacks *stacks, char **av);
int		ft_lstsize_ps(t_node *lst);
char	*strjoin_ps(char *s1, char *s2);
void	create_list(t_stacks *stacks, char **tab);
void	pre_sort_id(t_stacks *stacks);
void	newnode(t_node **head, int data, int id);
void	reset_index(t_node *head);
int		get_bitnbr(int size);
void	sort(t_stacks *stacks);
void	sort_ext(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_four_five(t_stacks *stacks);
void	freestacks(t_stacks *stacks);

#endif
