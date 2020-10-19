/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:07:14 by clorin            #+#    #+#             */
/*   Updated: 2020/10/19 11:07:15 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_reseaux.h"
#include "../includes/ft_printf.h"
#include "../libft.h"

void	ft_free(void *content)
/*fonction pour free les listes*/
{
	free (content);
	content = NULL;
}

t_list		*ft_lstmap1(t_list *lst1, void *(*f)(void *), void (*del)(void *))
/* ma fonction ft_lstmap de  libft n'est pas opé ! */
{
	t_list		*new_lst;
	t_list		*temp;

	new_lst = NULL;
	while (lst1)
	{
		temp = ft_lstnew(f(lst1->content));
		if (!temp)
		{
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		lst1 = lst1->next;
	}
	return (new_lst);
}

t_list		*ft_lstmaps(t_list *lst1, t_list *lst2, char *(*f)(t_list *,t_list *), void (*del)(void *))
/* permet de renvoyer un t_list à partir d'une fonction f() qui utiliser deux t_list */
{
	t_list		*new_lst;
	t_list		*temp;

	new_lst = NULL;
	while (lst1 || lst2)
	{
		temp = ft_lstnew(f(lst1, lst2));
		if (!temp)
		{
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		lst1 = lst1->next;
		lst2 = lst2->next;	
	}
	return (new_lst);
}


void print_list(t_list *liste, int binaire)
/* imprime une adresse :
				si binaire = 1 ==> sous forme binaire 
				si binaire = 0 ==> sous forme decimale*/
{
	while (liste)
	{		
		if (binaire)
			ft_printf("%08b", ft_atoi(liste->content));
		else
			ft_printf("%3d", ft_atoi(liste->content));
		if (liste->next)
				ft_putchar('.');
		liste = liste->next;
	}
}
