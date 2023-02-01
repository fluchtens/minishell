/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:17:10 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:09:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
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
	t_list   *last;

	lst = ft_lstnew("10");
	ft_print_list(lst);
	printf("Length : %d\n", ft_lstsize(lst));
    printf("\n");
    
    ft_lstadd_front(&lst, ft_lstnew("20"));
    ft_print_list(lst);
	printf("Length : %d\n", ft_lstsize(lst));
	printf("\n");

	last = ft_lstlast(lst);
    printf("Last element : [%s]\n", (char *)last->content);
	printf("\n");
} */