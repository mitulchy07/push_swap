/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitul <mitul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:06 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 14:06:46 by mitul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

int		checkSorted(t_list **stackA);
int		pushSwapStrlen(char *str);
void	freeTab(char **tab);
void	checkErrorArg(char **av);
int		isNumeric(char *str);
void	freeAtoi(t_list **stack, char **argv, int size);
int		ftAtoi(const char *str, t_list **stack, char **argv, int size);
void	sort_list(t_list **stack_a, t_list **stack_b, int size);
int		initialize_list(t_list **stack_a, int argc, char **argv, int size);
int		checkDuplicate(t_list *stackA, int value);
void	checkInverted(t_list **stackA, int argc);
void	deleteList(t_list **stack);

void	swapA(t_list **stackA);
void	swapB(t_list **stackB);
void	swapBoth(t_list **stackA, t_list **stackB);
void	pushA(t_list **stackB, t_list **stackA);
void	pushB(t_list **stackA, t_list **stackB);
void	rotateA(t_list **stackA);
void	rotateB(t_list **stackB);
void	rotateBoth(t_list **stackA, t_list **stackB);
void	reverseRotateA(t_list **stackA);
void	reverseRotateB(t_list **stackB);
void	reverseRotateBoth(t_list **stackA, t_list **stackB);
void	sortThree(t_list **stackA);
void	sortFive(t_list **stackA, t_list **stackB);
void	freeTab(char **tab);
void	check_arguments(int argc, char **argv, t_list **stack_a);
void	moveToB(t_list **stackA, t_list **stackB, int *arr, int len);
void	moveToA(t_list **stackA, t_list **stackB);
int		findBestPositionB(t_list **stackB, int sizeB,
            t_list **stackA, int sizeA);
int		moveRemainingNumbers(t_list *stackA, int size, int *arr, int len);
int		findBestCombination(int *arrA, int *arrB, int size);
int		findBestCombinationHelper(int *arrA, int *arrB,
            int *tmp, int size);
int		pushMinToTop(int a, int b, t_list **stackA, t_list **stackB);
void	searchMin(t_list **stackA, int size);

int		*copyStackNumber(t_list *stackA, int size);
int		*copyIntArray(int	*arr, int size);

int		countMoves(int min, int len, int size);
int		countMovesA(t_list *stackA, int nb, int size);
int		countMovesB(int len, int size);
int		maxNumber(int a, int b);
int		minNumber(int a, int b);
int		maxOrMin(t_list *stackA, int nb, int size);
int		returnMaxOrMin(int nb, int *maxNMin, int size);

int		*constructLis(int *stackNumbers, int *prev, int lisLength, int endIndex);
int		findMaxLisLength(int *lis, int size, int *endIndex);
void	updateLisAndPrev(int *lis, int *prev, int *stackNumbers, int size);
void	initializeLisAndPrev(int *lis, int *prev, int size);
int		*defineLis(int *stackNumbers, int size, int *len);
int		*findLisAndLen(int *stackNumbers, int size, int *len);

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