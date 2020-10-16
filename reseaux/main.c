/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:03:32 by clorin            #+#    #+#             */
/*   Updated: 2020/10/15 12:03:35 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "includes/ft_printf.h"

void	ft_free(void *content)
/*fonction pour free les listes*/
{
	free (content);
	content = NULL;
}

char 	*ft_et(t_list *lst1, t_list *lst2)
/*fonction pour le 'et' binaire => & */
{
	return (ft_itoa(ft_atoi(lst1->content) & ft_atoi(lst2->content)));
}

char	*ft_ou(t_list *lst1, t_list *lst2)
/*fonction pour le 'ou inclusif' binaire => | */
{
	return (ft_itoa(ft_atoi(lst1->content) | ft_atoi(lst2->content)));
}

void	*ft_neg(void *lst)
/* fonction pour inverser les bits => ~ */
{
	unsigned char	i;

	i = ft_atoi((char *)lst);
	i = ~i;
	return (ft_itoa(i));
}

static t_list		*ft_lstmap1(t_list *lst1, void *(*f)(void *), void (*del)(void *))
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

static t_list		*ft_lstmaps(t_list *lst1, t_list *lst2, char *(*f)(t_list *,t_list *), void (*del)(void *))
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


static void print_list(t_list *liste, int binaire)
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

int		main(int argc, char **argv)
{
	t_list	*ip;
	t_list	*masque;
	t_list	*adr_reseau;
	t_list	*masq_neg;
	t_list	*broadcast;

	if (argc == 3)
	{
		ip = ft_lstsplit(argv[1], '.');
		masque = ft_lstsplit(argv[2], '.');

			ft_putstr("IP   : ");
			print_list(ip, 0);
			ft_putstr("\t ==> ");
			print_list(ip, 1);
			ft_putstr("\nMASQ : ");
			print_list(masque, 0);
			ft_putstr("\t ==> ");
			print_list(masque, 1);
			adr_reseau = ft_lstmaps(ip, masque, &ft_et, &ft_free);//on applique le & binaire sur IP
			ft_putstr("\nAddress reseau : ");
			print_list(adr_reseau,0);
			ft_putstr(" ==> ");
			print_list(adr_reseau, 1);
			masq_neg = ft_lstmap1(masque, &ft_neg, &ft_free);	// on inverse les bits du masque
			// ft_putstr("\ninverse MASQ : ");
			// print_list(liste_neg,0);
			// ft_putstr(" ==> ");
			// print_list(liste_neg, 1);
			broadcast = ft_lstmaps(adr_reseau, masq_neg, &ft_ou, &ft_free);	// on applique un ou inclusif sur IP et inv du masque
			ft_putstr("\n broadcast     : ");
			print_list(broadcast, 0);
			ft_putstr(" ==> ");
			print_list(broadcast, 1);
			ft_putchar('\n');
	}
	else if (argc == 2)
		ft_printf("%s => %b\n", argv[1],ft_atoi(argv[1]));
	else
		ft_putstr("Erreur \n\treseaux [addr_ip] [addr_masq]\n\texemple : reseaux 10.0.0.255 255.255.255.0\n\treseaux [nbr]\n");
	ft_lstclear(&masque, &ft_free);
	ft_lstclear(&ip, &ft_free);
	ft_lstclear(&adr_reseau, &ft_free);
	ft_lstclear(&broadcast, &ft_free);
	return (0);
}

