/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:22:27 by emsakar           #+#    #+#             */
/*   Updated: 2024/03/11 05:22:33 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse	*_next_command(t_parse **parse)
{
	if ((*parse)->infile > STDERR || (*parse)->outfile > STDERR
		|| (*parse)->type == HEREDOC)
	{
		return ((*parse)->next->next);
	}
	else
	{
		return ((*parse)->next);
	}
}
