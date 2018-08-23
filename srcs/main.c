#include <ft_ping.h>

static void	ft_opt_i(char *option)
{
	char *tmp;

	tmp = option;
	while(ft_isdigit(*tmp) == 1)
		tmp++;
	if (*tmp != '\0')
	{
		fprintf(stderr, "%s","ping: bad timing interval" );
		exit(-1);
	}
	else
		g_env.interval = (unsigned int)atoi(option);
}

static void	ft_opt_t(char *option)
{
	char *tmp;

	tmp = option;
	while(ft_isdigit(*tmp))
		tmp++;
	if (*tmp != '\0')
	{
		fprintf(stderr, "%s","ping: can't set unicast time-to-live: Invalid argument" );
		exit(-1);
	}
	else
		g_env.ttl = atoi(option);
}


int			ft_option(char ***option)
{
	int	opt;


	opt = 0;
	if (***option == '-')
	{
		while (*option && **option && ***option == '-')
		{
			++**option;
			while(***option != '\0')
			{
				if (***option == 'v')
					opt |= OPT_V;
				else if (***option == 'a')
					opt |= OPT_A;
				else if (***option == 'h')
					opt |= OPT_H;
				else if (***option == 'i')
				{
					opt |= OPT_I;
					++*option;
					ft_opt_i(**option);
					break ;
				}
				else if (***option == 't')
				{
					opt |= OPT_T;
					++*option;
					ft_opt_t(**option);
					break ;
				}
				else if (***option == 'q')
					opt |= OPT_Q;
				else
					return(-1);
				++**option;
			}
			++*option;
		}

		return (opt);
	}
	else
		return (-2);
}


int			main(int argc, char *argv[])
{
	int opt;
	char **ptr;

	if (argc > 1)
	{
		if (argv[1][0] == '-')
		{
			ptr = argv + 1;
			if ((opt = ft_option(&ptr)) < 0)
			{
				if (opt == -1)
					fprintf(stderr ,"ping: -%c flag: %s\n", *argv[1], strerror(1));
				else
					fprintf(stderr ,"ping: %s\n", strerror(1));
				exit(-1);
			}
			ft_ping(opt, *ptr);
		}
		else
			ft_ping(0 , argv[1]);
	}
	else
		fprintf(stderr ,"%s\n", strerror(22));
	return 0;
}
