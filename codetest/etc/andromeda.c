/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   andromeda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:09:02 by codespace         #+#    #+#             */
/*   Updated: 2023/05/05 20:56:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	static char	*prompt;

	prompt = (char*)NULL;
	while(1 > 0)
	{
		prompt = readline ("Andromeda$");
		free(prompt);
	}
	return (0);
}
