/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:30:42 by adaly             #+#    #+#             */
/*   Updated: 2017/06/06 21:22:45 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free_wofinal(t_pfconv *current)
{
	if (current)
	{
		ft_strdel_plus(&(current->prefix));
		ft_strdel_plus(&(current->string));
		ft_strdel_plus(&(current->exponent));
		ft_strdel_plus(&(current->widthstr));
	}
}

static void	ft_finalize_one(t_pfconv *current)
{
	char	*final;

	final = NULL;
	if (current->string)
	{
		ft_restrcat(&final, current->prefix);
		ft_restrcat(&final, current->widthstr);
		ft_restrcat(&final, current->string);
		ft_restrcat(&final, current->exponent);
		current->final = final;
	}
	current->chars = ft_strlen(current->final);
}

static void	ft_finalize_two(t_pfconv *current)
{
	char	*final;

	final = NULL;
	if (current->string)
	{
		ft_restrcat(&final, current->widthstr);
		ft_restrcat(&final, current->prefix);
		ft_restrcat(&final, current->string);
		ft_restrcat(&final, current->exponent);
		current->final = final;
	}
	current->chars = ft_strlen(current->final);
}

static void	ft_finalize_three(t_pfconv *current)
{
	char	*final;

	final = NULL;
	if (current->string)
	{
		ft_restrcat(&final, current->prefix);
		ft_restrcat(&final, current->string);
		ft_restrcat(&final, current->exponent);
		ft_restrcat(&final, current->widthstr);
		current->final = final;
	}
	current->chars = ft_strlen(current->final);
}

void		ft_finalize(t_pfconv *current)
{
	char	*temp;
	if (current)
	{
		if (current->string[0] == '-' && current->widthstr && !current->flags[0] && current->flags[3])
		{
			temp = current->widthstr;
			current->widthstr = ft_strjoin("-", current->widthstr);
			ft_strdel_plus(&temp);
			temp = ft_strdup(current->string + 1);
			ft_strdel_plus(&(current->string));
			current->string = temp;
		}
		if (current->flags[0])
			ft_finalize_three(current);
		else if (current->flags[4] && !current->flags[3])
			ft_finalize_two(current);
		else
			ft_finalize_one(current);
		if (current->type == 'c' && !ft_strlen(current->string))
			current->chars += 1;
		ft_free_wofinal(current);
	}
}