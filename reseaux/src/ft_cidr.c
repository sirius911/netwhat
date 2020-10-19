/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cidr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:34:03 by clorin            #+#    #+#             */
/*   Updated: 2020/10/19 13:34:05 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_reseaux.h"
#include "../includes/ft_printf.h"
#include "../libft.h"

int		ft_nb_bit(unsigned char c)
/*compte le nombre de bits à 1 */
{
	int nb_bits;
	nb_bits = 0;

	while(c)
	{
		nb_bits	+=	c &	1;
  		c = c >> 1;
	}
	return (nb_bits);
}

static char		*ft_btochar(int b)
/* transforme un nombre de bit 1 placé à gauche
	en char* sur 8 bits (lesautres bits étant à 0*/
{
	int 	i;
	int 	p;
	int 	b_int;
	i = 0;
	p = 8 - b;
	b_int = 0;
	while (i <= 7)
	{
		if (i >= p)
			b_int = b_int + ft_power(2,i);
		i++;
	}
	return (ft_itoa(b_int));
}

t_list		*ft_masq_cidr(char *masq_cidr)
{
	int		cidr_int;
	int 	i;
	t_list		*new_lst;
	t_list		*temp;


	new_lst = NULL;
	i = 0;
	cidr_int = ft_atoi(masq_cidr);
	if (cidr_int > 32 || cidr_int < 0)
		return (NULL);
	while (cidr_int >= 8)
	{
		// ft_printf("Dans adresse %d on a 8 bit(s) à 1\n", i);
		cidr_int -= 8;
		i++;
		temp = ft_lstnew("255");
		if (!temp)
		{
			ft_lstclear(&new_lst, &ft_free);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
	}
	// ft_printf("Dans adresse %d on a %d bit(s) à 1\n", i, cidr_int);
	temp = ft_lstnew(ft_btochar(cidr_int));
	if (!temp)
	{
		ft_lstclear(&new_lst, &ft_free);
		return (NULL);
	}
	ft_lstadd_back(&new_lst, temp);
	while (i < 3)
	{
		temp = ft_lstnew("0");
		ft_lstadd_back(&new_lst, temp);
		i++;
	}
	return (new_lst);
}

int 		ft_ip_prive(t_list *ip, t_list *masque)
{
	if ((ft_atoi(ip->content) == 10 && ft_atoi(masque->content) == 255) ||
		(ft_atoi(ip->content) == 172 && ft_atoi(ip->next->content) == 16) ||
		(ft_atoi(ip->content) == 192 && ft_atoi(ip->next->content) == 168))
		return (1);
	else
		return (0);
}

int 	ft_nb_bit_masque(t_list *masque)
	/* renvoi la forme cidr du masque
		==> le nb de bit == 1*/
{
	int 	nb_bits_one;

	nb_bits_one = 0;
	while (masque)
	{
		nb_bits_one += ft_nb_bit(ft_atoi(masque->content));
		masque = masque->next;
	}
	return (nb_bits_one);
}

int 		ft_nb_postes(t_list *masque)
{
	int 	nb_zero_masque;

	nb_zero_masque = 32 - ft_nb_bit_masque(masque);
	return (ft_power(2, nb_zero_masque)); /* 2^nb de zero dans le masque*/
}
