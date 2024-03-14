/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:24:46 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/14 20:04:13 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

int	init(t_mini **mini)
{
	*mini = ft_calloc(1,sizeof(t_mini));
	if (!(*mini))
		return (1);
	(*mini)->lex_list = ft_calloc(1,sizeof(t_lexer));
	if (!(*mini)->lex_list)
		return (free(*mini),printf(A_ERR), 1); //changed
	g_heredoc_sig = 0;
	return (0);
}

void	error_free(t_list **node)
{
	if (!*node)
		return ;
	if ((*node)->next != NULL)
		free_node((*node)->next);
	if ((*node)->content)
		(*node)->content = (free((*node)->content), NULL);
	if ((*node))
		(*node) = (free(*node), NULL);
}

int	single_or_multi_command(t_mini *m_mini)
{
	t_parse	*parse;
	int		i;

	i = 0;
	parse = m_mini->parse;
	while (parse)
	{
		if (parse->type == 2)
			i++;
		parse = parse->next;
	}
	return (i);
}
