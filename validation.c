/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:13:39 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/22 19:49:59 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int	arg_isint(char *str, int value)
{
	char	*numberstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0' && value == 0)
		return (0);
	numberstr = ft_itoa(value);
	if (!numberstr)
		return (1);
	if (numberstr[0] == '-')
	{
		j++;
		i--;
	}
	while (str[i + j] == numberstr[j] && numberstr[j] != '\0')
		j++;
	i = str[i + j] - numberstr[j];
	free(numberstr);
	return (i);
}

int	value_isunique_normal(int i, int *numbers, int *norm)
{
	int	j;
	int	value;

	if (i == 0)
		return (0);
	j = 0;
	value = 0;
	while (j < i)
	{
		if (numbers[i] == numbers[j])
			return (-1);
		if (numbers[i] < numbers[j])
			norm[j]++;
		else
			value++;
		j++;
	}
	return (value);
}

void	*get_free(int *pointer_1, int *pointer_2)
{
	if (pointer_1)
		free(pointer_1);
	if (pointer_2)
		free(pointer_2);
	return (NULL);
}

int	*validate_input_normal(int argc, char **argv)
{
	int	*numbers;
	int	i;
	int	*norm;

	i = 0;
	numbers = malloc((argc - 1) * sizeof(int));
	norm = malloc((argc - 1) * sizeof(int));
	if (!numbers || !norm)
		return (get_free(numbers, norm));
	while (i < argc - 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		norm[i] = value_isunique_normal(i, numbers, norm);
		if (arg_isint(argv[i + 1], numbers[i]) != 0 || norm[i] == -1)
			return (get_free(numbers, norm));
		i++;
	}
	free(numbers);
	return (norm);
}

int	lst2stack(int argc, char **argv, t_stack **lst)
{
	int		i;
	int		*numbers;
	t_stack	*aux;

	i = 0;
	numbers = validate_input_normal(argc, argv);
	if (!numbers)
		return (1);
	while (i < argc - 1)
	{
		aux = create_node(numbers[i]);
		if (!aux)
			return (1);
		add_below(lst, aux);
		i++;
	}
	free (numbers);
	return (0);
}
