#include <ft_ping.h>
#include <limits.h>
#include <math.h>


uint64_t mysqrt (uint64_t a)
{
  uint64_t min = 0;
  uint64_t max = ((uint64_t) 1) << 32;
  while(1)
    {
       if (max <= 1 + min)
         return min;           
       uint64_t sqt = min + (max - min)/2;
       uint64_t sq = sqt*sqt;
       if (sq == a) 
         return sqt;

       if (sq > a)
         max = sqt;
       else
         min = sqt;
 	}
}

struct addrinfo *ft_get_info(char *ptr, int opt)
{
	struct addrinfo hints;
	struct addrinfo *result;
	struct sockaddr_in *h;

	(void)opt;
	if (!ptr) 
	{
		fprintf(stderr, "Usage: <ip>\n");
		exit(-1);
	}
	ft_memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_CANONNAME;
	if (getaddrinfo(ptr, NULL, &hints, &result))
	{
		if (errno == 0)
		{
			fprintf(stderr ,"%s%s", "ping: unknown host ", ptr);
			exit(-1);
		}
		else
			ft_error();
	}
	h = (struct sockaddr_in *) result->ai_addr;
	g_env.name =  inet_ntoa( h->sin_addr );
	g_env.pack = (struct packet*)ft_memalloc(sizeof(struct packet));
	return(result);
}

void	tvsub(struct timeval *out, struct timeval*in)
{
	if( (out->tv_usec -= in->tv_usec) < 0 )   {
		out->tv_sec--;
		out->tv_usec += 1000000;
	}
	out->tv_sec -= in->tv_sec;
}

static void ft_out(int i)
{
	(void)i;
	long double tmp;

	signal(SIGINT, SIG_IGN);

	printf("\n");
	printf("--- %s ping statistics ---\n", g_env.host);
	printf("%ld packets transmitted, ", g_env.seq);
	printf("%ld received, ", g_env.recvpack);
	if (g_env.error)
	printf("+%ld errors, ", g_env.error);

	if (g_env.seq)
	{
		if (g_env.recvpack > g_env.seq)
			printf("-- somebody's printing up packets!");
		else
			printf("%d%% packet loss, time=%lums", (int)(((g_env.seq - g_env.recvpack) * 100) / g_env.seq), (g_env.timer / 10000));
	}
	printf("\n");
	if (g_env.recvpack > 0)
	{
		printf("rtt min/avg/max = %ld.%ld/%lu.%ld/%ld.%ld/", g_env.tmin/1000, g_env.tmin%1000,
		(g_env.tsum / (g_env.recvpack))/1000, (g_env.tsum / (g_env.recvpack))%1000, g_env.tmax/1000, g_env.tmax%1000);
		g_env.tsum /= g_env.recvpack;
		g_env.tsum2 /= g_env.recvpack;
		tmp = mysqrt(g_env.tsum2 - g_env.tsum * g_env.tsum);
		printf("%.3LF ms\n", tmp/1000);
	}
	if (g_env.recvpack == 0)
		exit(1);
	exit (0);
}

