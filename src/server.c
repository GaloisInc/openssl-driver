
// From: https://wiki.openssl.org/index.php/Simple_TLS_Server

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include "noni.h"


// Public socket data from the victim request.
// ** BEGIN RECORDINGS public read_buf_0-12
unsigned char read_buf_0[32] = {
  0x30, 0x66, 0x44, 0x3F, 0x1E, 0xF3, 0x2B, 0xB5, 0x00, 0xC2, 0xCB, 0xE4, 0x4E, 0x90, 0x6C, 0x99,
  0x57, 0x3B, 0x89, 0xE9, 0x49, 0x5A, 0xD3, 0x06, 0xD8, 0x98, 0x9A, 0xA8, 0x59, 0x12, 0xB2, 0xD7
};
unsigned char read_buf_1[5] = {
  0x16, 0x03, 0x01, 0x00, 0x3D
};
unsigned char read_buf_2[61] = {
  0x01, 0x00, 0x00, 0x39, 0x03, 0x01, 0xB0, 0xFC, 0x2E, 0xC0, 0xD0, 0x9A, 0x29, 0x5D, 0xA8, 0xF1,
  0x1E, 0x11, 0x00, 0xE1, 0xA7, 0x01, 0x08, 0x0C, 0xD0, 0x03, 0x3C, 0x7D, 0x5B, 0x70, 0xC9, 0xB3,
  0xF7, 0xBC, 0x79, 0x26, 0xE4, 0x69, 0x00, 0x00, 0x04, 0x00, 0x2F, 0x00, 0xFF, 0x01, 0x00, 0x00,
  0x0C, 0x00, 0x23, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00
};
unsigned char read_buf_3[5] = {
  0x16, 0x03, 0x01, 0x00, 0x46
};
unsigned char read_buf_4[70] = {
  0x10, 0x00, 0x00, 0x42, 0x00, 0x40, 0x13, 0x52, 0xA4, 0xEB, 0xCC, 0xB3, 0x22, 0x27, 0x88, 0x86,
  0x26, 0x40, 0x8C, 0x32, 0x9F, 0xB5, 0xF8, 0xD4, 0xD5, 0xF4, 0x47, 0x27, 0x74, 0x78, 0xBD, 0xDE,
  0xC6, 0x3E, 0x08, 0x51, 0x68, 0x91, 0x1A, 0x15, 0x8D, 0x14, 0x39, 0xE1, 0x22, 0x1D, 0x57, 0xB3,
  0x32, 0x8F, 0x77, 0xC2, 0x8D, 0x72, 0xBB, 0xCF, 0x53, 0x0B, 0xE3, 0xBC, 0xF2, 0xE5, 0x07, 0xC7,
  0x3D, 0xD5, 0x62, 0xA8, 0x29, 0x28
};
unsigned char read_buf_5[5] = {
  0x14, 0x03, 0x01, 0x00, 0x01
};
unsigned char read_buf_6[1] = {
  0x01
};
unsigned char read_buf_7[5] = {
  0x16, 0x03, 0x01, 0x00, 0x30
};
unsigned char read_buf_8[48] = {
  0x57, 0x03, 0xA2, 0x6F, 0x41, 0x7B, 0xD0, 0x1B, 0xB5, 0xC4, 0xB6, 0xC5, 0x89, 0x7D, 0xEA, 0x04,
  0x98, 0xC9, 0xB8, 0xA3, 0x03, 0x64, 0x10, 0x31, 0x82, 0xA9, 0x44, 0xCA, 0xA1, 0x06, 0x48, 0xC1,
  0x75, 0xD2, 0xCD, 0xD8, 0x42, 0x33, 0xB5, 0xE2, 0xF9, 0x0D, 0x3C, 0x92, 0x4D, 0xFE, 0x12, 0x0A
};
unsigned char read_buf_9[5] = {
  0x17, 0x03, 0x01, 0x00, 0x20
};
unsigned char read_buf_10[32] = {
  0x84, 0x2E, 0xBE, 0x19, 0x81, 0x89, 0x52, 0xB5, 0x36, 0xDC, 0x69, 0xEF, 0x23, 0xA5, 0x22, 0x12,
  0xF7, 0xC8, 0x6A, 0x5E, 0x7A, 0x61, 0xE5, 0x38, 0x0E, 0x76, 0x83, 0x3C, 0xE4, 0x20, 0x76, 0x4D
};
unsigned char read_buf_11[5] = {
  0x17, 0x03, 0x01, 0x00, 0x60
};
unsigned char read_buf_12[96] = {
  0xCA, 0x32, 0x05, 0x0F, 0x23, 0xEE, 0xCF, 0x7D, 0x90, 0xF7, 0xD0, 0x59, 0xB7, 0x16, 0x9B, 0xCE,
  0xE4, 0x04, 0xAC, 0xA6, 0xA4, 0xDF, 0x8C, 0xE8, 0x95, 0x0E, 0x44, 0xFD, 0x7B, 0x53, 0x72, 0x0E,
  0x77, 0x37, 0x37, 0x8D, 0x57, 0x0F, 0x2F, 0x7E, 0xF5, 0xC1, 0x46, 0x35, 0x79, 0x08, 0xEC, 0x4B,
  0x43, 0xBC, 0xBA, 0x42, 0x61, 0x21, 0xF8, 0xEE, 0x9D, 0x3B, 0x9F, 0x4B, 0xFB, 0xCB, 0x6E, 0x69,
  0x87, 0x7B, 0x93, 0xA0, 0xAC, 0xED, 0x5A, 0x0C, 0xF6, 0xF3, 0x9C, 0xA1, 0x5B, 0x43, 0x02, 0x5E,
  0x40, 0x56, 0xC4, 0x66, 0xEC, 0x0C, 0x89, 0x12, 0x56, 0xE7, 0xD8, 0xD5, 0xAC, 0x8B, 0x34, 0xE4
};
// ** END RECORDINGS
// Public socket data from the client hello of the attacker request.
// ** BEGIN RECORDINGS public read_buf_13
unsigned char read_buf_13[5] = {
  0x16, 0x03, 0x01, 0x00, 0x3D
};
// ** END RECORDINGS

