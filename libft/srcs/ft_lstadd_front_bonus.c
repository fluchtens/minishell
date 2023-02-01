/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:45:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:04:30 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
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

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("10");
	ft_print_list(lst);
	printf("\n");
	
	ft_lstadd_front(&lst, ft_lstnew("20"));
	ft_print_list(lst);
	printf("\n");
} */