static void	ft_ping_old(int i)
{
	alarm(0);
	double tmp;
	(void)i;
	g_env.seq++;
	int len;
	struct sockaddr_in server;
	struct  msghdr msg;
	struct iovec iov[1]; /* Data array */
	struct timeval tp, tv;
	struct recv_packet *p;

	memset(&msg, '\0', sizeof(msg));
	memset(g_env.pack, '\0', (sizeof(struct packet)));
	g_env.pack->hdr.type = ICMP_ECHOREQ;
	g_env.pack->hdr.un.echo.id = getpid();
	g_env.pack->hdr.un.echo.sequence = g_env.seq;
	g_env.pack->hdr.checksum =  ft_in_cksum((unsigned short*)g_env.pack, sizeof(struct packet));
	server.sin_family = g_env.pinfo->ai_family;
	inet_pton(AF_INET, g_env.name, &server.sin_addr);
	iov[0].iov_base = &(g_env.pack->hdr);
	iov[0].iov_len = sizeof(*g_env.pack);
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;
	len = 0;
	gettimeofday( &tp, NULL);
	if (sendto (g_env.sd, g_env.pack, PACKETSIZE, 0, (struct sockaddr *) &server, sizeof (struct sockaddr)) < 0)
	{
		perror ("sendto() failed ");
		alarm(g_env.interval);
		return ;
	}
	if (g_env.tr.tv_usec)
	{
		struct timeval tb;
		gettimeofday(&tb, NULL);
		tvsub(&tb, &(g_env.tr));
		g_env.timer += tb.tv_sec * 10000000L + tb.tv_usec; 
	}
	alarm(2);
	jump:
	len = recvmsg(g_env.sd, &msg, 0);
	gettimeofday(&(g_env.tr), NULL);
	if (len)
	{
		p = (struct recv_packet *)msg.msg_iov[0].iov_base;
		if (p->hdr.icmp_hun.ih_idseq.icd_id != getpid() && (p->hdr.icmp_code != ICMP_ECHOREPLY && p->hdr.icmp_code != ICMP_FILTER))
			goto jump;
		if (p->hdr.icmp_code == ICMP_FILTER)
		{
			alarm(0);
			++g_env.error;
			printf("From %d.%d.%d.%d icmp_seq=%ld %s\n", (int)(p->ip.ip_src.s_addr & 0xFF), (int)((p->ip.ip_src.s_addr &0xFF00)>>8),
			(int)((p->ip.ip_src.s_addr &0xFF0000)>>16),(int)((p->ip.ip_src.s_addr &0xFF000000)>>24), g_env.seq, "Packet filtered");
		}
		else
		{
			gettimeofday( &tv, NULL);
			alarm(0);
			if ((CHECK_BIT(g_env.opt, OPT_T)) && p->ip.ip_ttl > g_env.ttl)
			{	
				if (!CHECK_BIT(g_env.opt, OPT_Q))
					printf("%zd bytes from %s: icmp_seq=%u %s\n", msg.msg_iov[0].iov_len, g_env.name, p->hdr.icmp_hun.ih_idseq.icd_seq, "Time to live exceeded");
			}
			else
			{		
				++g_env.recvpack;
				tvsub(&tv, &tp);
				tmp = tv.tv_sec * 10000000L + tv.tv_usec;
				if (!CHECK_BIT(g_env.opt, OPT_Q))
					printf("%zd bytes from %s: icmp_seq=%u ttl=%d time=%.2fms\n", msg.msg_iov[0].iov_len, g_env.name, p->hdr.icmp_hun.ih_idseq.icd_seq, p->ip.ip_ttl, tmp/1000);
				g_env.tsum += tmp;
				g_env.tsum2 += (long long)tmp * (long long)tmp;
				if (tmp < g_env.tmin)
						g_env.tmin = tmp;
				if (tmp > g_env.tmax)
						g_env.tmax = tmp;
				if (CHECK_BIT(g_env.opt, OPT_A))
					beep();
			}
		}
	}
	alarm(g_env.interval);
}

int		ft_ping(int opt, char *ptr)
{

	if(CHECK_BIT(opt, OPT_H))
		ft_how_use();
	g_env.pinfo = ft_get_info(ptr, opt);
	if ((g_env.sd = socket (AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
	{
		printf("%s\n", "socket");
		ft_error();
	}
	if (!CHECK_BIT(opt, OPT_I))
		g_env.interval = 1;
	g_env.tmin = LONG_MAX;
	g_env.host = ptr;
	g_env.opt = opt;
	printf("%s %s (%s) %s \n", "PING", ptr, g_env.name, "56(84) bytes of data.");
	signal(SIGALRM, ft_ping_old);
	signal(SIGINT, ft_out);
		ft_ping_old(0);
	while(1)
		;
	return(0);
}