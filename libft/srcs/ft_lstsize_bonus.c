/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:16:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:05:57 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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
	printf("Length : %d\n", ft_lstsize(lst));
    printf("\n");
    
    ft_lstadd_front(&lst, ft_lstnew("20"));
    ft_print_list(lst);
	printf("Length : %d\n", ft_lstsize(lst));
	printf("\n");
} */