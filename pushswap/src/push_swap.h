/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:25:53 by alprival          #+#    #+#             */
/*   Updated: 2022/08/06 16:31:13 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_push_swap
{
	int	len;
	int	*tab_a;
	int	*end_tab;
}	t_push_swap;

typedef struct s_data
{
	int				value;
	struct s_data	*next;
	struct s_data	*preview;
}	t_data;

t_data	*ft_d_lstlast(t_data *lst);
void	ft_sa(t_data **list_a);
void	ft_sb(t_data **list_b);
void	ft_ss(t_data **list_b, t_data **list_a);
void	ft_pa(t_data **list_a, t_data **list_b);
void	ft_pb(t_data **list_a, t_data **list_b);
void	ft_ra(t_data **list_a);
void	ft_better_tab(t_push_swap *vars);
void	ft_rb(t_data **list_b);
int		*ft_new_tab(t_push_swap *vars);
void	ft_sort_five(t_data **list_a, t_push_swap *vars, t_data **list_b);
void	ft_sort_three(t_data **list_a);
void	ft_sort_two_a(t_data **list_a);
void	ft_sort_two_b(t_data **list_b);
void	ft_sort(t_data **list_a, t_data **list_b);
t_data	*ft_d_lstnew(int content);
void	ft_d_lstadd_back(t_data *list, t_data *new);
int		ft_atoi_push(const char *nptr, t_push_swap *vars, t_data **list_a);
void	ft_free_without_list(t_push_swap *vars);
void	ft_rr(t_data **list_a, t_data **list_b);
void	ft_rra(t_data **list_a);
void	ft_rrb(t_data **list_b);
void	ft_init_tab(int ac, t_push_swap *vars, char **av, t_data **list_a);
void	ft_rrr(t_data **list_a, t_data **list_b);
void	ft_check_doublon(t_push_swap *vars, t_data **list_a);
void	ft_free(t_push_swap *vars, t_data **list_a);
int		ft_atoi(const char *nptr);
void	ft_init_tab_ac_two(char *av, int ac, t_push_swap *vars, t_data **list_a);
void	error(t_push_swap *vars);
#endif
