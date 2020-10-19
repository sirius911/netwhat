/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:01:05 by clorin            #+#    #+#             */
/*   Updated: 2020/10/19 11:01:14 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_reseaux.h"
#include "../libft.h"

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
