/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 20:12:55 by adaly             #+#    #+#             */
/*   Updated: 2017/06/09 22:38:09 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_char(t_pfconv *current, char c)
{
	current->string = ft_strnew(1);
	current->string[0] = c;
	current->chars = 1;
	return (1);
}

static int	ft_char_wide(t_pfconv *current, unsigned int c)
{
	int				width;
	wchar_t			full_char;

	full_char = ft_char_expand(c);
	width = ft_utf8width((unsigned char*)&full_char);
	current->string = ft_strnew(width);
	current->chars = width;
	ft_memcpy(current->string, &full_char, width);
	return (width);
}

static int	ft_string(t_pfconv *current, char *c)
{
	if (c)
	{
		current->string = ft_strdup(c);
		current->chars = ft_strlen(current->string);
	}
	else
	{
		current->string = ft_strdup("(null)");
		current->chars = ft_strlen(current->string);
	}
	return (current->chars);
}

static int	ft_string_wide(t_pfconv *current, char *c)
{
	wchar_t	*wc;
	int		index;

	if (c)
	{
		index = 0;
		wc = (wchar_t*)c;
		while (wc[index])
			++index;
		current->string = (char*)ft_memalloc(sizeof(wchar_t) * (index + 1));
		current->chars = index * sizeof(wchar_t);
		ft_memcpy(current->string, wc, current->chars);
	}
	else
	{
		current->string = ft_strdup("(null)");
		current->chars = ft_strlen(current->string);
		printf("current->chars is %d\n", current->chars);
	}
	return (current->chars);
}

int			ft_other_types(t_pfconv *current, va_list args)
{
	ft_import_options(current, args);
	if (current->type == 'c')
		ft_char(current, va_arg(args, int));
	if (current->type == 'C')
		ft_char_wide(current, va_arg(args, int));
	if (current->type == 's')
		ft_string(current, va_arg(args, char*));
	if (current->type == 'S' || (current->type == 's' && current->length == 2))
		ft_string_wide(current, va_arg(args, char*));
	if (current->type == '%')
		ft_char(current, '%');
//	if (current->type == 'n')
//		current->string = (char*)va_arg(args, int*);
	return (current->chars);
}
