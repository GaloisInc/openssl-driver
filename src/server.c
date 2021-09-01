
// From: https://wiki.openssl.org/index.php/Simple_TLS_Server

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

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

    method = SSLv23_server_method();

    ctx = SSL_CTX_new(method);
    if (!ctx) {
	perror("Unable to create SSL context");
	ERR_print_errors_fp(stderr);
	exit(EXIT_FAILURE);
    }

    return ctx;
}

unsigned char key_pem[] = {
  0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x42, 0x45, 0x47, 0x49, 0x4e, 0x20, 0x50,
  0x52, 0x49, 0x56, 0x41, 0x54, 0x45, 0x20, 0x4b, 0x45, 0x59, 0x2d, 0x2d,
  0x2d, 0x2d, 0x2d, 0x0a, 0x4d, 0x49, 0x49, 0x4a, 0x51, 0x77, 0x49, 0x42,
  0x41, 0x44, 0x41, 0x4e, 0x42, 0x67, 0x6b, 0x71, 0x68, 0x6b, 0x69, 0x47,
  0x39, 0x77, 0x30, 0x42, 0x41, 0x51, 0x45, 0x46, 0x41, 0x41, 0x53, 0x43,
  0x43, 0x53, 0x30, 0x77, 0x67, 0x67, 0x6b, 0x70, 0x41, 0x67, 0x45, 0x41,
  0x41, 0x6f, 0x49, 0x43, 0x41, 0x51, 0x43, 0x75, 0x70, 0x61, 0x77, 0x4d,
  0x61, 0x75, 0x77, 0x70, 0x75, 0x66, 0x6f, 0x49, 0x0a, 0x52, 0x35, 0x39,
  0x44, 0x37, 0x31, 0x32, 0x59, 0x66, 0x4c, 0x4d, 0x4b, 0x4c, 0x61, 0x76,
  0x7a, 0x59, 0x44, 0x7a, 0x78, 0x37, 0x61, 0x53, 0x58, 0x32, 0x74, 0x79,
  0x6a, 0x48, 0x52, 0x6e, 0x6e, 0x78, 0x59, 0x67, 0x4d, 0x55, 0x6e, 0x42,
  0x51, 0x32, 0x64, 0x65, 0x6a, 0x68, 0x32, 0x4f, 0x43, 0x76, 0x78, 0x76,
  0x74, 0x41, 0x35, 0x55, 0x38, 0x7a, 0x54, 0x64, 0x33, 0x50, 0x6a, 0x59,
  0x67, 0x0a, 0x45, 0x45, 0x45, 0x6d, 0x51, 0x4b, 0x36, 0x2b, 0x39, 0x49,
  0x4b, 0x43, 0x58, 0x68, 0x50, 0x52, 0x6b, 0x79, 0x6c, 0x57, 0x6c, 0x78,
  0x6d, 0x6b, 0x6b, 0x48, 0x5a, 0x6f, 0x6c, 0x57, 0x59, 0x79, 0x64, 0x54,
  0x72, 0x33, 0x74, 0x38, 0x54, 0x51, 0x79, 0x2f, 0x71, 0x36, 0x36, 0x78,
  0x38, 0x4a, 0x70, 0x6d, 0x66, 0x57, 0x2b, 0x45, 0x6b, 0x6a, 0x62, 0x7a,
  0x47, 0x34, 0x2b, 0x35, 0x61, 0x64, 0x0a, 0x44, 0x49, 0x65, 0x35, 0x47,
  0x59, 0x71, 0x37, 0x36, 0x56, 0x72, 0x78, 0x75, 0x31, 0x47, 0x74, 0x6f,
  0x38, 0x70, 0x46, 0x73, 0x39, 0x39, 0x75, 0x62, 0x6f, 0x41, 0x47, 0x35,
  0x67, 0x77, 0x73, 0x41, 0x72, 0x57, 0x61, 0x67, 0x43, 0x6a, 0x41, 0x75,
  0x31, 0x41, 0x48, 0x73, 0x59, 0x2b, 0x4b, 0x68, 0x69, 0x35, 0x53, 0x2b,
  0x78, 0x48, 0x4d, 0x62, 0x48, 0x2f, 0x4d, 0x58, 0x79, 0x37, 0x70, 0x0a,
  0x31, 0x6a, 0x72, 0x70, 0x6c, 0x6e, 0x69, 0x39, 0x44, 0x39, 0x4f, 0x58,
  0x6d, 0x66, 0x2b, 0x2b, 0x51, 0x4b, 0x61, 0x46, 0x65, 0x74, 0x7a, 0x4b,
  0x52, 0x56, 0x4a, 0x47, 0x36, 0x65, 0x2b, 0x4c, 0x4f, 0x31, 0x4c, 0x56,
  0x77, 0x78, 0x41, 0x73, 0x5a, 0x42, 0x58, 0x6d, 0x74, 0x50, 0x69, 0x59,
  0x6a, 0x62, 0x58, 0x51, 0x79, 0x77, 0x61, 0x4a, 0x44, 0x64, 0x36, 0x50,
  0x6a, 0x70, 0x44, 0x32, 0x0a, 0x52, 0x44, 0x63, 0x69, 0x77, 0x64, 0x72,
  0x51, 0x61, 0x32, 0x42, 0x46, 0x73, 0x62, 0x71, 0x58, 0x65, 0x4d, 0x4a,
  0x44, 0x6a, 0x51, 0x54, 0x64, 0x57, 0x31, 0x6e, 0x46, 0x53, 0x4b, 0x57,
  0x46, 0x4c, 0x54, 0x78, 0x47, 0x4d, 0x79, 0x35, 0x44, 0x2f, 0x76, 0x4c,
  0x4b, 0x56, 0x78, 0x4c, 0x61, 0x2b, 0x79, 0x32, 0x51, 0x31, 0x38, 0x56,
  0x71, 0x63, 0x76, 0x66, 0x48, 0x6b, 0x54, 0x62, 0x74, 0x0a, 0x48, 0x4f,
  0x6a, 0x50, 0x34, 0x35, 0x44, 0x54, 0x50, 0x4f, 0x44, 0x6f, 0x50, 0x6b,
  0x53, 0x46, 0x30, 0x5a, 0x6b, 0x38, 0x70, 0x43, 0x2f, 0x63, 0x69, 0x7a,
  0x51, 0x53, 0x58, 0x67, 0x6d, 0x38, 0x52, 0x4c, 0x7a, 0x64, 0x73, 0x46,
  0x35, 0x4a, 0x6f, 0x63, 0x61, 0x65, 0x6c, 0x44, 0x65, 0x58, 0x6b, 0x47,
  0x62, 0x75, 0x56, 0x49, 0x51, 0x52, 0x55, 0x54, 0x73, 0x49, 0x4c, 0x66,
  0x6b, 0x51, 0x0a, 0x57, 0x57, 0x33, 0x4c, 0x6c, 0x68, 0x51, 0x34, 0x6a,
  0x59, 0x4a, 0x75, 0x51, 0x37, 0x44, 0x63, 0x32, 0x50, 0x30, 0x7a, 0x45,
  0x5a, 0x49, 0x6e, 0x4d, 0x4a, 0x37, 0x56, 0x6a, 0x5a, 0x66, 0x57, 0x4b,
  0x54, 0x65, 0x2b, 0x36, 0x74, 0x58, 0x62, 0x32, 0x6a, 0x42, 0x66, 0x73,
  0x46, 0x42, 0x77, 0x75, 0x56, 0x46, 0x45, 0x31, 0x67, 0x52, 0x45, 0x77,
  0x45, 0x30, 0x50, 0x38, 0x56, 0x71, 0x45, 0x0a, 0x6a, 0x4d, 0x74, 0x62,
  0x6a, 0x4f, 0x73, 0x6b, 0x70, 0x37, 0x58, 0x38, 0x45, 0x46, 0x4a, 0x4c,
  0x5a, 0x49, 0x76, 0x74, 0x4b, 0x55, 0x71, 0x34, 0x38, 0x73, 0x4e, 0x4b,
  0x37, 0x67, 0x4a, 0x44, 0x56, 0x66, 0x77, 0x68, 0x66, 0x4a, 0x78, 0x6a,
  0x6d, 0x35, 0x36, 0x36, 0x75, 0x65, 0x41, 0x39, 0x43, 0x42, 0x36, 0x33,
  0x31, 0x71, 0x66, 0x56, 0x53, 0x48, 0x34, 0x34, 0x38, 0x4a, 0x67, 0x50,
  0x0a, 0x31, 0x48, 0x30, 0x36, 0x4a, 0x48, 0x51, 0x61, 0x32, 0x63, 0x64,
  0x76, 0x68, 0x6d, 0x43, 0x4c, 0x5a, 0x49, 0x57, 0x74, 0x6d, 0x68, 0x74,
  0x46, 0x38, 0x45, 0x34, 0x7a, 0x65, 0x2b, 0x54, 0x66, 0x61, 0x36, 0x31,
  0x74, 0x47, 0x67, 0x45, 0x49, 0x58, 0x79, 0x4c, 0x39, 0x55, 0x78, 0x46,
  0x2f, 0x66, 0x68, 0x33, 0x55, 0x30, 0x4f, 0x46, 0x74, 0x66, 0x5a, 0x36,
  0x49, 0x4b, 0x76, 0x71, 0x79, 0x0a, 0x63, 0x48, 0x72, 0x31, 0x4e, 0x66,
  0x72, 0x47, 0x6c, 0x77, 0x70, 0x54, 0x6c, 0x66, 0x6b, 0x50, 0x79, 0x65,
  0x51, 0x45, 0x30, 0x6f, 0x33, 0x6f, 0x43, 0x2b, 0x56, 0x57, 0x4f, 0x53,
  0x46, 0x49, 0x75, 0x2b, 0x64, 0x74, 0x57, 0x77, 0x30, 0x30, 0x39, 0x43,
  0x4c, 0x65, 0x65, 0x6c, 0x2f, 0x73, 0x69, 0x4e, 0x42, 0x46, 0x52, 0x5a,
  0x4b, 0x48, 0x35, 0x4b, 0x7a, 0x48, 0x2f, 0x76, 0x55, 0x30, 0x0a, 0x62,
  0x35, 0x45, 0x70, 0x5a, 0x65, 0x47, 0x6a, 0x32, 0x4e, 0x42, 0x6d, 0x48,
  0x56, 0x43, 0x45, 0x51, 0x6a, 0x44, 0x38, 0x59, 0x6e, 0x42, 0x68, 0x35,
  0x65, 0x67, 0x39, 0x57, 0x51, 0x49, 0x44, 0x41, 0x51, 0x41, 0x42, 0x41,
  0x6f, 0x49, 0x43, 0x41, 0x44, 0x7a, 0x44, 0x6f, 0x37, 0x4c, 0x47, 0x57,
  0x4e, 0x6a, 0x44, 0x76, 0x6a, 0x79, 0x33, 0x50, 0x72, 0x43, 0x53, 0x54,
  0x63, 0x78, 0x4b, 0x0a, 0x52, 0x72, 0x6a, 0x5a, 0x33, 0x79, 0x50, 0x55,
  0x62, 0x68, 0x2f, 0x32, 0x67, 0x50, 0x66, 0x63, 0x7a, 0x44, 0x74, 0x73,
  0x57, 0x71, 0x45, 0x4c, 0x56, 0x79, 0x53, 0x43, 0x59, 0x6c, 0x57, 0x66,
  0x46, 0x61, 0x6e, 0x74, 0x35, 0x79, 0x2b, 0x4d, 0x63, 0x70, 0x6a, 0x71,
  0x55, 0x44, 0x68, 0x52, 0x5a, 0x6d, 0x54, 0x30, 0x6e, 0x6a, 0x78, 0x56,
  0x71, 0x33, 0x55, 0x31, 0x75, 0x42, 0x62, 0x30, 0x0a, 0x56, 0x35, 0x77,
  0x6f, 0x51, 0x31, 0x6a, 0x39, 0x6a, 0x4c, 0x70, 0x31, 0x35, 0x42, 0x51,
  0x66, 0x74, 0x7a, 0x4c, 0x34, 0x47, 0x42, 0x43, 0x69, 0x50, 0x52, 0x77,
  0x48, 0x4d, 0x6c, 0x45, 0x37, 0x52, 0x30, 0x64, 0x56, 0x6d, 0x76, 0x7a,
  0x75, 0x69, 0x74, 0x35, 0x2b, 0x6b, 0x47, 0x50, 0x6c, 0x77, 0x6a, 0x55,
  0x4d, 0x52, 0x41, 0x44, 0x73, 0x5a, 0x53, 0x52, 0x2f, 0x77, 0x49, 0x64,
  0x55, 0x0a, 0x7a, 0x37, 0x47, 0x66, 0x62, 0x50, 0x47, 0x76, 0x4e, 0x53,
  0x63, 0x2f, 0x53, 0x42, 0x50, 0x53, 0x47, 0x6e, 0x56, 0x4d, 0x41, 0x52,
  0x77, 0x6d, 0x37, 0x53, 0x79, 0x4f, 0x50, 0x70, 0x2b, 0x67, 0x44, 0x46,
  0x35, 0x41, 0x35, 0x79, 0x4a, 0x5a, 0x51, 0x54, 0x44, 0x5a, 0x37, 0x66,
  0x31, 0x6b, 0x47, 0x71, 0x72, 0x75, 0x79, 0x78, 0x48, 0x4d, 0x32, 0x62,
  0x35, 0x2f, 0x2f, 0x67, 0x34, 0x35, 0x0a, 0x76, 0x58, 0x4c, 0x58, 0x76,
  0x2b, 0x56, 0x66, 0x39, 0x52, 0x41, 0x6f, 0x43, 0x54, 0x33, 0x50, 0x46,
  0x4b, 0x74, 0x62, 0x70, 0x56, 0x36, 0x61, 0x43, 0x31, 0x34, 0x59, 0x65,
  0x6a, 0x34, 0x58, 0x72, 0x49, 0x38, 0x53, 0x6c, 0x42, 0x50, 0x76, 0x36,
  0x6a, 0x78, 0x31, 0x42, 0x78, 0x63, 0x55, 0x58, 0x6b, 0x55, 0x77, 0x59,
  0x7a, 0x74, 0x72, 0x7a, 0x49, 0x73, 0x70, 0x53, 0x34, 0x71, 0x4d, 0x0a,
  0x63, 0x58, 0x69, 0x4f, 0x4e, 0x38, 0x2b, 0x50, 0x30, 0x6e, 0x64, 0x53,
  0x54, 0x30, 0x6a, 0x39, 0x43, 0x61, 0x54, 0x63, 0x65, 0x38, 0x70, 0x30,
  0x54, 0x4b, 0x35, 0x59, 0x44, 0x46, 0x62, 0x59, 0x45, 0x33, 0x31, 0x58,
  0x41, 0x6c, 0x5a, 0x79, 0x59, 0x67, 0x34, 0x74, 0x4a, 0x4b, 0x43, 0x2b,
  0x30, 0x33, 0x72, 0x36, 0x43, 0x56, 0x52, 0x43, 0x5a, 0x4c, 0x5a, 0x41,
  0x42, 0x52, 0x6b, 0x47, 0x0a, 0x68, 0x61, 0x4d, 0x51, 0x71, 0x6c, 0x2b,
  0x73, 0x75, 0x36, 0x59, 0x33, 0x76, 0x53, 0x36, 0x30, 0x32, 0x42, 0x75,
  0x6d, 0x39, 0x5a, 0x42, 0x2f, 0x6e, 0x39, 0x53, 0x6c, 0x64, 0x65, 0x4c,
  0x4e, 0x5a, 0x34, 0x2b, 0x51, 0x30, 0x44, 0x72, 0x50, 0x51, 0x4f, 0x44,
  0x38, 0x4e, 0x6b, 0x43, 0x4e, 0x65, 0x6d, 0x69, 0x33, 0x5a, 0x57, 0x34,
  0x75, 0x47, 0x44, 0x31, 0x69, 0x43, 0x61, 0x38, 0x79, 0x0a, 0x6b, 0x44,
  0x71, 0x36, 0x37, 0x41, 0x46, 0x72, 0x68, 0x70, 0x4f, 0x53, 0x61, 0x6f,
  0x49, 0x6d, 0x35, 0x4a, 0x56, 0x6c, 0x35, 0x55, 0x2f, 0x50, 0x34, 0x70,
  0x6b, 0x69, 0x78, 0x37, 0x7a, 0x36, 0x33, 0x36, 0x5a, 0x78, 0x4f, 0x38,
  0x4e, 0x37, 0x6e, 0x68, 0x63, 0x61, 0x36, 0x37, 0x50, 0x6b, 0x51, 0x42,
  0x34, 0x48, 0x68, 0x77, 0x41, 0x6a, 0x59, 0x55, 0x7a, 0x44, 0x43, 0x4a,
  0x79, 0x38, 0x0a, 0x42, 0x77, 0x31, 0x2b, 0x68, 0x51, 0x72, 0x71, 0x73,
  0x31, 0x6f, 0x4b, 0x51, 0x6e, 0x4d, 0x6c, 0x71, 0x69, 0x45, 0x6c, 0x48,
  0x48, 0x55, 0x44, 0x6b, 0x4e, 0x44, 0x68, 0x43, 0x4c, 0x34, 0x73, 0x7a,
  0x75, 0x32, 0x74, 0x47, 0x55, 0x78, 0x48, 0x45, 0x54, 0x59, 0x61, 0x4e,
  0x47, 0x49, 0x75, 0x59, 0x6f, 0x53, 0x59, 0x77, 0x47, 0x30, 0x4d, 0x6b,
  0x52, 0x56, 0x54, 0x47, 0x32, 0x7a, 0x42, 0x0a, 0x72, 0x6e, 0x4a, 0x79,
  0x4f, 0x35, 0x42, 0x34, 0x54, 0x74, 0x68, 0x6a, 0x4d, 0x63, 0x59, 0x68,
  0x68, 0x55, 0x62, 0x74, 0x47, 0x78, 0x58, 0x37, 0x58, 0x6e, 0x53, 0x46,
  0x33, 0x68, 0x46, 0x30, 0x36, 0x57, 0x78, 0x76, 0x74, 0x33, 0x38, 0x33,
  0x55, 0x44, 0x54, 0x2b, 0x31, 0x51, 0x75, 0x50, 0x58, 0x34, 0x31, 0x78,
  0x49, 0x2f, 0x38, 0x55, 0x4d, 0x4c, 0x32, 0x73, 0x6e, 0x48, 0x47, 0x2b,
  0x0a, 0x69, 0x4c, 0x55, 0x74, 0x43, 0x6e, 0x64, 0x43, 0x78, 0x4f, 0x51,
  0x52, 0x67, 0x52, 0x52, 0x55, 0x6a, 0x70, 0x51, 0x64, 0x4b, 0x35, 0x43,
  0x34, 0x6e, 0x66, 0x44, 0x42, 0x42, 0x55, 0x71, 0x47, 0x4e, 0x65, 0x57,
  0x34, 0x50, 0x48, 0x51, 0x7a, 0x4b, 0x2f, 0x36, 0x51, 0x62, 0x49, 0x72,
  0x58, 0x78, 0x54, 0x44, 0x4f, 0x62, 0x6c, 0x76, 0x2b, 0x79, 0x53, 0x71,
  0x41, 0x7a, 0x52, 0x72, 0x53, 0x0a, 0x71, 0x56, 0x55, 0x64, 0x44, 0x52,
  0x65, 0x73, 0x43, 0x6a, 0x51, 0x69, 0x61, 0x63, 0x64, 0x57, 0x6a, 0x62,
  0x43, 0x68, 0x41, 0x6f, 0x49, 0x42, 0x41, 0x51, 0x44, 0x67, 0x5a, 0x63,
  0x57, 0x33, 0x6e, 0x71, 0x66, 0x67, 0x77, 0x4d, 0x53, 0x34, 0x69, 0x62,
  0x2b, 0x75, 0x6d, 0x54, 0x63, 0x59, 0x47, 0x2f, 0x45, 0x67, 0x37, 0x43,
  0x66, 0x38, 0x75, 0x76, 0x36, 0x6e, 0x4e, 0x7a, 0x79, 0x4c, 0x0a, 0x70,
  0x4c, 0x71, 0x4f, 0x64, 0x38, 0x32, 0x39, 0x69, 0x6b, 0x45, 0x70, 0x65,
  0x72, 0x58, 0x70, 0x61, 0x6b, 0x64, 0x71, 0x74, 0x33, 0x35, 0x68, 0x69,
  0x48, 0x62, 0x47, 0x4b, 0x55, 0x58, 0x38, 0x46, 0x34, 0x6a, 0x30, 0x77,
  0x71, 0x30, 0x75, 0x71, 0x4e, 0x73, 0x4d, 0x32, 0x72, 0x72, 0x34, 0x34,
  0x66, 0x6d, 0x65, 0x59, 0x30, 0x5a, 0x6a, 0x4b, 0x52, 0x2f, 0x6d, 0x47,
  0x66, 0x6f, 0x7a, 0x0a, 0x58, 0x4e, 0x32, 0x4f, 0x63, 0x6e, 0x73, 0x35,
  0x30, 0x50, 0x6f, 0x4c, 0x46, 0x42, 0x67, 0x33, 0x48, 0x74, 0x58, 0x52,
  0x73, 0x61, 0x46, 0x31, 0x67, 0x4f, 0x57, 0x57, 0x51, 0x31, 0x43, 0x53,
  0x7a, 0x66, 0x33, 0x44, 0x78, 0x72, 0x4b, 0x47, 0x44, 0x4e, 0x4f, 0x41,
  0x6d, 0x55, 0x2f, 0x70, 0x56, 0x57, 0x7a, 0x31, 0x68, 0x77, 0x43, 0x52,
  0x79, 0x4d, 0x6f, 0x33, 0x36, 0x32, 0x44, 0x64, 0x0a, 0x38, 0x33, 0x50,
  0x77, 0x49, 0x41, 0x77, 0x53, 0x6d, 0x44, 0x43, 0x53, 0x4c, 0x63, 0x52,
  0x62, 0x48, 0x49, 0x6f, 0x59, 0x32, 0x37, 0x71, 0x61, 0x76, 0x7a, 0x4d,
  0x51, 0x47, 0x50, 0x78, 0x65, 0x73, 0x34, 0x43, 0x4c, 0x58, 0x6a, 0x2b,
  0x4e, 0x59, 0x66, 0x79, 0x50, 0x31, 0x33, 0x6f, 0x6f, 0x61, 0x45, 0x76,
  0x64, 0x39, 0x6c, 0x69, 0x35, 0x36, 0x46, 0x77, 0x4d, 0x59, 0x6c, 0x59,
  0x32, 0x0a, 0x71, 0x73, 0x37, 0x4a, 0x35, 0x59, 0x5a, 0x71, 0x42, 0x39,
  0x4c, 0x76, 0x30, 0x71, 0x31, 0x63, 0x4f, 0x53, 0x4f, 0x64, 0x6a, 0x70,
  0x6e, 0x77, 0x4c, 0x47, 0x4b, 0x63, 0x73, 0x34, 0x6a, 0x59, 0x35, 0x4b,
  0x4c, 0x65, 0x31, 0x2b, 0x35, 0x43, 0x61, 0x36, 0x56, 0x4d, 0x52, 0x75,
  0x4d, 0x6f, 0x41, 0x56, 0x4c, 0x76, 0x4a, 0x68, 0x2f, 0x30, 0x42, 0x6b,
  0x63, 0x52, 0x6d, 0x4e, 0x39, 0x67, 0x0a, 0x58, 0x4d, 0x53, 0x37, 0x7a,
  0x49, 0x30, 0x68, 0x6b, 0x2f, 0x52, 0x4b, 0x4d, 0x6b, 0x62, 0x44, 0x62,
  0x63, 0x2f, 0x71, 0x48, 0x2f, 0x57, 0x75, 0x4c, 0x73, 0x56, 0x33, 0x48,
  0x79, 0x70, 0x32, 0x31, 0x33, 0x41, 0x4b, 0x52, 0x46, 0x49, 0x4e, 0x76,
  0x6f, 0x75, 0x2b, 0x4a, 0x6b, 0x4b, 0x4e, 0x41, 0x6f, 0x49, 0x42, 0x41,
  0x51, 0x44, 0x48, 0x50, 0x6a, 0x35, 0x70, 0x49, 0x49, 0x49, 0x41, 0x0a,
  0x51, 0x62, 0x6b, 0x52, 0x49, 0x62, 0x49, 0x4d, 0x42, 0x4e, 0x74, 0x72,
  0x47, 0x57, 0x32, 0x56, 0x48, 0x59, 0x57, 0x2f, 0x59, 0x42, 0x74, 0x6f,
  0x42, 0x53, 0x54, 0x6f, 0x74, 0x71, 0x6a, 0x55, 0x63, 0x67, 0x68, 0x4e,
  0x39, 0x71, 0x4e, 0x7a, 0x75, 0x62, 0x48, 0x34, 0x50, 0x41, 0x42, 0x4a,
  0x6a, 0x70, 0x59, 0x46, 0x59, 0x56, 0x50, 0x41, 0x48, 0x39, 0x79, 0x37,
  0x48, 0x67, 0x7a, 0x72, 0x0a, 0x54, 0x54, 0x7a, 0x4a, 0x63, 0x6f, 0x66,
  0x72, 0x59, 0x42, 0x62, 0x31, 0x33, 0x4a, 0x4e, 0x6c, 0x53, 0x44, 0x41,
  0x71, 0x79, 0x32, 0x4d, 0x48, 0x4d, 0x46, 0x78, 0x7a, 0x6d, 0x37, 0x51,
  0x6a, 0x47, 0x78, 0x30, 0x67, 0x32, 0x62, 0x78, 0x49, 0x47, 0x46, 0x78,
  0x77, 0x50, 0x43, 0x34, 0x6e, 0x62, 0x50, 0x78, 0x43, 0x6d, 0x66, 0x62,
  0x4e, 0x72, 0x77, 0x4a, 0x31, 0x79, 0x56, 0x73, 0x72, 0x0a, 0x74, 0x72,
  0x7a, 0x67, 0x54, 0x38, 0x62, 0x46, 0x73, 0x35, 0x32, 0x53, 0x6b, 0x55,
  0x6a, 0x6b, 0x6a, 0x71, 0x30, 0x71, 0x37, 0x2f, 0x31, 0x35, 0x42, 0x51,
  0x69, 0x71, 0x48, 0x46, 0x50, 0x33, 0x2b, 0x78, 0x77, 0x74, 0x6b, 0x56,
  0x74, 0x59, 0x67, 0x2b, 0x36, 0x4b, 0x62, 0x47, 0x39, 0x34, 0x50, 0x70,
  0x44, 0x37, 0x6b, 0x44, 0x65, 0x43, 0x6d, 0x62, 0x6b, 0x6a, 0x45, 0x70,
  0x33, 0x39, 0x0a, 0x36, 0x30, 0x2f, 0x77, 0x4c, 0x73, 0x5a, 0x41, 0x6d,
  0x36, 0x49, 0x78, 0x71, 0x36, 0x61, 0x4c, 0x63, 0x54, 0x2b, 0x53, 0x31,
  0x67, 0x38, 0x6e, 0x7a, 0x32, 0x39, 0x59, 0x4c, 0x4d, 0x55, 0x39, 0x6a,
  0x6c, 0x36, 0x66, 0x33, 0x46, 0x61, 0x33, 0x45, 0x37, 0x69, 0x72, 0x5a,
  0x61, 0x61, 0x49, 0x6a, 0x70, 0x79, 0x6b, 0x34, 0x44, 0x63, 0x55, 0x76,
  0x58, 0x53, 0x6d, 0x38, 0x61, 0x6d, 0x37, 0x0a, 0x6a, 0x68, 0x44, 0x67,
  0x72, 0x37, 0x38, 0x50, 0x45, 0x76, 0x54, 0x6d, 0x56, 0x4b, 0x38, 0x4c,
  0x63, 0x4a, 0x42, 0x77, 0x6c, 0x34, 0x2f, 0x49, 0x2b, 0x30, 0x47, 0x51,
  0x67, 0x45, 0x50, 0x6c, 0x4c, 0x45, 0x77, 0x45, 0x34, 0x67, 0x75, 0x70,
  0x6b, 0x54, 0x36, 0x53, 0x41, 0x6c, 0x36, 0x4f, 0x33, 0x43, 0x4d, 0x44,
  0x46, 0x4f, 0x34, 0x6c, 0x70, 0x65, 0x73, 0x72, 0x6c, 0x44, 0x66, 0x4c,
  0x0a, 0x72, 0x4a, 0x2f, 0x46, 0x50, 0x47, 0x64, 0x75, 0x47, 0x46, 0x6a,
  0x39, 0x41, 0x6f, 0x49, 0x42, 0x41, 0x51, 0x43, 0x35, 0x61, 0x6c, 0x36,
  0x64, 0x41, 0x72, 0x4f, 0x6b, 0x75, 0x71, 0x50, 0x52, 0x39, 0x38, 0x41,
  0x79, 0x2f, 0x4e, 0x62, 0x52, 0x54, 0x51, 0x56, 0x4a, 0x4e, 0x74, 0x6b,
  0x7a, 0x73, 0x79, 0x2b, 0x48, 0x36, 0x39, 0x52, 0x54, 0x62, 0x71, 0x48,
  0x58, 0x35, 0x70, 0x5a, 0x52, 0x0a, 0x37, 0x31, 0x4d, 0x34, 0x65, 0x76,
  0x53, 0x6c, 0x45, 0x66, 0x52, 0x41, 0x38, 0x61, 0x32, 0x7a, 0x32, 0x5a,
  0x61, 0x4b, 0x31, 0x72, 0x2f, 0x46, 0x4e, 0x59, 0x30, 0x73, 0x38, 0x55,
  0x38, 0x34, 0x4a, 0x72, 0x34, 0x5a, 0x4f, 0x51, 0x4d, 0x56, 0x63, 0x32,
  0x4e, 0x57, 0x78, 0x4b, 0x44, 0x38, 0x66, 0x70, 0x61, 0x6c, 0x41, 0x77,
  0x49, 0x43, 0x50, 0x74, 0x47, 0x7a, 0x53, 0x6c, 0x55, 0x58, 0x0a, 0x79,
  0x4e, 0x31, 0x54, 0x47, 0x68, 0x2b, 0x49, 0x4c, 0x43, 0x70, 0x78, 0x51,
  0x6c, 0x30, 0x76, 0x51, 0x6e, 0x70, 0x79, 0x56, 0x74, 0x7a, 0x55, 0x38,
  0x50, 0x43, 0x6d, 0x50, 0x43, 0x42, 0x33, 0x4d, 0x31, 0x48, 0x77, 0x43,
  0x4c, 0x35, 0x48, 0x42, 0x78, 0x63, 0x70, 0x4b, 0x59, 0x77, 0x47, 0x36,
  0x65, 0x70, 0x74, 0x6d, 0x6b, 0x68, 0x49, 0x48, 0x55, 0x6e, 0x48, 0x4f,
  0x44, 0x50, 0x42, 0x0a, 0x69, 0x59, 0x39, 0x59, 0x75, 0x67, 0x68, 0x74,
  0x59, 0x48, 0x2b, 0x62, 0x57, 0x72, 0x51, 0x74, 0x2b, 0x5a, 0x36, 0x76,
  0x78, 0x6e, 0x57, 0x42, 0x71, 0x73, 0x43, 0x6b, 0x61, 0x42, 0x51, 0x4c,
  0x4e, 0x74, 0x51, 0x42, 0x35, 0x77, 0x4a, 0x42, 0x4d, 0x53, 0x79, 0x2f,
  0x45, 0x7a, 0x62, 0x74, 0x4a, 0x6c, 0x6f, 0x6f, 0x77, 0x58, 0x69, 0x4c,
  0x59, 0x30, 0x66, 0x4b, 0x2b, 0x36, 0x53, 0x39, 0x0a, 0x4b, 0x41, 0x6e,
  0x62, 0x73, 0x44, 0x45, 0x65, 0x36, 0x76, 0x66, 0x4b, 0x30, 0x48, 0x48,
  0x53, 0x53, 0x6c, 0x71, 0x52, 0x4d, 0x4b, 0x66, 0x36, 0x7a, 0x37, 0x44,
  0x6b, 0x67, 0x58, 0x65, 0x56, 0x32, 0x6d, 0x79, 0x54, 0x51, 0x6c, 0x2b,
  0x67, 0x52, 0x72, 0x66, 0x49, 0x63, 0x37, 0x41, 0x6a, 0x61, 0x71, 0x78,
  0x2b, 0x6c, 0x64, 0x71, 0x39, 0x50, 0x4f, 0x6f, 0x79, 0x59, 0x79, 0x71,
  0x61, 0x0a, 0x66, 0x43, 0x35, 0x32, 0x77, 0x47, 0x52, 0x49, 0x52, 0x77,
  0x78, 0x74, 0x59, 0x45, 0x73, 0x59, 0x79, 0x66, 0x7a, 0x51, 0x47, 0x53,
  0x68, 0x31, 0x57, 0x6a, 0x35, 0x78, 0x76, 0x56, 0x49, 0x76, 0x6d, 0x53,
  0x72, 0x4f, 0x79, 0x37, 0x35, 0x68, 0x41, 0x6f, 0x49, 0x42, 0x41, 0x51,
  0x43, 0x37, 0x72, 0x6e, 0x42, 0x50, 0x79, 0x75, 0x56, 0x71, 0x70, 0x48,
  0x35, 0x57, 0x47, 0x75, 0x32, 0x43, 0x0a, 0x30, 0x4e, 0x68, 0x33, 0x6a,
  0x46, 0x35, 0x6a, 0x52, 0x6f, 0x6f, 0x45, 0x65, 0x64, 0x32, 0x58, 0x49,
  0x4c, 0x46, 0x68, 0x33, 0x52, 0x34, 0x76, 0x38, 0x4c, 0x4c, 0x4e, 0x37,
  0x66, 0x53, 0x4f, 0x51, 0x47, 0x2f, 0x61, 0x71, 0x33, 0x71, 0x42, 0x7a,
  0x36, 0x53, 0x56, 0x73, 0x4e, 0x61, 0x5a, 0x64, 0x65, 0x6f, 0x52, 0x41,
  0x50, 0x2b, 0x65, 0x62, 0x77, 0x56, 0x42, 0x70, 0x58, 0x64, 0x50, 0x0a,
  0x53, 0x78, 0x61, 0x56, 0x78, 0x6f, 0x2b, 0x35, 0x71, 0x6b, 0x52, 0x6c,
  0x4b, 0x32, 0x30, 0x2f, 0x43, 0x6c, 0x6b, 0x73, 0x4e, 0x5a, 0x46, 0x38,
  0x4f, 0x45, 0x41, 0x35, 0x2f, 0x36, 0x43, 0x53, 0x4d, 0x52, 0x42, 0x79,
  0x55, 0x4e, 0x34, 0x52, 0x47, 0x57, 0x4b, 0x4f, 0x77, 0x6b, 0x56, 0x76,
  0x2f, 0x74, 0x6c, 0x4d, 0x5a, 0x72, 0x35, 0x51, 0x38, 0x54, 0x50, 0x2b,
  0x41, 0x47, 0x66, 0x33, 0x0a, 0x4e, 0x33, 0x6a, 0x49, 0x35, 0x62, 0x35,
  0x4b, 0x50, 0x66, 0x50, 0x31, 0x4c, 0x46, 0x67, 0x53, 0x4e, 0x61, 0x47,
  0x78, 0x7a, 0x44, 0x6c, 0x30, 0x73, 0x4d, 0x41, 0x63, 0x56, 0x48, 0x34,
  0x39, 0x5a, 0x52, 0x6e, 0x41, 0x6e, 0x75, 0x42, 0x70, 0x33, 0x6c, 0x58,
  0x6f, 0x41, 0x6a, 0x4f, 0x6e, 0x2f, 0x48, 0x49, 0x66, 0x44, 0x5a, 0x78,
  0x78, 0x34, 0x63, 0x56, 0x4e, 0x4e, 0x47, 0x4a, 0x66, 0x0a, 0x33, 0x62,
  0x72, 0x74, 0x47, 0x77, 0x6f, 0x6f, 0x39, 0x43, 0x61, 0x30, 0x68, 0x4a,
  0x75, 0x47, 0x48, 0x71, 0x70, 0x39, 0x33, 0x72, 0x35, 0x31, 0x65, 0x37,
  0x53, 0x36, 0x31, 0x57, 0x32, 0x42, 0x79, 0x7a, 0x76, 0x37, 0x69, 0x43,
  0x64, 0x56, 0x48, 0x7a, 0x47, 0x44, 0x52, 0x67, 0x6e, 0x63, 0x71, 0x5a,
  0x4a, 0x47, 0x36, 0x41, 0x48, 0x41, 0x77, 0x4e, 0x51, 0x35, 0x4d, 0x70,
  0x50, 0x41, 0x0a, 0x2b, 0x56, 0x52, 0x6a, 0x32, 0x34, 0x57, 0x41, 0x4f,
  0x79, 0x70, 0x30, 0x52, 0x50, 0x43, 0x57, 0x6d, 0x38, 0x64, 0x6f, 0x2f,
  0x4d, 0x6e, 0x34, 0x43, 0x4d, 0x41, 0x62, 0x49, 0x57, 0x74, 0x6d, 0x38,
  0x59, 0x43, 0x46, 0x50, 0x57, 0x49, 0x68, 0x4a, 0x46, 0x42, 0x2b, 0x79,
  0x4b, 0x71, 0x45, 0x49, 0x45, 0x54, 0x6b, 0x71, 0x68, 0x76, 0x63, 0x36,
  0x65, 0x45, 0x65, 0x68, 0x41, 0x58, 0x52, 0x0a, 0x2b, 0x58, 0x46, 0x70,
  0x41, 0x6f, 0x49, 0x42, 0x41, 0x46, 0x50, 0x64, 0x72, 0x5a, 0x72, 0x46,
  0x53, 0x4b, 0x44, 0x47, 0x6f, 0x56, 0x2b, 0x5a, 0x73, 0x47, 0x4a, 0x6c,
  0x36, 0x4b, 0x64, 0x42, 0x4b, 0x42, 0x6f, 0x44, 0x56, 0x4f, 0x32, 0x74,
  0x6b, 0x54, 0x6f, 0x35, 0x58, 0x70, 0x31, 0x72, 0x74, 0x4b, 0x69, 0x53,
  0x32, 0x37, 0x69, 0x31, 0x4a, 0x76, 0x35, 0x72, 0x63, 0x77, 0x75, 0x30,
  0x0a, 0x4d, 0x5a, 0x6d, 0x6e, 0x6b, 0x62, 0x37, 0x2f, 0x2f, 0x6a, 0x75,
  0x79, 0x6c, 0x6a, 0x71, 0x59, 0x7a, 0x6b, 0x45, 0x46, 0x78, 0x35, 0x6d,
  0x4b, 0x48, 0x6b, 0x6c, 0x63, 0x7a, 0x42, 0x78, 0x70, 0x4c, 0x54, 0x6d,
  0x76, 0x61, 0x37, 0x77, 0x67, 0x76, 0x57, 0x30, 0x69, 0x53, 0x77, 0x5a,
  0x67, 0x73, 0x66, 0x6d, 0x76, 0x74, 0x44, 0x36, 0x4d, 0x41, 0x37, 0x49,
  0x53, 0x2b, 0x39, 0x79, 0x47, 0x0a, 0x6b, 0x5a, 0x46, 0x6f, 0x68, 0x49,
  0x33, 0x42, 0x6f, 0x61, 0x64, 0x6b, 0x4c, 0x4a, 0x34, 0x70, 0x6c, 0x79,
  0x56, 0x76, 0x45, 0x34, 0x62, 0x75, 0x30, 0x74, 0x63, 0x71, 0x51, 0x6b,
  0x55, 0x56, 0x71, 0x70, 0x71, 0x44, 0x4b, 0x54, 0x50, 0x6e, 0x46, 0x61,
  0x56, 0x54, 0x5a, 0x42, 0x35, 0x41, 0x59, 0x32, 0x69, 0x4b, 0x33, 0x38,
  0x59, 0x53, 0x79, 0x69, 0x57, 0x33, 0x57, 0x6b, 0x4d, 0x32, 0x0a, 0x38,
  0x55, 0x39, 0x45, 0x2b, 0x6e, 0x33, 0x51, 0x34, 0x68, 0x2f, 0x47, 0x61,
  0x66, 0x4b, 0x4d, 0x55, 0x58, 0x76, 0x6d, 0x43, 0x62, 0x46, 0x4b, 0x32,
  0x33, 0x38, 0x7a, 0x53, 0x6d, 0x59, 0x53, 0x36, 0x43, 0x2f, 0x33, 0x68,
  0x39, 0x6e, 0x4f, 0x4a, 0x2f, 0x53, 0x59, 0x47, 0x71, 0x43, 0x36, 0x37,
  0x56, 0x70, 0x31, 0x66, 0x71, 0x41, 0x59, 0x52, 0x36, 0x34, 0x50, 0x4e,
  0x38, 0x4b, 0x52, 0x0a, 0x44, 0x7a, 0x33, 0x6c, 0x72, 0x72, 0x6b, 0x45,
  0x4f, 0x44, 0x71, 0x77, 0x62, 0x70, 0x69, 0x30, 0x6e, 0x58, 0x58, 0x62,
  0x74, 0x56, 0x70, 0x42, 0x32, 0x78, 0x42, 0x30, 0x6f, 0x2f, 0x38, 0x34,
  0x50, 0x63, 0x69, 0x6a, 0x33, 0x51, 0x36, 0x74, 0x71, 0x65, 0x48, 0x68,
  0x42, 0x63, 0x69, 0x58, 0x30, 0x77, 0x2f, 0x49, 0x63, 0x73, 0x37, 0x46,
  0x49, 0x7a, 0x33, 0x58, 0x76, 0x37, 0x38, 0x2b, 0x0a, 0x7a, 0x38, 0x68,
  0x57, 0x33, 0x6e, 0x69, 0x72, 0x53, 0x45, 0x68, 0x54, 0x4c, 0x31, 0x58,
  0x31, 0x50, 0x31, 0x48, 0x37, 0x76, 0x47, 0x54, 0x6a, 0x37, 0x2b, 0x52,
  0x61, 0x49, 0x70, 0x34, 0x3d, 0x0a, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x45,
  0x4e, 0x44, 0x20, 0x50, 0x52, 0x49, 0x56, 0x41, 0x54, 0x45, 0x20, 0x4b,
  0x45, 0x59, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a
};
unsigned int key_pem_len = 3272;

