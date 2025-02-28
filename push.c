/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibyeo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:52:39 by ibyeo             #+#    #+#             */
/*   Updated: 2025/02/24 16:52:43 by ibyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_init_stack()
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->size = 0;
    stack->top = NULL;
    return (stack);
}

void    fill_in_stack_a(t_stack *stack, char **str)
{
    int i;
    t_node *new_node;

    i = 0;
 
    while (str[i])
    {
        new_node = malloc(sizeof(t_node));
        if (!new_node)
            return; 
        new_node->value = ft_atoi(str[i]);
        new_node->next = stack->top;
        stack->top = new_node;
        i++;   
    }
}

void    ft_push(t_stack *stack, t_stack *stackb)
{
    t_node *new_node;
    t_node *temp;
    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = stack->top->value;
    new_node->next = stackb->top;
    stackb->top = new_node;
    temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    stackb->size++;
    ft_printf("pa\n");

}

void    ft_swap(t_stack *stack)
{
    int val;
   val = stack->top->next->value;
   stack->top->next->value = stack->top->value;
   stack->top->value = val;
   ft_printf("sa\n");

}

void ft_rotate(t_stack *stack)
{
    t_node *node;
    t_node *first_node;

    node = stack->top;
    first_node = stack->top;
    while(node->next)
    {
        node = node->next;
    }
    stack->top = first_node->next;
    first_node->next = NULL;
    node = first_node;
    ft_printf("ra\n");
}

int ft_is_sorted(char **str)
{

}

void ft_reverse_rotate(t_stack *stack)
{
    t_node *node;
    t_node *first_node;

    node = stack->top;
    first_node = stack->top;
    while(node->next)
    {
        node = node->next;
    }
    stack->top = node;
    stack->top->next = first_node;
    node = NULL;
    ft_printf("rr\n");
}

int    ft_is_number(char **str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != NULL)
    {
        j = 0;
        while (str[i][j] != '\0')
        {
            if (j == 0 && (str[i][0] == '-' || str[i][0] == '+'))
                j++;
            else 
            {
                if (ft_isdigit(str[i][j]) == 0)
                    return (0);
                j++;
            }
        }
        i++;
    }
    return (1);
}

int    ft_detect_doublon(char **str)
{
    int i;
    int j;
    int temp;

    i = 1;
    while (str[i - 1] != NULL)
    {
        j = i;
        temp = ft_atoi(str[i - 1]);
        while (str[j] != NULL)
        {
            if (temp == ft_atoi(str[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int ft_is_higther_than_int(char **str)
{
    int  i;
    long value;

    i = 0;
    while(str[i] != NULL)
    {
        value = ft_atoi(str[i]);
        if ( value > INT_MAX)
            return (0);
        else if (value < INT_MIN)
            return (0);
        i++;
    }
    return (1);
}

char **ft_argv_strcpy(char **str, char **dest, int ac)
{
    int i;

    i = 0;
    dest[ac - 1] = NULL;
    while(ac > 1)
    {
        dest[i] =  ft_strdup(str[ac - 1]);
        i++;
        ac--;

    }
    return (dest);
}

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current != NULL) {
        ft_printf("Value: %d\n", current->value);
        current = current->next;
    }
}

int     main(int ac, char *av[])
{
    char **str;
    int i = 0;
    t_stack *stack_a;
   //t_stack *stack_b;

    stack_a = ft_init_stack();
   //stack_b = ft_init_stack();
    str = malloc(ac * sizeof(char *));
    str = ft_argv_strcpy(av, str, ac);
    if (ft_is_number(str) == 0)
    {
        ft_printf("Error\n");
        return (0);
    }
    if (ft_detect_doublon(str) == 0)
    {
        ft_printf("Error\n");
        return (0);
    }
    if (ft_is_higther_than_int(str) == 0)
    {
        ft_printf("Error\n");
        return (0);
    }
    fill_in_stack_a(stack_a, str);
   // print_stack(stack_a);
   //ft_push(stack_a, stack_b);
   ft_reverse_otate(stack_a);
   ft_printf("top value %d \n", stack_a->top->value);
    ft_printf("top value %d \n", stack_a->top->next->value);
    return (0);
}