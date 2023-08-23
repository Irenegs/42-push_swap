/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:47:22 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/22 19:18:05 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 1)
		exit (0);
	a = NULL;
	if (lst2stack(argc, argv, &a) == 1)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	sort_original(&a, argc - 1);
	clear_all_stack(&a);
	free(a);
	exit(0);
}