unsigned char cert_pem[] = {
  0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x42, 0x45, 0x47, 0x49, 0x4e, 0x20, 0x43,
  0x45, 0x52, 0x54, 0x49, 0x46, 0x49, 0x43, 0x41, 0x54, 0x45, 0x2d, 0x2d,
  0x2d, 0x2d, 0x2d, 0x0a, 0x4d, 0x49, 0x49, 0x46, 0x61, 0x7a, 0x43, 0x43,
  0x41, 0x31, 0x4f, 0x67, 0x41, 0x77, 0x49, 0x42, 0x41, 0x67, 0x49, 0x55,
  0x4c, 0x47, 0x53, 0x76, 0x4e, 0x2b, 0x35, 0x36, 0x6e, 0x30, 0x62, 0x45,
  0x4c, 0x36, 0x49, 0x42, 0x31, 0x66, 0x45, 0x56, 0x79, 0x79, 0x33, 0x78,
  0x68, 0x53, 0x73, 0x77, 0x44, 0x51, 0x59, 0x4a, 0x4b, 0x6f, 0x5a, 0x49,
  0x68, 0x76, 0x63, 0x4e, 0x41, 0x51, 0x45, 0x4c, 0x0a, 0x42, 0x51, 0x41,
  0x77, 0x52, 0x54, 0x45, 0x4c, 0x4d, 0x41, 0x6b, 0x47, 0x41, 0x31, 0x55,
  0x45, 0x42, 0x68, 0x4d, 0x43, 0x51, 0x56, 0x55, 0x78, 0x45, 0x7a, 0x41,
  0x52, 0x42, 0x67, 0x4e, 0x56, 0x42, 0x41, 0x67, 0x4d, 0x43, 0x6c, 0x4e,
  0x76, 0x62, 0x57, 0x55, 0x74, 0x55, 0x33, 0x52, 0x68, 0x64, 0x47, 0x55,
  0x78, 0x49, 0x54, 0x41, 0x66, 0x42, 0x67, 0x4e, 0x56, 0x42, 0x41, 0x6f,
  0x4d, 0x0a, 0x47, 0x45, 0x6c, 0x75, 0x64, 0x47, 0x56, 0x79, 0x62, 0x6d,
  0x56, 0x30, 0x49, 0x46, 0x64, 0x70, 0x5a, 0x47, 0x64, 0x70, 0x64, 0x48,
  0x4d, 0x67, 0x55, 0x48, 0x52, 0x35, 0x49, 0x45, 0x78, 0x30, 0x5a, 0x44,
  0x41, 0x65, 0x46, 0x77, 0x30, 0x79, 0x4d, 0x54, 0x41, 0x34, 0x4d, 0x6a,
  0x41, 0x78, 0x4f, 0x44, 0x4d, 0x78, 0x4e, 0x44, 0x5a, 0x61, 0x46, 0x77,
  0x30, 0x79, 0x4d, 0x6a, 0x41, 0x34, 0x0a, 0x4d, 0x6a, 0x41, 0x78, 0x4f,
  0x44, 0x4d, 0x78, 0x4e, 0x44, 0x5a, 0x61, 0x4d, 0x45, 0x55, 0x78, 0x43,
  0x7a, 0x41, 0x4a, 0x42, 0x67, 0x4e, 0x56, 0x42, 0x41, 0x59, 0x54, 0x41,
  0x6b, 0x46, 0x56, 0x4d, 0x52, 0x4d, 0x77, 0x45, 0x51, 0x59, 0x44, 0x56,
  0x51, 0x51, 0x49, 0x44, 0x41, 0x70, 0x54, 0x62, 0x32, 0x31, 0x6c, 0x4c,
  0x56, 0x4e, 0x30, 0x59, 0x58, 0x52, 0x6c, 0x4d, 0x53, 0x45, 0x77, 0x0a,
  0x48, 0x77, 0x59, 0x44, 0x56, 0x51, 0x51, 0x4b, 0x44, 0x42, 0x68, 0x4a,
  0x62, 0x6e, 0x52, 0x6c, 0x63, 0x6d, 0x35, 0x6c, 0x64, 0x43, 0x42, 0x58,
  0x61, 0x57, 0x52, 0x6e, 0x61, 0x58, 0x52, 0x7a, 0x49, 0x46, 0x42, 0x30,
  0x65, 0x53, 0x42, 0x4d, 0x64, 0x47, 0x51, 0x77, 0x67, 0x67, 0x49, 0x69,
  0x4d, 0x41, 0x30, 0x47, 0x43, 0x53, 0x71, 0x47, 0x53, 0x49, 0x62, 0x33,
  0x44, 0x51, 0x45, 0x42, 0x0a, 0x41, 0x51, 0x55, 0x41, 0x41, 0x34, 0x49,
  0x43, 0x44, 0x77, 0x41, 0x77, 0x67, 0x67, 0x49, 0x4b, 0x41, 0x6f, 0x49,
  0x43, 0x41, 0x51, 0x43, 0x75, 0x70, 0x61, 0x77, 0x4d, 0x61, 0x75, 0x77,
  0x70, 0x75, 0x66, 0x6f, 0x49, 0x52, 0x35, 0x39, 0x44, 0x37, 0x31, 0x32,
  0x59, 0x66, 0x4c, 0x4d, 0x4b, 0x4c, 0x61, 0x76, 0x7a, 0x59, 0x44, 0x7a,
  0x78, 0x37, 0x61, 0x53, 0x58, 0x32, 0x74, 0x79, 0x6a, 0x0a, 0x48, 0x52,
  0x6e, 0x6e, 0x78, 0x59, 0x67, 0x4d, 0x55, 0x6e, 0x42, 0x51, 0x32, 0x64,
  0x65, 0x6a, 0x68, 0x32, 0x4f, 0x43, 0x76, 0x78, 0x76, 0x74, 0x41, 0x35,
  0x55, 0x38, 0x7a, 0x54, 0x64, 0x33, 0x50, 0x6a, 0x59, 0x67, 0x45, 0x45,
  0x45, 0x6d, 0x51, 0x4b, 0x36, 0x2b, 0x39, 0x49, 0x4b, 0x43, 0x58, 0x68,
  0x50, 0x52, 0x6b, 0x79, 0x6c, 0x57, 0x6c, 0x78, 0x6d, 0x6b, 0x6b, 0x48,
  0x5a, 0x6f, 0x0a, 0x6c, 0x57, 0x59, 0x79, 0x64, 0x54, 0x72, 0x33, 0x74,
  0x38, 0x54, 0x51, 0x79, 0x2f, 0x71, 0x36, 0x36, 0x78, 0x38, 0x4a, 0x70,
  0x6d, 0x66, 0x57, 0x2b, 0x45, 0x6b, 0x6a, 0x62, 0x7a, 0x47, 0x34, 0x2b,
  0x35, 0x61, 0x64, 0x44, 0x49, 0x65, 0x35, 0x47, 0x59, 0x71, 0x37, 0x36,
  0x56, 0x72, 0x78, 0x75, 0x31, 0x47, 0x74, 0x6f, 0x38, 0x70, 0x46, 0x73,
  0x39, 0x39, 0x75, 0x62, 0x6f, 0x41, 0x47, 0x0a, 0x35, 0x67, 0x77, 0x73,
  0x41, 0x72, 0x57, 0x61, 0x67, 0x43, 0x6a, 0x41, 0x75, 0x31, 0x41, 0x48,
  0x73, 0x59, 0x2b, 0x4b, 0x68, 0x69, 0x35, 0x53, 0x2b, 0x78, 0x48, 0x4d,
  0x62, 0x48, 0x2f, 0x4d, 0x58, 0x79, 0x37, 0x70, 0x31, 0x6a, 0x72, 0x70,
  0x6c, 0x6e, 0x69, 0x39, 0x44, 0x39, 0x4f, 0x58, 0x6d, 0x66, 0x2b, 0x2b,
  0x51, 0x4b, 0x61, 0x46, 0x65, 0x74, 0x7a, 0x4b, 0x52, 0x56, 0x4a, 0x47,
  0x0a, 0x36, 0x65, 0x2b, 0x4c, 0x4f, 0x31, 0x4c, 0x56, 0x77, 0x78, 0x41,
  0x73, 0x5a, 0x42, 0x58, 0x6d, 0x74, 0x50, 0x69, 0x59, 0x6a, 0x62, 0x58,
  0x51, 0x79, 0x77, 0x61, 0x4a, 0x44, 0x64, 0x36, 0x50, 0x6a, 0x70, 0x44,
  0x32, 0x52, 0x44, 0x63, 0x69, 0x77, 0x64, 0x72, 0x51, 0x61, 0x32, 0x42,
  0x46, 0x73, 0x62, 0x71, 0x58, 0x65, 0x4d, 0x4a, 0x44, 0x6a, 0x51, 0x54,
  0x64, 0x57, 0x31, 0x6e, 0x46, 0x0a, 0x53, 0x4b, 0x57, 0x46, 0x4c, 0x54,
  0x78, 0x47, 0x4d, 0x79, 0x35, 0x44, 0x2f, 0x76, 0x4c, 0x4b, 0x56, 0x78,
  0x4c, 0x61, 0x2b, 0x79, 0x32, 0x51, 0x31, 0x38, 0x56, 0x71, 0x63, 0x76,
  0x66, 0x48, 0x6b, 0x54, 0x62, 0x74, 0x48, 0x4f, 0x6a, 0x50, 0x34, 0x35,
  0x44, 0x54, 0x50, 0x4f, 0x44, 0x6f, 0x50, 0x6b, 0x53, 0x46, 0x30, 0x5a,
  0x6b, 0x38, 0x70, 0x43, 0x2f, 0x63, 0x69, 0x7a, 0x51, 0x53, 0x0a, 0x58,
  0x67, 0x6d, 0x38, 0x52, 0x4c, 0x7a, 0x64, 0x73, 0x46, 0x35, 0x4a, 0x6f,
  0x63, 0x61, 0x65, 0x6c, 0x44, 0x65, 0x58, 0x6b, 0x47, 0x62, 0x75, 0x56,
  0x49, 0x51, 0x52, 0x55, 0x54, 0x73, 0x49, 0x4c, 0x66, 0x6b, 0x51, 0x57,
  0x57, 0x33, 0x4c, 0x6c, 0x68, 0x51, 0x34, 0x6a, 0x59, 0x4a, 0x75, 0x51,
  0x37, 0x44, 0x63, 0x32, 0x50, 0x30, 0x7a, 0x45, 0x5a, 0x49, 0x6e, 0x4d,
  0x4a, 0x37, 0x56, 0x0a, 0x6a, 0x5a, 0x66, 0x57, 0x4b, 0x54, 0x65, 0x2b,
  0x36, 0x74, 0x58, 0x62, 0x32, 0x6a, 0x42, 0x66, 0x73, 0x46, 0x42, 0x77,
  0x75, 0x56, 0x46, 0x45, 0x31, 0x67, 0x52, 0x45, 0x77, 0x45, 0x30, 0x50,
  0x38, 0x56, 0x71, 0x45, 0x6a, 0x4d, 0x74, 0x62, 0x6a, 0x4f, 0x73, 0x6b,
  0x70, 0x37, 0x58, 0x38, 0x45, 0x46, 0x4a, 0x4c, 0x5a, 0x49, 0x76, 0x74,
  0x4b, 0x55, 0x71, 0x34, 0x38, 0x73, 0x4e, 0x4b, 0x0a, 0x37, 0x67, 0x4a,
  0x44, 0x56, 0x66, 0x77, 0x68, 0x66, 0x4a, 0x78, 0x6a, 0x6d, 0x35, 0x36,
  0x36, 0x75, 0x65, 0x41, 0x39, 0x43, 0x42, 0x36, 0x33, 0x31, 0x71, 0x66,
  0x56, 0x53, 0x48, 0x34, 0x34, 0x38, 0x4a, 0x67, 0x50, 0x31, 0x48, 0x30,
  0x36, 0x4a, 0x48, 0x51, 0x61, 0x32, 0x63, 0x64, 0x76, 0x68, 0x6d, 0x43,
  0x4c, 0x5a, 0x49, 0x57, 0x74, 0x6d, 0x68, 0x74, 0x46, 0x38, 0x45, 0x34,
  0x7a, 0x0a, 0x65, 0x2b, 0x54, 0x66, 0x61, 0x36, 0x31, 0x74, 0x47, 0x67,
  0x45, 0x49, 0x58, 0x79, 0x4c, 0x39, 0x55, 0x78, 0x46, 0x2f, 0x66, 0x68,
  0x33, 0x55, 0x30, 0x4f, 0x46, 0x74, 0x66, 0x5a, 0x36, 0x49, 0x4b, 0x76,
  0x71, 0x79, 0x63, 0x48, 0x72, 0x31, 0x4e, 0x66, 0x72, 0x47, 0x6c, 0x77,
  0x70, 0x54, 0x6c, 0x66, 0x6b, 0x50, 0x79, 0x65, 0x51, 0x45, 0x30, 0x6f,
  0x33, 0x6f, 0x43, 0x2b, 0x56, 0x57, 0x0a, 0x4f, 0x53, 0x46, 0x49, 0x75,
  0x2b, 0x64, 0x74, 0x57, 0x77, 0x30, 0x30, 0x39, 0x43, 0x4c, 0x65, 0x65,
  0x6c, 0x2f, 0x73, 0x69, 0x4e, 0x42, 0x46, 0x52, 0x5a, 0x4b, 0x48, 0x35,
  0x4b, 0x7a, 0x48, 0x2f, 0x76, 0x55, 0x30, 0x62, 0x35, 0x45, 0x70, 0x5a,
  0x65, 0x47, 0x6a, 0x32, 0x4e, 0x42, 0x6d, 0x48, 0x56, 0x43, 0x45, 0x51,
  0x6a, 0x44, 0x38, 0x59, 0x6e, 0x42, 0x68, 0x35, 0x65, 0x67, 0x39, 0x0a,
  0x57, 0x51, 0x49, 0x44, 0x41, 0x51, 0x41, 0x42, 0x6f, 0x31, 0x4d, 0x77,
  0x55, 0x54, 0x41, 0x64, 0x42, 0x67, 0x4e, 0x56, 0x48, 0x51, 0x34, 0x45,
  0x46, 0x67, 0x51, 0x55, 0x70, 0x6c, 0x54, 0x43, 0x56, 0x30, 0x69, 0x4c,
  0x48, 0x66, 0x4f, 0x55, 0x37, 0x73, 0x6e, 0x34, 0x45, 0x2b, 0x6a, 0x6f,
  0x63, 0x43, 0x79, 0x4e, 0x6d, 0x71, 0x77, 0x77, 0x48, 0x77, 0x59, 0x44,
  0x56, 0x52, 0x30, 0x6a, 0x0a, 0x42, 0x42, 0x67, 0x77, 0x46, 0x6f, 0x41,
  0x55, 0x70, 0x6c, 0x54, 0x43, 0x56, 0x30, 0x69, 0x4c, 0x48, 0x66, 0x4f,
  0x55, 0x37, 0x73, 0x6e, 0x34, 0x45, 0x2b, 0x6a, 0x6f, 0x63, 0x43, 0x79,
  0x4e, 0x6d, 0x71, 0x77, 0x77, 0x44, 0x77, 0x59, 0x44, 0x56, 0x52, 0x30,
  0x54, 0x41, 0x51, 0x48, 0x2f, 0x42, 0x41, 0x55, 0x77, 0x41, 0x77, 0x45,
  0x42, 0x2f, 0x7a, 0x41, 0x4e, 0x42, 0x67, 0x6b, 0x71, 0x0a, 0x68, 0x6b,
  0x69, 0x47, 0x39, 0x77, 0x30, 0x42, 0x41, 0x51, 0x73, 0x46, 0x41, 0x41,
  0x4f, 0x43, 0x41, 0x67, 0x45, 0x41, 0x6f, 0x75, 0x30, 0x6b, 0x48, 0x41,
  0x70, 0x54, 0x48, 0x4e, 0x48, 0x46, 0x65, 0x55, 0x75, 0x43, 0x6c, 0x54,
  0x34, 0x51, 0x31, 0x37, 0x58, 0x76, 0x2f, 0x34, 0x54, 0x78, 0x4d, 0x42,
  0x63, 0x31, 0x37, 0x41, 0x63, 0x73, 0x33, 0x6c, 0x66, 0x65, 0x4e, 0x58,
  0x61, 0x56, 0x0a, 0x6b, 0x37, 0x4b, 0x41, 0x32, 0x38, 0x6c, 0x58, 0x51,
  0x52, 0x46, 0x36, 0x63, 0x7a, 0x6f, 0x42, 0x76, 0x32, 0x48, 0x63, 0x43,
  0x58, 0x41, 0x73, 0x4e, 0x62, 0x4f, 0x54, 0x4c, 0x50, 0x33, 0x4e, 0x71,
  0x4a, 0x76, 0x58, 0x48, 0x32, 0x74, 0x46, 0x6d, 0x57, 0x7a, 0x6d, 0x47,
  0x70, 0x34, 0x49, 0x74, 0x2b, 0x6b, 0x4e, 0x38, 0x54, 0x41, 0x50, 0x63,
  0x57, 0x65, 0x59, 0x38, 0x43, 0x77, 0x74, 0x0a, 0x43, 0x39, 0x49, 0x34,
  0x2b, 0x41, 0x65, 0x58, 0x47, 0x73, 0x46, 0x72, 0x54, 0x41, 0x47, 0x53,
  0x74, 0x2f, 0x55, 0x6e, 0x7a, 0x43, 0x4c, 0x63, 0x2f, 0x43, 0x31, 0x70,
  0x70, 0x63, 0x53, 0x50, 0x62, 0x38, 0x30, 0x73, 0x33, 0x57, 0x57, 0x70,
  0x37, 0x69, 0x46, 0x69, 0x62, 0x4d, 0x6f, 0x73, 0x61, 0x39, 0x6e, 0x43,
  0x47, 0x38, 0x57, 0x76, 0x6c, 0x2b, 0x49, 0x55, 0x46, 0x54, 0x6c, 0x78,
  0x0a, 0x4e, 0x74, 0x53, 0x46, 0x39, 0x5a, 0x48, 0x62, 0x46, 0x31, 0x70,
  0x41, 0x6e, 0x38, 0x75, 0x39, 0x37, 0x63, 0x43, 0x51, 0x64, 0x6a, 0x54,
  0x4c, 0x7a, 0x41, 0x5a, 0x65, 0x70, 0x37, 0x44, 0x45, 0x4d, 0x4d, 0x79,
  0x53, 0x6b, 0x71, 0x4c, 0x4d, 0x42, 0x52, 0x63, 0x64, 0x36, 0x46, 0x43,
  0x62, 0x35, 0x75, 0x38, 0x4b, 0x65, 0x59, 0x43, 0x67, 0x55, 0x38, 0x48,
  0x4f, 0x48, 0x44, 0x69, 0x48, 0x0a, 0x32, 0x4d, 0x37, 0x30, 0x78, 0x6b,
  0x46, 0x61, 0x64, 0x70, 0x62, 0x59, 0x4c, 0x7a, 0x56, 0x69, 0x55, 0x43,
  0x77, 0x6f, 0x57, 0x52, 0x34, 0x2f, 0x79, 0x6e, 0x57, 0x46, 0x5a, 0x33,
  0x4f, 0x43, 0x70, 0x65, 0x59, 0x51, 0x48, 0x71, 0x74, 0x72, 0x67, 0x31,
  0x64, 0x77, 0x47, 0x78, 0x38, 0x34, 0x6d, 0x64, 0x7a, 0x79, 0x66, 0x4f,
  0x38, 0x6d, 0x44, 0x38, 0x61, 0x56, 0x70, 0x69, 0x59, 0x6e, 0x0a, 0x69,
  0x31, 0x53, 0x30, 0x43, 0x4b, 0x32, 0x41, 0x6c, 0x4c, 0x36, 0x35, 0x4a,
  0x47, 0x6b, 0x6e, 0x39, 0x4b, 0x4d, 0x52, 0x45, 0x74, 0x52, 0x45, 0x2b,
  0x75, 0x70, 0x71, 0x5a, 0x56, 0x4d, 0x6c, 0x69, 0x55, 0x62, 0x62, 0x4c,
  0x65, 0x2f, 0x5a, 0x4d, 0x76, 0x37, 0x4d, 0x4d, 0x54, 0x73, 0x64, 0x46,
  0x50, 0x46, 0x2b, 0x73, 0x71, 0x51, 0x64, 0x61, 0x57, 0x71, 0x61, 0x4a,
  0x30, 0x46, 0x7a, 0x0a, 0x37, 0x6c, 0x79, 0x53, 0x61, 0x62, 0x66, 0x6f,
  0x6c, 0x68, 0x37, 0x30, 0x2f, 0x6b, 0x75, 0x57, 0x30, 0x32, 0x74, 0x77,
  0x2f, 0x51, 0x48, 0x45, 0x36, 0x46, 0x77, 0x65, 0x56, 0x52, 0x33, 0x62,
  0x35, 0x77, 0x61, 0x38, 0x4f, 0x74, 0x74, 0x48, 0x58, 0x2f, 0x4b, 0x35,
  0x74, 0x4c, 0x50, 0x7a, 0x76, 0x4a, 0x5a, 0x62, 0x6d, 0x31, 0x54, 0x54,
  0x52, 0x53, 0x4b, 0x54, 0x64, 0x78, 0x44, 0x45, 0x0a, 0x6e, 0x45, 0x61,
  0x76, 0x38, 0x42, 0x64, 0x30, 0x64, 0x61, 0x39, 0x47, 0x68, 0x79, 0x33,
  0x69, 0x68, 0x55, 0x53, 0x63, 0x4b, 0x4a, 0x6d, 0x76, 0x67, 0x54, 0x57,
  0x72, 0x4a, 0x71, 0x56, 0x57, 0x35, 0x68, 0x63, 0x4c, 0x2f, 0x31, 0x64,
  0x33, 0x42, 0x49, 0x69, 0x46, 0x68, 0x70, 0x66, 0x58, 0x72, 0x6b, 0x4a,
  0x72, 0x55, 0x58, 0x45, 0x32, 0x66, 0x48, 0x47, 0x79, 0x66, 0x53, 0x54,
  0x6d, 0x0a, 0x5a, 0x36, 0x52, 0x64, 0x35, 0x6d, 0x38, 0x35, 0x4b, 0x58,
  0x55, 0x44, 0x55, 0x37, 0x72, 0x35, 0x6b, 0x48, 0x65, 0x52, 0x73, 0x6b,
  0x48, 0x36, 0x44, 0x72, 0x71, 0x4e, 0x36, 0x5a, 0x2f, 0x77, 0x57, 0x38,
  0x65, 0x47, 0x77, 0x5a, 0x4f, 0x4b, 0x2f, 0x59, 0x6f, 0x76, 0x67, 0x32,
  0x30, 0x76, 0x49, 0x35, 0x4d, 0x67, 0x4f, 0x44, 0x48, 0x59, 0x65, 0x63,
  0x76, 0x30, 0x4f, 0x44, 0x61, 0x4e, 0x0a, 0x58, 0x53, 0x34, 0x54, 0x68,
  0x77, 0x6e, 0x79, 0x4b, 0x33, 0x49, 0x72, 0x47, 0x38, 0x62, 0x52, 0x6b,
  0x37, 0x6a, 0x39, 0x76, 0x72, 0x52, 0x6f, 0x6e, 0x66, 0x70, 0x72, 0x6a,
  0x61, 0x6b, 0x49, 0x57, 0x6e, 0x56, 0x2f, 0x32, 0x38, 0x48, 0x38, 0x63,
  0x2f, 0x65, 0x4a, 0x53, 0x38, 0x53, 0x4d, 0x31, 0x78, 0x48, 0x2f, 0x75,
  0x64, 0x55, 0x46, 0x57, 0x4c, 0x57, 0x32, 0x79, 0x79, 0x37, 0x72, 0x0a,
  0x2f, 0x46, 0x70, 0x4e, 0x68, 0x34, 0x37, 0x49, 0x62, 0x52, 0x7a, 0x36,
  0x74, 0x56, 0x2f, 0x6e, 0x62, 0x2b, 0x2f, 0x6c, 0x4a, 0x37, 0x6e, 0x78,
  0x4a, 0x67, 0x4f, 0x35, 0x45, 0x58, 0x62, 0x38, 0x7a, 0x45, 0x65, 0x69,
  0x37, 0x36, 0x69, 0x79, 0x76, 0x61, 0x4c, 0x47, 0x6a, 0x69, 0x5a, 0x31,
  0x6e, 0x57, 0x6d, 0x59, 0x71, 0x62, 0x58, 0x2f, 0x54, 0x6f, 0x44, 0x4f,
  0x73, 0x48, 0x45, 0x3d, 0x0a, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x45, 0x4e,
  0x44, 0x20, 0x43, 0x45, 0x52, 0x54, 0x49, 0x46, 0x49, 0x43, 0x41, 0x54,
  0x45, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a
};
unsigned int cert_pem_len = 1939;

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
    uint len = sizeof(addr);
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
        size_t length;
        SSL_read(ssl, password, 127);
        printf("%s\n", password);
        SSL_write(ssl, reply, strlen(reply));
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
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
    handle_connection(sock, ctx);
    handle_connection(sock, ctx);

    close(sock);
    SSL_CTX_free(ctx);
    cleanup_openssl();
}

