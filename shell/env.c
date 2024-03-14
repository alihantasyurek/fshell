/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:22:07 by emsakar           #+#    #+#             */
/*   Updated: 2024/03/13 22:42:39 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	env_get(char **env, t_mini **mini)
{
	t_env	*key_v;
	char	**str;

	while (*env)
	{
		key_v = malloc(sizeof(t_env));
		if (!key_v)
		{
			return (printf(A_ERR), 1);
			//TODO; free(other stuff)
		}
		str = ft_split(*env, '=');
		//TODO; if split NULL free(other stuff);
		key_v->key = ft_strdup(str[0]);
		//TODO; if strdup NULL free(other stuff);
		key_v->value = ft_strdup(str[1]);
		//TODO; if strdup NULL free(other stuff);
		ft_lstadd_back(&(*mini)->env, ft_lstnew(key_v));
		free_str(str);
		env++;
	}
	return (0);
}
