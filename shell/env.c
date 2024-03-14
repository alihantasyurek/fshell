/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:22:07 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/14 20:04:13 by atasyure         ###   ########.fr       */
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
			return (printf(A_ERR), 1);
		str = ft_split(*env, '=');
		//if(!str[0] || !str[1]) // added leak protection
		//{
		//free(key_v);
		//free_str(str);
		//return(printf(ENV_ERR),1);
		//}
		if(str[0] == NULL) // choose one of the above
			key_v->key = NULL;
		else
			key_v->key = ft_strdup(str[0]);
		if(str[1] == NULL)
			key_v->value = NULL;
		else
			key_v->value = ft_strdup(str[1]);

		ft_lstadd_back(&(*mini)->env, ft_lstnew(key_v));
		free_str(str);
		env++;
	}
	return (0);
}
