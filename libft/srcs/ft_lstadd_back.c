/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:22:15 by fluchten          #+#    #+#             */
/*   Updated: 2022/10/24 08:33:28 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
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

	ft_lstadd_back(&lst, ft_lstnew("30"));
    ft_print_list(lst);
    printf("Length : %d\n", ft_lstsize(lst));
	printf("\n");

	last = ft_lstlast(lst);
    printf("Last element : [%s]\n", (char *)last->content);
	printf("\n");
} */