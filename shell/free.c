/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:23:25 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/15 19:34:32 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	free_init_check(t_mini *mini)
{
	if (mini->env)
		free_(mini);
	//if (mini->lex_list->lex) // find where lex_lists are used 
		//free(mini->lex_list->lex);
	//if (mini->lex_list)
		//free(mini->lex_list);
	if (mini)
		free(mini);
	return ((void)printf(ENV_ERR));
}
