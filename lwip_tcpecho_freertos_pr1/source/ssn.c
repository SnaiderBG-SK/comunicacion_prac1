/*
 * ssn.c
 *
 *  Created on: 13 feb 2023
 *      Author: snaiderbautista
 */

#include "ssn.h"

static void initCrc32(CRC_Type *base, uint32_t seed);

err_t ssn_connect(struct netconn *conn, const ip4_addr_t *server_ipaddr, u16_t port)
{
	err_t err;
	conn = netconn_new(NETCONN_TCP);
	LWIP_ERROR("tcpessn: invalid conn", (conn != NULL), return;);
	/* Connect to the corresponding server */
	err = netconn_connect(conn, server_ipaddr, 10000);
	/* Process the new connection. */
	if (err == ERR_OK)
	{
		PRINTF("Connected to server :: %u.%u.%u.%u\r\n", ((u8_t *)server_ipaddr)[0], ((u8_t *)server_ipaddr)[1],
				((u8_t *)server_ipaddr)[2], ((u8_t *)server_ipaddr)[3]);
	}
	return err;
}

err_t ssn_transmit(struct netconn *conn, const char *payload, u16_t length)
{
	err_t err;
	void *data;
	/* AES data */
	uint8_t key[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };
	uint8_t iv[]  = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	struct AES_ctx ctx;
	uint8_t padded_msg[512] = {0};
	size_t padded_len;

	/* CRC data */
	CRC_Type *base = CRC0;
	uint32_t checksum32;

	/* Init the AES context structure */
	AES_init_ctx_iv(&ctx, key, iv);

	padded_len = length + (16 - (length%16) );
	memcpy(padded_msg, payload, length);
	AES_CBC_encrypt_buffer(&ctx, padded_msg, padded_len);
	PRINTF("Encrypted Message: ");
	for(int i=0; i<padded_len; i++) {
		PRINTF("0x%02x,", padded_msg[i]);
	}
	PRINTF("\r\n");

	initCrc32(base, 0xFFFFFFFFU);
	CRC_WriteData(base, (uint8_t *)&padded_msg[0], padded_len);
	checksum32 = CRC_Get32bitResult(base);
	memcpy(&padded_msg[padded_len], &checksum32, sizeof(checksum32));

	PRINTF("CRC-32: 0x%08x\r\n", checksum32);
	data = (char*)padded_msg;
	err = netconn_write(conn, data, padded_len + 4, NETCONN_COPY);
}

err_t ssn_receive(struct netconn* conn, char* buffer, u16_t len)
{
	err_t err;
	struct netbuf *buf;
	void *data;
	/* CRC data */
	CRC_Type *base = CRC0;
	uint32_t checksumCalculated = 0;
	int32_t checksumReceived = 0;
	/* AES data */
	uint8_t key[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };
	uint8_t iv[]  = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	struct AES_ctx ctx;
	uint8_t message[512] = {0};
	/* Init the AES context structure */
	AES_init_ctx_iv(&ctx, key, iv);

	err = netconn_recv(conn, &buf) == ERR_OK;
	netbuf_data(buf, &data, &len);
	uint8_t* cdata = (uint8_t*)data;
	PRINTF("Received Encrypted Message: ");
	for(int i = 0; i < len; i++)
	{
		PRINTF("0x%02x, ", cdata[i]);
	}
	PRINTF("\r\n");
	checksumReceived = (uint32_t)cdata[len - 1] << 24 | (uint32_t)cdata[len - 2] << 16 | (uint32_t)cdata[len - 3] << 8 | (uint32_t)cdata[len - 4];
	initCrc32(base, 0xFFFFFFFFU);
	CRC_WriteData(base, cdata, len - 4);
	checksumCalculated = CRC_Get32bitResult(base);
	PRINTF("Received CRC-32: 0x%08x\r\n", checksumCalculated);
	PRINTF("Calculated CRC-32: 0x%08x\r\n", checksumReceived);
	if(checksumCalculated == checksumReceived)
	{
		PRINTF("Correct CRC\r\n");
		PRINTF("Decrypted message: ");
		AES_CBC_decrypt_buffer(&ctx, cdata, len - 4);
		for(int i = 0; i < len - 4; i++)
		{
			PRINTF("%c", (char)cdata[i]);
		}
		PRINTF("\r\n");
	}
	else
	{
		PRINTF("Incorrect CRC\r\n");
	}

}

static void initCrc32(CRC_Type *base, uint32_t seed)
{
	crc_config_t config;

	config.polynomial         = SSN_POLYNOMIAL;
	config.seed               = seed;
	config.reflectIn          = true;
	config.reflectOut         = true;
	config.complementChecksum = true;
	config.crcBits            = kCrcBits32;
	config.crcResult          = kCrcFinalChecksum;

	CRC_Init(base, &config);
}