// // Public gettimeofday responses.
// const size_t TIMEOFDAY_COUNTS = 7;
// const long int timeofdays[TIMEOFDAY_COUNTS] = { 1634333955, 1634333965, 1634333965, 1634333965, 1634333965, 1634333965, 1634333965 };

int create_socket(int port)
{
    int s;
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
	perror("Unable to create socket");
	exit(EXIT_FAILURE);
    }

    int option = 1;
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
	perror("Unable to bind");
	exit(EXIT_FAILURE);
    }

    if (listen(s, 1) < 0) {
	perror("Unable to listen");
	exit(EXIT_FAILURE);
    }

    return s;
}

void init_openssl()
{ 
    SSL_load_error_strings();	
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl()
{
    EVP_cleanup();
}

SSL_CTX *create_context()
{
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = TLSv1_server_method();

    ctx = SSL_CTX_new(method);
    if (!ctx) {
	perror("Unable to create SSL context");
	ERR_print_errors_fp(stderr);
	exit(EXIT_FAILURE);
    }

    //SSL_CTX_set_cipher_list(ctx, "AES128-GCM-SHA256");
    SSL_CTX_set_cipher_list(ctx, "AES128-SHA");

    return ctx;
}


unsigned char key_pem[] = {
  0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x42, 0x45, 0x47, 0x49, 0x4e, 0x20, 0x50,
  0x52, 0x49, 0x56, 0x41, 0x54, 0x45, 0x20, 0x4b, 0x45, 0x59, 0x2d, 0x2d,
  0x2d, 0x2d, 0x2d, 0x0a, 0x4d, 0x49, 0x49, 0x42, 0x56, 0x41, 0x49, 0x42,
  0x41, 0x44, 0x41, 0x4e, 0x42, 0x67, 0x6b, 0x71, 0x68, 0x6b, 0x69, 0x47,
  0x39, 0x77, 0x30, 0x42, 0x41, 0x51, 0x45, 0x46, 0x41, 0x41, 0x53, 0x43,
  0x41, 0x54, 0x34, 0x77, 0x67, 0x67, 0x45, 0x36, 0x41, 0x67, 0x45, 0x41,
  0x41, 0x6b, 0x45, 0x41, 0x38, 0x33, 0x73, 0x63, 0x44, 0x67, 0x73, 0x49,
  0x4a, 0x61, 0x61, 0x79, 0x72, 0x71, 0x39, 0x65, 0x0a, 0x79, 0x63, 0x72,
  0x61, 0x4f, 0x65, 0x45, 0x7a, 0x35, 0x70, 0x61, 0x64, 0x72, 0x59, 0x49,
  0x4d, 0x66, 0x72, 0x4b, 0x48, 0x64, 0x33, 0x4c, 0x44, 0x6f, 0x36, 0x4d,
  0x46, 0x4c, 0x63, 0x32, 0x57, 0x44, 0x72, 0x4c, 0x51, 0x76, 0x71, 0x52,
  0x68, 0x49, 0x48, 0x45, 0x33, 0x67, 0x62, 0x2b, 0x77, 0x2f, 0x34, 0x34,
  0x57, 0x46, 0x53, 0x36, 0x69, 0x6d, 0x4e, 0x33, 0x4e, 0x69, 0x32, 0x76,
  0x4e, 0x0a, 0x54, 0x34, 0x4e, 0x52, 0x4d, 0x51, 0x49, 0x44, 0x41, 0x51,
  0x41, 0x42, 0x41, 0x6b, 0x45, 0x41, 0x31, 0x45, 0x32, 0x66, 0x69, 0x39,
  0x73, 0x77, 0x73, 0x6d, 0x76, 0x6c, 0x57, 0x41, 0x35, 0x51, 0x6a, 0x35,
  0x49, 0x53, 0x73, 0x4f, 0x39, 0x65, 0x61, 0x77, 0x30, 0x66, 0x31, 0x69,
  0x41, 0x55, 0x74, 0x78, 0x45, 0x43, 0x73, 0x44, 0x50, 0x67, 0x78, 0x54,
  0x66, 0x34, 0x4d, 0x66, 0x52, 0x71, 0x0a, 0x44, 0x45, 0x35, 0x51, 0x54,
  0x42, 0x30, 0x35, 0x42, 0x2b, 0x61, 0x73, 0x62, 0x64, 0x2f, 0x51, 0x52,
  0x39, 0x48, 0x74, 0x58, 0x68, 0x33, 0x68, 0x4a, 0x63, 0x48, 0x37, 0x39,
  0x4f, 0x33, 0x2f, 0x72, 0x4d, 0x2f, 0x4f, 0x42, 0x51, 0x49, 0x68, 0x41,
  0x50, 0x71, 0x4d, 0x76, 0x59, 0x4f, 0x42, 0x43, 0x64, 0x73, 0x62, 0x53,
  0x41, 0x63, 0x4a, 0x6f, 0x70, 0x6f, 0x4f, 0x43, 0x33, 0x2b, 0x66, 0x0a,
  0x56, 0x51, 0x45, 0x2b, 0x71, 0x34, 0x32, 0x57, 0x6a, 0x54, 0x7a, 0x51,
  0x2f, 0x44, 0x48, 0x52, 0x46, 0x57, 0x46, 0x48, 0x41, 0x69, 0x45, 0x41,
  0x2b, 0x4d, 0x63, 0x42, 0x46, 0x54, 0x76, 0x4b, 0x47, 0x54, 0x38, 0x54,
  0x7a, 0x7a, 0x44, 0x37, 0x37, 0x43, 0x36, 0x38, 0x57, 0x2b, 0x48, 0x56,
  0x49, 0x59, 0x72, 0x6b, 0x4d, 0x4c, 0x45, 0x4a, 0x57, 0x63, 0x6d, 0x35,
  0x30, 0x43, 0x65, 0x33, 0x0a, 0x4e, 0x63, 0x63, 0x43, 0x49, 0x41, 0x6f,
  0x73, 0x54, 0x73, 0x47, 0x5a, 0x4b, 0x72, 0x4a, 0x48, 0x30, 0x45, 0x76,
  0x67, 0x32, 0x30, 0x5a, 0x51, 0x44, 0x61, 0x31, 0x33, 0x35, 0x62, 0x61,
  0x77, 0x4f, 0x62, 0x7a, 0x39, 0x41, 0x4f, 0x30, 0x59, 0x4f, 0x7a, 0x55,
  0x32, 0x6e, 0x52, 0x79, 0x66, 0x41, 0x69, 0x41, 0x4c, 0x34, 0x70, 0x34,
  0x48, 0x6f, 0x4b, 0x71, 0x67, 0x47, 0x43, 0x5a, 0x66, 0x0a, 0x49, 0x4b,
  0x7a, 0x34, 0x64, 0x4b, 0x63, 0x6c, 0x45, 0x4a, 0x33, 0x35, 0x45, 0x30,
  0x53, 0x68, 0x6d, 0x75, 0x4f, 0x69, 0x65, 0x59, 0x4f, 0x36, 0x45, 0x52,
  0x75, 0x73, 0x6f, 0x77, 0x49, 0x67, 0x42, 0x31, 0x63, 0x64, 0x31, 0x49,
  0x6c, 0x73, 0x4c, 0x6e, 0x6c, 0x71, 0x37, 0x36, 0x46, 0x75, 0x37, 0x53,
  0x4a, 0x38, 0x68, 0x59, 0x58, 0x6b, 0x4c, 0x32, 0x6a, 0x58, 0x51, 0x76,
  0x72, 0x2b, 0x0a, 0x35, 0x70, 0x58, 0x6b, 0x44, 0x66, 0x74, 0x6b, 0x57,
  0x50, 0x30, 0x3d, 0x0a, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x45, 0x4e, 0x44,
  0x20, 0x50, 0x52, 0x49, 0x56, 0x41, 0x54, 0x45, 0x20, 0x4b, 0x45, 0x59,
  0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a
};
unsigned int key_pem_len = 522;

unsigned char cert_pem[] = {
  0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x42, 0x45, 0x47, 0x49, 0x4e, 0x20, 0x43,
  0x45, 0x52, 0x54, 0x49, 0x46, 0x49, 0x43, 0x41, 0x54, 0x45, 0x2d, 0x2d,
  0x2d, 0x2d, 0x2d, 0x0a, 0x4d, 0x49, 0x49, 0x42, 0x34, 0x54, 0x43, 0x43,
  0x41, 0x59, 0x75, 0x67, 0x41, 0x77, 0x49, 0x42, 0x41, 0x67, 0x49, 0x55,
  0x4b, 0x75, 0x5a, 0x65, 0x77, 0x36, 0x48, 0x6e, 0x4e, 0x37, 0x71, 0x4e,
  0x6f, 0x53, 0x69, 0x74, 0x48, 0x4d, 0x75, 0x77, 0x46, 0x48, 0x6f, 0x50,
  0x76, 0x51, 0x73, 0x77, 0x44, 0x51, 0x59, 0x4a, 0x4b, 0x6f, 0x5a, 0x49,
  0x68, 0x76, 0x63, 0x4e, 0x41, 0x51, 0x45, 0x4c, 0x0a, 0x42, 0x51, 0x41,
  0x77, 0x52, 0x54, 0x45, 0x4c, 0x4d, 0x41, 0x6b, 0x47, 0x41, 0x31, 0x55,
  0x45, 0x42, 0x68, 0x4d, 0x43, 0x51, 0x56, 0x55, 0x78, 0x45, 0x7a, 0x41,
  0x52, 0x42, 0x67, 0x4e, 0x56, 0x42, 0x41, 0x67, 0x4d, 0x43, 0x6c, 0x4e,
  0x76, 0x62, 0x57, 0x55, 0x74, 0x55, 0x33, 0x52, 0x68, 0x64, 0x47, 0x55,
  0x78, 0x49, 0x54, 0x41, 0x66, 0x42, 0x67, 0x4e, 0x56, 0x42, 0x41, 0x6f,
  0x4d, 0x0a, 0x47, 0x45, 0x6c, 0x75, 0x64, 0x47, 0x56, 0x79, 0x62, 0x6d,
  0x56, 0x30, 0x49, 0x46, 0x64, 0x70, 0x5a, 0x47, 0x64, 0x70, 0x64, 0x48,
  0x4d, 0x67, 0x55, 0x48, 0x52, 0x35, 0x49, 0x45, 0x78, 0x30, 0x5a, 0x44,
  0x41, 0x65, 0x46, 0x77, 0x30, 0x79, 0x4d, 0x54, 0x45, 0x77, 0x4d, 0x54,
  0x49, 0x78, 0x4f, 0x44, 0x55, 0x78, 0x4e, 0x54, 0x4a, 0x61, 0x46, 0x77,
  0x30, 0x79, 0x4d, 0x6a, 0x45, 0x77, 0x0a, 0x4d, 0x54, 0x49, 0x78, 0x4f,
  0x44, 0x55, 0x78, 0x4e, 0x54, 0x4a, 0x61, 0x4d, 0x45, 0x55, 0x78, 0x43,
  0x7a, 0x41, 0x4a, 0x42, 0x67, 0x4e, 0x56, 0x42, 0x41, 0x59, 0x54, 0x41,
  0x6b, 0x46, 0x56, 0x4d, 0x52, 0x4d, 0x77, 0x45, 0x51, 0x59, 0x44, 0x56,
  0x51, 0x51, 0x49, 0x44, 0x41, 0x70, 0x54, 0x62, 0x32, 0x31, 0x6c, 0x4c,
  0x56, 0x4e, 0x30, 0x59, 0x58, 0x52, 0x6c, 0x4d, 0x53, 0x45, 0x77, 0x0a,
  0x48, 0x77, 0x59, 0x44, 0x56, 0x51, 0x51, 0x4b, 0x44, 0x42, 0x68, 0x4a,
  0x62, 0x6e, 0x52, 0x6c, 0x63, 0x6d, 0x35, 0x6c, 0x64, 0x43, 0x42, 0x58,
  0x61, 0x57, 0x52, 0x6e, 0x61, 0x58, 0x52, 0x7a, 0x49, 0x46, 0x42, 0x30,
  0x65, 0x53, 0x42, 0x4d, 0x64, 0x47, 0x51, 0x77, 0x58, 0x44, 0x41, 0x4e,
  0x42, 0x67, 0x6b, 0x71, 0x68, 0x6b, 0x69, 0x47, 0x39, 0x77, 0x30, 0x42,
  0x41, 0x51, 0x45, 0x46, 0x0a, 0x41, 0x41, 0x4e, 0x4c, 0x41, 0x44, 0x42,
  0x49, 0x41, 0x6b, 0x45, 0x41, 0x38, 0x33, 0x73, 0x63, 0x44, 0x67, 0x73,
  0x49, 0x4a, 0x61, 0x61, 0x79, 0x72, 0x71, 0x39, 0x65, 0x79, 0x63, 0x72,
  0x61, 0x4f, 0x65, 0x45, 0x7a, 0x35, 0x70, 0x61, 0x64, 0x72, 0x59, 0x49,
  0x4d, 0x66, 0x72, 0x4b, 0x48, 0x64, 0x33, 0x4c, 0x44, 0x6f, 0x36, 0x4d,
  0x46, 0x4c, 0x63, 0x32, 0x57, 0x44, 0x72, 0x4c, 0x51, 0x0a, 0x76, 0x71,
  0x52, 0x68, 0x49, 0x48, 0x45, 0x33, 0x67, 0x62, 0x2b, 0x77, 0x2f, 0x34,
  0x34, 0x57, 0x46, 0x53, 0x36, 0x69, 0x6d, 0x4e, 0x33, 0x4e, 0x69, 0x32,
  0x76, 0x4e, 0x54, 0x34, 0x4e, 0x52, 0x4d, 0x51, 0x49, 0x44, 0x41, 0x51,
  0x41, 0x42, 0x6f, 0x31, 0x4d, 0x77, 0x55, 0x54, 0x41, 0x64, 0x42, 0x67,
  0x4e, 0x56, 0x48, 0x51, 0x34, 0x45, 0x46, 0x67, 0x51, 0x55, 0x68, 0x37,
  0x38, 0x62, 0x0a, 0x4e, 0x38, 0x50, 0x75, 0x75, 0x63, 0x74, 0x6d, 0x57,
  0x67, 0x61, 0x32, 0x64, 0x37, 0x71, 0x73, 0x39, 0x45, 0x64, 0x44, 0x66,
  0x6f, 0x30, 0x77, 0x48, 0x77, 0x59, 0x44, 0x56, 0x52, 0x30, 0x6a, 0x42,
  0x42, 0x67, 0x77, 0x46, 0x6f, 0x41, 0x55, 0x68, 0x37, 0x38, 0x62, 0x4e,
  0x38, 0x50, 0x75, 0x75, 0x63, 0x74, 0x6d, 0x57, 0x67, 0x61, 0x32, 0x64,
  0x37, 0x71, 0x73, 0x39, 0x45, 0x64, 0x44, 0x0a, 0x66, 0x6f, 0x30, 0x77,
  0x44, 0x77, 0x59, 0x44, 0x56, 0x52, 0x30, 0x54, 0x41, 0x51, 0x48, 0x2f,
  0x42, 0x41, 0x55, 0x77, 0x41, 0x77, 0x45, 0x42, 0x2f, 0x7a, 0x41, 0x4e,
  0x42, 0x67, 0x6b, 0x71, 0x68, 0x6b, 0x69, 0x47, 0x39, 0x77, 0x30, 0x42,
  0x41, 0x51, 0x73, 0x46, 0x41, 0x41, 0x4e, 0x42, 0x41, 0x4b, 0x32, 0x49,
  0x56, 0x4d, 0x6c, 0x56, 0x69, 0x37, 0x2b, 0x67, 0x76, 0x67, 0x71, 0x2b,
  0x0a, 0x31, 0x6c, 0x66, 0x59, 0x48, 0x43, 0x33, 0x59, 0x46, 0x38, 0x41,
  0x49, 0x37, 0x64, 0x61, 0x70, 0x6a, 0x68, 0x4f, 0x64, 0x47, 0x31, 0x58,
  0x63, 0x48, 0x45, 0x56, 0x34, 0x59, 0x31, 0x63, 0x47, 0x6f, 0x48, 0x68,
  0x33, 0x55, 0x47, 0x2f, 0x48, 0x64, 0x71, 0x38, 0x37, 0x2f, 0x74, 0x34,
  0x59, 0x6a, 0x75, 0x72, 0x44, 0x67, 0x34, 0x32, 0x68, 0x53, 0x6d, 0x47,
  0x39, 0x41, 0x57, 0x71, 0x5a, 0x0a, 0x49, 0x4f, 0x48, 0x46, 0x78, 0x44,
  0x45, 0x3d, 0x0a, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x45, 0x4e, 0x44, 0x20,
  0x43, 0x45, 0x52, 0x54, 0x49, 0x46, 0x49, 0x43, 0x41, 0x54, 0x45, 0x2d,
  0x2d, 0x2d, 0x2d, 0x2d, 0x0a
};
unsigned int cert_pem_len = 713;

void configure_context(SSL_CTX *ctx)
{
    // SSL_CTX_set_ecdh_auto(ctx, 1);

    // Set the cert.
    X509* cert = X509_new();
    BIO* bio_cert = BIO_new_mem_buf(cert_pem, cert_pem_len);
    PEM_read_bio_X509(bio_cert, &cert, NULL, NULL);
    BIO_free(bio_cert);

    if (SSL_CTX_use_certificate(ctx, cert) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }


    // Set the private key.
    EVP_PKEY *key = EVP_PKEY_new();
    BIO* bio_key = BIO_new_mem_buf(key_pem, key_pem_len);
    PEM_read_bio_PrivateKey(bio_key, &key, NULL, NULL);
    BIO_free(bio_key);

    if (SSL_CTX_use_PrivateKey(ctx, key) <= 0 ) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
}

void handle_connection(int sock, SSL_CTX *ctx) {
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    SSL *ssl;
    const char reply[] = "Logged in\n";
    char password[128] = {0};

    int client = accept(sock, (struct sockaddr*)&addr, &len);
    if (client < 0) {
        perror("Unable to accept");
        exit(EXIT_FAILURE);
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, client);

    if (SSL_accept(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    }
    else {
        // size_t length;
	cc_ssl_should_taint_incoming = 1;
        SSL_read(ssl, password, 127);
	cc_ssl_should_taint_incoming = 0;

        //printf("%s\n", password);
        SSL_write(ssl, reply, strlen(reply));
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    shutdown(client, SHUT_WR);
    close(client);
}

int main(int argc, char **argv)
{
    int sock;
    SSL_CTX *ctx;

    init_openssl();
    ctx = create_context();

    configure_context(ctx);

    sock = create_socket(4433);

    /* Handle connections */
    cc_current_label = label0;
    handle_connection(sock, ctx);
    cc_current_label = label1;
    handle_connection(sock, ctx);

    close(sock);
    SSL_CTX_free(ctx);
    cleanup_openssl();
}

