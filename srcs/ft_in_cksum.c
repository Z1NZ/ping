#include <libft.h>
#include <sys/types.h>
#include <netinet/ip_icmp.h>

u_short ft_in_cksum(unsigned short *addr, int len)
{
	int nleft;
	u_short sum;
	u_short *w;
	u_short answer;
	union {
		u_short us;
		u_char uc[2];
	} last;

	nleft = len;
	sum = 0;
	w = addr;
	while (nleft > 1) {
		sum += *w++;
		nleft -= 2;
	}
	if (nleft == 1) {
		last.us = *w;
		last.uc[1] = 0;
		sum += last.us;
	}
	sum = (sum >> 16) + (sum & 0Xffff);
	sum += (sum >> 16);
	answer = ~sum;
	return (answer);
}

u_short ft_cksum(struct icmp *hdr)
{
	char tmp[65535];
	u_short checksum;
	ft_memcpy(tmp, (unsigned short *)&hdr, sizeof(struct icmp));
	ft_memcpy(tmp + sizeof(struct icmp), tmp, ft_strlen(tmp));
	checksum = ft_in_cksum((unsigned short *)tmp,
						   sizeof(struct icmp) + (u_short)ft_strlen(tmp));
	return (checksum);
}
