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

#include "../libft.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_reseaux.h"

static void ft_resultat(t_list *ip, t_list *masque, t_list *adr_reseau, t_list *broadcast)
{
	// t_list	*last;
	// int 	nb_poste;
	// int nb_zero_masque;

	ft_putstr("IP   : ");
	print_list(ip, 0);
	ft_putstr("\t ==> ");
	print_list(ip, 1);
	ft_putstr("\nMASQ : ");
	print_list(masque, 0);
	ft_putstr("\t ==> ");
	print_list(masque, 1);
	ft_putstr("\nAddress reseau : ");
	print_list(adr_reseau,0);
	ft_putstr(" ==> ");
	print_list(adr_reseau, 1);
	ft_putstr("\n broadcast     : ");
	print_list(broadcast, 0);
	ft_putstr(" ==> ");
	print_list(broadcast, 1);
	ft_putchar('\n');
	if (ft_ip_prive(ip, masque))
		ft_printf("IP : %s.%s => Privée\n", ip->content,ip->next->content);
	else
		ft_printf("IP : %s.%s => internet\n", ip->content,ip->next->content);
	ft_printf("Nb d'adresse dispo = %d [2^nb zero du masque](addr reseau & broadcast inclus)\n", ft_nb_postes(masque));

}

int		main(int argc, char **argv)
{
	t_list	*ip;
	char 	ip_char[15];
	t_list	*masque;
	t_list	*adr_reseau;
	t_list	*masq_neg;
	t_list	*broadcast;
	char 	*masq_cidr;
	int 	i;

	if (argc == 3)
	{
		ip = ft_lstsplit(argv[1], '.');
		masque = ft_lstsplit(argv[2], '.');
		adr_reseau = ft_lstmaps(ip, masque, &ft_et, &ft_free);/*on applique le & binaire sur IP*/
		masq_neg = ft_lstmap1(masque, &ft_neg, &ft_free);	/* on inverse les bits du masque */
		broadcast = ft_lstmaps(adr_reseau, masq_neg, &ft_ou, &ft_free);	/* on applique un ou inclusif sur IP et inv du masque */
		ft_resultat(ip, masque, adr_reseau, broadcast);
	}
	else if (argc == 2)
	{
		masq_cidr = ft_strrchr(argv[1],'/');
		if (masq_cidr)
		{
			masq_cidr++;
			masque = ft_masq_cidr(masq_cidr);
			i = 0;
			while (argv[1][i] != '/' && argv[1][i])
			{
				ip_char[i] = argv[1][i];
				i++;
			}
			ip = ft_lstsplit(ip_char, '.');
			adr_reseau = ft_lstmaps(ip, masque, &ft_et, &ft_free);/*on applique le & binaire sur IP*/
			masq_neg = ft_lstmap1(masque, &ft_neg, &ft_free);	/* on inverse les bits du masque */
			broadcast = ft_lstmaps(adr_reseau, masq_neg, &ft_ou, &ft_free);	/* on applique un ou inclusif sur IP et inv du masque */
			ft_resultat(ip, masque, adr_reseau, broadcast);
		}
		else
		{
			ft_printf("\n%s => %b (%d bits on 1)", argv[1],ft_atoi(argv[1]), ft_nb_bit(ft_atoi(argv[1])));
			ft_printf(" (%d bits on 0)\n", (8 - ft_nb_bit(ft_atoi(argv[1]))));
			return (0);
		}
	}
	else
	{
		ft_putstr("Erreur \n\treseaux [addr_ip] [addr_masq]\n\texemple : reseaux 10.0.0.255 255.255.255.0\n\treseaux [nbr]\n");
		return (0);
	}
	ft_lstclear(&ip, &ft_free);
	ft_lstclear(&adr_reseau, &ft_free);
	ft_lstclear(&broadcast, &ft_free);
	return (0);
}

