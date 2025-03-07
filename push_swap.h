/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:47 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 14:08:34 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

int		check_if_sorted(t_list **stack_a);
int		push_swap_strlen(char *str);
void	free_tab_memory(char **tab);
void	check_argument_error(char **av);
int		is_numeric_string(char *str);
void	free_atoi_memory(t_list **stack, char **argv, int size);
int		ft_atoi(const char *str, t_list **stack, char **argv, int size);
void	sort_list(t_list **stack_a, t_list **stack_b, int size);
int		initialize_list(t_list **stack_a, int argc, char **argv, int size);
int		check_for_duplicates(t_list *stack_a, int value);
void	check_if_inverted(t_list **stack_a, int argc);
void	delete_linked_list(t_list **stack);
void	swap_stack_a(t_list **stack_a);
void	swap_stack_b(t_list **stack_b);
void	swap_both_stacks(t_list **stack_a, t_list **stack_b);
void	push_to_stack_a(t_list **stack_b, t_list **stack_a);
void	push_to_stack_b(t_list **stack_a, t_list **stack_b);
void	rotate_stack_a(t_list **stack_a);
void	rotate_stack_b(t_list **stack_b);
void	rotate_both_stacks(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_stack_a(t_list **stack_a);
void	reverse_rotate_stack_b(t_list **stack_b);
void	reverse_rotate_both_stacks(t_list **stack_a, t_list **stack_b);
void	sort_three_elements(t_list **stack_a);
void	sort_five_elements(t_list **stack_a, t_list **stack_b);
void	check_arguments(int argc, char **argv, t_list **stack_a);
void	move_to_stack_b(t_list **stack_a, t_list **stack_b, int *arr, int len);
void	move_to_stack_a(t_list **stack_a, t_list **stack_b);
int		find_best_position_b(t_list **stack_b, int size_b,
			t_list **stack_a, int size_a);
int		move_remaining_numbers_to_b(t_list *stack_a,
			int size, int *arr, int len);
int		find_best_combination_of_moves(int *arr_a, int *arr_b, int size);
int		helper_find_best_combination(int *arr_a, int *arr_b,
			int *tmp, int size);
int		push_minimum_to_top(int a, int b, t_list **stack_a, t_list **stack_b);
void	find_minimum_in_stack(t_list **stack_a, int size);
int		*copy_stack_number_values(t_list *stack_a, int size);
int		*copy_integer_arr_ay(int *arr, int size);
int		count_total_moves(int min, int len, int size);
int		count_moves_in_stack_a(t_list *stack_a, int nb, int size);
int		count_moves_in_stack_b(int len, int size);
int		max_number_in_stack(int a, int b);
int		min_number_in_stack(int a, int b);
int		get_max_or_min_value(t_list *stack_a, int nb, int size);
int		return_max_or_min_value(int nb, int *max_n_min,
			int size);
int		*construct_lis(int *stackNumbers, int *prev,
			int lisLength, int end_index);
int		find_max_length_of_lis(int *lis, int size, int *end_index);
void	update_lis_prev_val(int *lis, int *prev, int *stackNumbers, int size);
void	init_lis_prev_val(int *lis, int *prev, int size);
int		*define_lis(int *stackNumbers, int size, int *len);
int		*find_lis_and_length(int *stackNumbers, int size, int *len);

#endif