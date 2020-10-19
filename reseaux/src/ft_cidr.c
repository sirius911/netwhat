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