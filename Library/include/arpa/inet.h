#ifndef _ARPA_INET_H
#define _ARPA_INET_H

/* All our big endian platforms use gcc, and gcc gets the define right
   so trust it for big endian detection */

#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

#define htonl(x)	(x)
#define htons(x)	(x)

#else

extern uint32_t htonl(uint32_t __hostlong);
extern uint16_t htons(uint16_t __hostshort);

#endif

#define ntohl(a)	htonl(a)
#define ntohs(a)	htons(a)

/* Legacy BSD API - avoid if possible */
extern int inet_aton(const char *__cp, struct in_addr *__inp);
extern in_addr_t inet_addr(const char *__cp);
extern in_addr_t inet_network(const char *__cp);
/* Awkward - struct argument .. may need hacks for 6502 ?? */
extern char *inet_ntoa(struct in_addr __in);

/* Modern APIs */
extern const char *inet_ntop(int __af, const void *__src, char *__dst,
							socklen_t __size);
extern int inet_pton(int __af, const char *__src, void *__dst);

#if 0
/* These are obsolete to the point we don't bother */
extern struct in_addr inet_makeaddr(in_addr_t net, ip_addr_t host);
extern in_addr_t inet_lnaof(struct in_addr in);
extern in_addr_t inet_netof(struct in_addr in);
#endif

#endif