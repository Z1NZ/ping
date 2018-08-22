#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <errno.h>
#include <libft.h>
#include <sys/time.h>
#include <signal.h>
#include <curses.h>

/*
** define Flag option
*/
#define CHECK_BIT(var,pos)	(var & pos)
#define OPT_V				1
#define OPT_H				2
#define OPT_I				4
#define OPT_T				8
#define OPT_Q				16
#define OPT_A				32

#define ICMP_ECHOREPLY		0
#define ICMP_ECHOREQ		8
#define ICMP_FILTER			13
#define REQ_DATASIZE		64
#define PACKETSIZE			64


typedef struct			s_env
{
	unsigned long int	error;
	int					opt;
	int					ttl;
	int					interval;
	long int			sd;
	unsigned long int	seq;
	unsigned long int	recvpack;
	char				*name;
	struct addrinfo		*pinfo;
	struct packet		*pack;
	char				*host;
	u_long				timer;
	unsigned long		tmin;
	unsigned long		tmax;
	u_long				tsum;
	u_long				tsum2;
	struct timeval		tr;
}						t_env;

struct					packet
{
	struct				icmphdr hdr;
	char				msg[PACKETSIZE-sizeof(struct icmphdr)];
};

struct					recv_packet
{
	struct ip			ip;
	struct icmp			hdr;
	char				msg[PACKETSIZE-(sizeof(struct icmphdr) + sizeof( struct iphdr))];
};

t_env g_env;

/*
** opt
*/
int						ft_option(char ***option);
/*
** network
*/
struct addrinfo 		*ft_get_info(char *ptr, int opt);
u_short					ft_in_cksum(u_short *addr, int len);
u_short					ft_cksum(struct icmp *hdr);
int						ft_ping(int opt, char *ptr);
/*
** error
*/
void					ft_error(void);
void					ft_how_use(void);

