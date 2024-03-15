/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:23:53 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/14 20:49:07 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>

int		g_heredoc_sig;

void	get_readline(t_mini *mini)
{
	mini->cmd = readline("🟢 emmodogl&&aatasyure$");
	if (mini->cmd && !is_space(mini->cmd))
	{
		free(mini->cmd);
		get_readline(mini); //continue tarzi bir sey eklenebilir;
	}
	if (!mini->cmd)
	{
		free_loop(0, mini);
		free_(mini);
		free(mini->lex_list);
		free(mini);
		exit(1);
	}
	add_history(mini->cmd);
}

void	proper_free(t_list **node)
{
	t_list *curr_node;
	t_list *temp;

	curr_node = *node;

	while(curr_node != NULL)
	{
		free(curr_node->content);
		curr_node->content = NULL;
		temp = curr_node;
		curr_node = curr_node->next;
		free(temp);
		temp = NULL;
	}
}

void	go_parser(t_mini *mini, char **env, int control)
{
	control = check(mini);
	if (!control)
	{
		//error_free(&(mini->lex_list)->lex);
		proper_free(&mini->lex_list->lex);

		// Free memory in the selected code block
		free_loop(control, mini);
		return ;
	}
	if (ft_strcmp(mini->cmd, ""))
	{
		if (our_parser(mini))
			exec(env, mini);
	}
	free_loop(control, mini);
}

void	start_minishell(t_mini *mini, char **env, int control)
{
	while (42)
	{
		get_readline(mini);
		if (quote_check(mini->cmd, '\'', '\"'))
		{
			lexer(mini);
			expander(mini);
			go_parser(mini, env, control);
		}
		else
		{
			(free(mini->cmd));
			continue ;
		}
	}
}

static int argument_control(int argc, char **argv/*, char **env*/)
{
	(void)argv;
	if (argc != 1) //more optimized?
		return (printf(W_ARGS), -1); // fixed the error message
	//if (!*env)
		//return (printf(ENV_ERR), -1); // added ENV check
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini;

	if (argument_control(argc, argv/*, env*/) != 0) // def 0 as success and 1 as ERROR; 
		return (-1);
	if (init(&mini) != 0)
		return (-1);
	if(*env != NULL) // check this on bash in mac
		if (env_get(env, &mini))
			return (free_init_check(mini), 1);
	signals_control();
	start_minishell(mini, env, 0);
}
