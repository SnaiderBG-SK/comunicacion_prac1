/*
 * ssn.h
 *
 *  Created on: 13 feb 2023
 *      Author: snaiderbautista
 */

#ifndef SSN_H_
#define SSN_H_

#include "lwip/opt.h"
#include "lwip/sys.h"
#include "lwip/api.h"
#include "fsl_crc.h"
#include "aes.h"

#define SSN_POLYNOMIAL 0x04C11DB7U

err_t ssn_connect(struct netconn *conn, const ip4_addr_t *server_ipaddr, u16_t port);
err_t ssn_transmit(struct netconn *conn, const char *payload, u16_t length);
err_t ssn_receive(struct netconn* conn, char* buffer, u16_t len);






#endif /* SSN_H_ */
