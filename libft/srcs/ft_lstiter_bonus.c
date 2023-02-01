/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:01:10 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:23:29 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

/* static void ft_print_list(t_list *lst)
{
	if (!lst)
    {
        printf("The list is empty!\n");
		return ;
    }
    while (lst)
    {
        printf("[%s] ", lst->content);
        lst = lst->next;
    }
    printf("\n");
}

static void my_func(void *element)
{
	if (ft_toupper((int)element))
		printf("The first letter of the element is a lower case.\n");
	else
		printf("The first letter of the element is a capital letter.\n");
}

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("aa");
	ft_print_list(lst);
    printf("\n");
	
	ft_lstadd_front(&lst, ft_lstnew("AA"));
    ft_print_list(lst);
	printf("\n");
	
	ft_lstiter(lst, my_func);
	printf("\n");
} */