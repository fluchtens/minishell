/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:01:06 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:21:24 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		ft_lstdelone(current, del);
		current = temp;
	}
	*lst = NULL;
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

static void	ft_del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	char	*element;

	element = ft_strdup("Hello World!");
	lst = ft_lstnew(element);
	
	ft_print_list(lst);
	printf("Length : %d\n", ft_lstsize(lst));
    printf("\n");

	ft_lstclear(&lst, ft_del);

	ft_print_list(lst);
	printf("Length : %d\n", ft_lstsize(lst));
    printf("\n");
} */