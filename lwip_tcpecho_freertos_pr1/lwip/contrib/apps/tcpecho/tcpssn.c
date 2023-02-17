/*
 * tcpssn.c
 *
 *  Created on: 15 feb 2023
 *      Author: snaiderbautista
 */

#include "tcpssn.h"
#include "ssn.h"
/*-----------------------------------------------------------------------------------*/
static void tcpssn_thread(void *arg)
{
	struct netconn *conn;
	err_t err;
	LWIP_UNUSED_ARG(arg);
	ip4_addr_t server_ipaddr;
	char buffer[1024] = { 0 };

	/* Create a new connection identifier. */
	/* Bind connection to well known port number 7. */
#if LWIP_IPV6
	conn = netconn_new(NETCONN_TCP_IPV6);
	netconn_bind(conn, IP6_ADDR_ANY, 7);
#else /* LWIP_IPV6 */
	conn = netconn_new(NETCONN_TCP);
#endif /* LWIP_IPV6 */
	LWIP_ERROR("tcpecho: invalid conn", (conn != NULL), return;);

	IP4_ADDR(&server_ipaddr, 192, 168, 0, 100);
	//err = ssn_connect(conn, &server_ipaddr, 10000);
	err = netconn_connect(conn, &server_ipaddr, 10000);
	while (1) {
		/* Connect to the corresponding server */

		//err = netconn_connect(conn, &server_ipaddr, 10000);
		/* Process the new connection. */
		if (err == ERR_OK) {
			struct netbuf *buf;
			void *data;
			u16_t len;
			const char* message = "random:oijdoiqwjdoiqjoiqjorihwoqihroiqwjroiqwhroiwqhroqiwhroiho\n";
			data = (char*) message;
			len = strlen(message);
			ssn_transmit(conn, message, len);
			//err = netconn_write(conn, data, len, NETCONN_COPY);
			ssn_receive(conn, buffer, len);
			PRINTF("adios\n");
			/*printf("Got EOF, looping\n");*/
			/* Close connection and discard connection identifier. */
			netconn_close(conn);
			netconn_delete(conn);
		}
	}
}
/*-----------------------------------------------------------------------------------*/
void tcpssn_init(void)
{
	sys_thread_new("tcpssn_thread", tcpssn_thread, NULL, DEFAULT_THREAD_STACKSIZE, DEFAULT_THREAD_PRIO);
}

/*-----------------------------------------------------------------------------------*/

