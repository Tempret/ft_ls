/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:05:15 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/21 17:35:53 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H_
# define FT_LS_H_

# include <stdio.h>
# include "../libft/libft.h"
# include <dirent.h>

#define	AVAILIBLE_OPTIONS	"lraRt"
#define TRUE				1
#define FALSE				0

typedef struct		s_params
{
	char			*options;
	char 			**dirs;
}					t_params;

#endif
