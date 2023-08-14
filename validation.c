/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:13:39 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/14 19:31:12 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int arg_isint(char *str, int value)
{
    char    *numberstr;
    int     i;
    int     j;

    numberstr = ft_itoa(value);
    if (!numberstr)
        return (1);
    i = 0;
    j = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (numberstr[0] == '-')
        j++;
    while (str[i]  == '0')
        i++;
    if (str[i] == '\0' && value == 0)
    {
        free(numberstr);
        return (0);
    }
    //printf("\ni,j:[%d,%d]\n", i, j);
    if (j == 1)
        i--;
    while (str[i + j] == numberstr[j] && numberstr[j] != '\0')
        j++;
    //printf("\ni,j:[%d,%d]\n", i, j);
    //printf("\nReturn:[%d]\n", str[i + j] - numberstr[j]);
    i = str[i + j] - numberstr[j];
    free(numberstr);
    return (i);
}

int value_isunique_normal(int i, int* numbers, int *norm)
{
    int j;
    int value;

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

int *validate_input_normal(int argc, char **argv)
{
    int *numbers;
    int i;
    int *norm;

    i = 0;
    numbers = malloc((argc - 1) * sizeof(int));
    norm =  malloc((argc - 1) * sizeof(int));
    if (!numbers || !norm)
    {
        free(numbers);
        free(norm);
        return (NULL);
    }
    while (i < argc - 1)
    {
        numbers[i] = ft_atoi(argv[i + 1]);
        norm[i] = value_isunique_normal(i, numbers, norm);
        //printf("\n[i:%d]\n", i);
        if (arg_isint(argv[i + 1], numbers[i]) != 0 || norm[i] == -1)
        {
            //printf("\n[IF %d, %d]\n", arg_isint(argv[i], numbers[i]), norm[i]);
            free(numbers);
            free(norm);
            return (NULL);
        }
        i++;
    }
    free(numbers);
    return (norm);
}

int lst2stack(int argc, char **argv, stack **lst)
{
    int     i;
    int     *numbers;
    stack   *aux;

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