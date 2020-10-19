/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reseaux.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:38:56 by clorin            #+#    #+#             */
/*   Updated: 2020/10/19 10:39:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RESEAUX_H
# define FT_RESEAUX_H

#include "../libft.h"

long		ft_power(long nb, long power);
char 		*ft_et(t_list *lst1, t_list *lst2);
char		*ft_ou(t_list *lst1, t_list *lst2);
void		*ft_neg(void *lst);
void		ft_free(void *content);
t_list		*ft_lstmap1(t_list *lst1, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstmaps(t_list *lst1, t_list *lst2, char *(*f)(t_list *,t_list *), void (*del)(void *));
void 		print_list(t_list *liste, int binaire);
t_list		*ft_masq_cidr(char *masq_cidr);
int			ft_nb_bit(unsigned char c);
int 		ft_ip_prive(t_list *ip, t_list *masque);
int 		ft_nb_postes(t_list *masque);
int 		ft_nb_bit_masque(t_list *masque);

#endif
