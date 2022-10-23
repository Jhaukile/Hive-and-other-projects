/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:20:29 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:20:30 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

typedef enum e_algorithms
{
	SELECT = 0,
	RADIX,
	SIMPLE
}	t_algorithms;

typedef struct s_int_arr
{
	int		*arr;
	size_t	size;
	size_t	space;
}	t_int_arr;

typedef struct s_value
{
	int		min;
	size_t	index;
}	t_value;

typedef struct s_instructions
{
	char	**instr;
	size_t	size;
	size_t	space;
}	t_instructions;

typedef struct s_arguments
{
	char	**argv;
	int		argc;
}	t_arguments;

void			free_2d_arr(char **arr, size_t size);

void			stack_swap(int *a, int *b, size_t size);
void			stack_push(t_int_arr *stack, int *item);
int				*stack_pop(t_int_arr *stack);
void			stack_reverse_rotate(t_int_arr *stack);
void			stack_rotate(t_int_arr *stack);

t_int_arr		make_int_array(int argc, char **argv);
int				copy_to_int_array(int argc, char **argv, t_int_arr *int_arr);
t_arguments		fix_arguments(int argc, char **argv);

char			**realloc_instructions(t_instructions *instructions,
					size_t new_size);
int				read_instructions(t_instructions *instructions);
void			instruction_pushback(t_instructions *instructions, char *instr);
void			remove_instruction(t_instructions *instructions, size_t index);
void			instruction_insert(t_instructions *instructions,
					char *instr, size_t index);

void			remove_extra(t_instructions *instructions);

t_instructions	*select_sort(t_int_arr a, t_int_arr b,
					t_instructions *instructions);
t_instructions	*radix_sort(t_int_arr a, t_int_arr b,
					t_instructions *instructions);
t_instructions	*simple_sort(t_int_arr a, t_instructions *instructions);

int				validate_arguments(int ac, char **av);
char			**join_arrays(int ac1, int ac2, char **av1, char **av2);
t_int_arr		simple_array(t_int_arr stack);

void			execute_instructions(char **instructions,
					t_int_arr *a, t_int_arr *b);

t_instructions	*init_instructions(t_instructions *instructions);

void			output_instructions(t_instructions *instr);

int				initialize_arrays(t_int_arr *stack_a, char **argv, int argc);
void			init_all_instructions(t_instructions *instr);

#endif
