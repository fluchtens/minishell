/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:01:08 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:19:47 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
/* 
static void ft_print_list(t_list *lst)
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

	ft_lstdelone(lst, ft_del);

	ft_print_list(lst);
	printf("Length : %d\n", ft_lstsize(lst));
    printf("\n");
} */