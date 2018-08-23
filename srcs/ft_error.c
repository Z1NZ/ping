#include <ft_ping.h>

int ft_error(void)
{
	if (errno == 0)
		fprintf(stderr, "%s", "Unknown error");
	else
		fprintf(stderr, "%s", strerror(errno));
	exit(-1);
}

int ft_how_use(void)
{
	printf("%s\n", "Usage: ping [-ahvq] [-i interval] [-t ttl] destination\n");
	exit(-1);
}

/*

Usage: ping [-aAbBdDfhLnOqrRUvV] [-c count] [-i interval] [-I interface]
			[-m mark] [-M pmtudisc_option] [-l preload] [-p pattern] [-Q tos]
			[-s packetsize] [-S sndbuf] [-t ttl] [-T timestamp_option]
			[-w deadline] [-W timeout] [hop1 ...] destination


*/
