/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:01:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 07:50:45 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
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

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("10");
	ft_print_list(lst);
    printf("\n");
} */