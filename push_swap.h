/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:06 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

int		check_sorted(t_list **stack_a);
int		push_swap_strlen(char *str);
void	free_tab(char **tab);
void	check_error_arg(char **av);
int		is_numeric(char *str);
void	free_atoi(t_list **stack, char **argv, int size);
int		ft_atoi(const char *str, t_list **stack, char **argv, int size);
void	sort_list(t_list **stack_a, t_list **stack_b, int size);
int		initialize_list(t_list **stack_a, int argc, char **argv, int size);
int		check_duplicate(t_list *stack_a, int value);
void	check_inverted(t_list **stack_a, int argc);
void	delete_list(t_list **stack);

void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	free_tab(char **tab);
void	check_arguments(int argc, char **argv, t_list **stack_a);
void	move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int len);
void	move_to_a(t_list **stack_a, t_list **stack_b);
int		find_best_position_b(t_list **stack_b, int size_b,
			t_list **stack_a, int size_a);
int		move_remaining_numbers(t_list *stack_a, int size, int *arr, int len);
int		find_best_combination(int *arr_a, int *arr_b, int size);
int		find_best_combination_helper(int *arr_a, int *arr_b,
			int *tmp, int size);
int		push_min_to_top(int a, int b, t_list **stack_a, t_list **stack_b);
void	search_min(t_list **stack_a, int size);

int		*copy_stack_number(t_list *stack_a, int size);
int		*copy_int_array(int	*arr, int size);

int		count_moves(int min, int len, int size);
int		count_moves_a(t_list *stack_a, int nb, int size);
int		count_moves_b(int len, int size);
int		max_number(int a, int b);
int		min_number(int a, int b);
int		max_or_min(t_list *stack_a, int nb, int size);
int		return_max_or_min(int nb, int *len_n_min, int size);

int		*construct_lis(int *stack_numbers,
			int *prev, int lis_length, int end_index);
int		find_max_lis_length(int *lis, int size, int *end_index);
void	update_lis_and_prev(int *lis, int *prev, int *stack_numbers, int size);
void	initialize_lis_and_prev(int *lis, int *prev, int size);
int		*define_lis(int *stack_numbers, int size, int *len);
int		*find_lis_and_len(int *stack_numbers, int size, int *len);

int		check_len(char *str);
void	check_free_tab(char **tab);
int		check_numeric(char *str);
int		check_atoi(const char *str, t_list **stack, char **argv, int size);
void	check_error_args(char **av);
void	check_args3(int argc, char **argv, t_list **stack_a);
void	check_delete_list(t_list **stack);
int		check_dup(t_list *stack_a, int check);
void	check_instruction(t_list **stack_a, t_list **stack_b, char *str);
void	check_instruction_rrr(t_list **stack_a, t_list **stack_b, char *str);
int		check_list(t_list **stack_a, int argc, char **argv, int size);
int		ok_or_ko(t_list **stack_a);
void	swap_a_check(t_list **stack_a);
void	swap_b_check(t_list **stack_b);
void	swap_s_check(t_list **stack_a, t_list **stack_b);
void	push_a_check(t_list **stack_b, t_list **stack_a);
void	push_b_check(t_list **stack_a, t_list **stack_b);
void	rotate_a_check(t_list **stack_a);
void	rotate_b_check(t_list **stack_b);
void	rotate_r_check(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a_check(t_list **stack_a);
void	reverse_rotate_b_check(t_list **stack_b);
void	reverse_rotate_r_check(t_list **stack_a, t_list **stack_b);

#endif
