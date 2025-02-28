/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:19:29 by ibyeo             #+#    #+#             */
/*   Updated: 2025/02/23 13:22:49 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_strlenn(char **str)
{
    int i;

    i = 0;
    while(str[i] != NULL)
    {
        i++;
    }
    return(i);
}

int ft_count_step_to_poush(char **str)
{
    int   i;
    int step;
    int j;

    i = 0;
    step = 0;
    j = 1;
    while(str[i] != NULL)
    {
        if( i <= ft_strlenn(str))
            step = i + 1;
        else
            step = ft_strlenn(str) - i;
    }

}

void ft_print_stack(char **str, char **str1)
{
    int i;
    int j;
    int k;
     
    if (ft_strlenn(str) > ft_strlenn(str1))
    {
        i = ft_strlenn(str);
        j = 0;
        while (i)
        {
            if (i > ft_strlenn(str1))
            {
                printf(" %s\n", str[ft_strlenn(str) - i]);
                i--;
            }
            else
            {
                printf(" %s    %s\n", str[ft_strlenn(str) - i], str1[j]);
                j++;
                i--;
            }
        }
        
    }
    else
    {
        i = ft_strlenn(str1);
        j = 0;
        while (i)
        {
            if (i > ft_strlenn(str))
            {
                printf(" %s\n", str1[ft_strlenn(str1) - i]);
                i--;
            }
            else
            {
                printf(" %s    %s\n", str1[ft_strlenn(str1) - i], str[j]);
                j++;
                i--;
            }
        }
    }
    printf("%s\n", "___  ___");
    printf("%s\n", " a    b");
}

char **ft(char **str, char **str1)
{
    int i;

    i =0;
    while(ft_strlenn(str) > 3)
    {
        ft_position_it_at_top(str[ft_count_low_shot(str)]);
        str = ft_push(str, str1);
        str = ft_a_is_push(str);
    }
}

char** ft_push(char **stac_a, char **stac_b)
{
    char **temp_b;
    int i = 0;
    temp_b = malloc(ft_strlenn(stac_b) + 2);
    while(i < ft_strlenn(stac_b))
    {
        temp_b[i] = malloc(strlen(stac_b[i]) + 1);
        temp_b[i] = strcpy(temp_b[i],stac_b[i]);
        i++;
    }
    temp_b[i] = malloc(strlen(stac_a[0]) + 1);
    temp_b[i] = strcpy(temp_b[i], stac_a[0]);
    temp_b[i + 1] = NULL;
    return(temp_b);
}

char **ft_a_is_push(char **str)
{
    char **temp;
    int i = 0;
    temp = malloc(ft_strlenn(str));
    while (str[i])
    {
        temp[i] = malloc(strlen(str[i]));
        temp[i] = strcpy(temp[i],str[i]);
        i++;
    }
    if(i != 0)
        temp[i -1] = NULL;
    return(temp);
}

char **ft_fill_in_stack_A(char **stack_A, int ac, char *av[])
{
    int i;

    i = 0;    
    stack_A = malloc((ac) * sizeof(char *));
    while(i < (ac - 1))
    {
        stack_A[i] = malloc(strlen(av[i + 1]) + 1);
        strcpy(stack_A[i], av[i + 1]);
        i++;
    }
    stack_A[ac - 1] = NULL;
    return (stack_A);
}

char **ft_rotate(char **str, int r)
{
    char **temp;
    int i;
    int size_to_stop;
    temp = malloc(ft_strlenn(str) + 1);
    if ( r == 0)
    {
        temp[0] = malloc(ft_strlenn(str) - 1);
        temp[0] = strcpy(temp[0], str[ft_strlenn(str) - 1]);
        i = 1;
        size_to_stop = ft_strlenn(str) - 1;
    }
    else
    {
        temp[ft_strlenn(str) - 1] = malloc(strlen(str[0]));
        temp[ft_strlenn(str) - 1] = strcpy(temp[ft_strlenn(str) - 1], str[0]);
        i = 0;
        size_to_stop = ft_strlenn(str) - 2;
    }
    while (i <= size_to_stop)
    {
        if (r == 0)
        {
            temp[i] = malloc(strlen(str[i - 1]));
            temp[i] = strcpy(temp[i], str[i - 1]);
        }
        else
        {
            temp[i] = malloc(strlen(str[i + 1]));
            temp[i] = strcpy(temp[i], str[i + 1]);
        }
        i++;
        
    }
    temp[ft_strlenn(str)] = NULL;
    return (temp);
}

int ft_is_sorted(char **str)
{
    int i = 0;
    while (i < (ft_strlenn(str) - 1))
    {
        if (atoi(str[i]) < atoi(str[i + 1]))
            i++;
        else
            return (0);
    }
    return (1);
}

char **ft_swap(char ** str)
{
    char *temp;
    if (ft_strlenn(str) >=2)
    {
        temp = malloc(strlen(str[0]));
        temp = strcpy(temp, str[0]);
        str[0] = malloc(strlen(str[1]));
        str[0] = strcpy(str[0], str[1]);
        str[1] = malloc(strlen(temp));
        str[1] = strcpy(str[1], temp);
    }
    return (str);
}

int ft_find_min(char **str)
{
    int i;
    int j;
    int value;

    i = 0;
    j = 0;
    value = atoi(str[0]);
    while(j < ft_strlenn(str))
    {
        if (atoi(str[j]) <= value)
        {
            i = j;
            value = atoi(str[j]);
        }
        j++;
    }
    return (i);
}

int ft_find_max(char **str)
{
    int i;
    int j;
    int value;

    i = 0;
    j = 0;
    value = atoi(str[0]);
    while(j < ft_strlenn(str))
    {
        if (atoi(str[j]) >= value)
        {
            i = j;
            value = atoi(str[j]);
        }
        j++;
    }
    return (i);
}

char **ft_my_function(char **str1)
{
    int i;
    int j;

    i = 0;
    if (ft_strlenn(str1) == 3)
    {
        j = ft_is_sorted(str1);
        while(j == 0)
        {
            printf("%d\n", j);
            if(ft_find_max(str1) == 0 && ft_find_min(str1) == 2)
            {
                str1 = ft_swap(str1);
                str1 = ft_rotate(str1, 1);
            }
            else if (ft_find_max(str1) == 1 && ft_find_min(str1) == 2)
            {
                str1 = ft_rotate(str1, 0);
                //str1 = ft_rotate(str1, 0);
            }
            else if(ft_find_max(str1) == 1 && ft_find_min(str1) == 0)
            {
                str1 = ft_swap(str1);
                str1 = ft_rotate(str1, 0);
            }
            else if(ft_find_max(str1) == 2 && ft_find_min(str1) == 1)
            {
                str1 = ft_swap(str1);
            }
            else  if(ft_find_max(str1) == 0 && ft_find_min(str1) == 1)
            {
                str1 = ft_rotate(str1, 0);
            }
            j = ft_is_sorted(str1);
        }
    }
    return (str1);
}

int main(int ac, char* av[])
{
    char** stack_A;
    char** stack_B;

    stack_B = malloc(1);
   stack_B[0] = NULL;
   stack_A = malloc(1);
   stack_A[0] = NULL;
    stack_A = ft_fill_in_stack_A(stack_A, ac, av);
    //stack_B = ft_fill_in_stack_A(stack_A, ac, av);
    //stack_B = ft_push(stack_A, stack_B, ac);
    //stack_A = ft_a_is_push(stack_A);
    //stack_A = ft_rotate(stack_A, 0);
    //stack_A = ft_rotate(stack_A, 0);

    stack_A = ft_my_function(stack_A);
    ft_print_stack(stack_A, stack_B);

}
