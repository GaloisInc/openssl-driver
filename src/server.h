#ifndef SERVER_H
#define SERVER_H

#ifdef __APPLE__
# define SECRET_GLOBAL      __attribute__((section("__DATA,__secret")))
# define SECRET_GLOBAL_RO   __attribute__((section("__TEXT,__secret")))
#else
# define SECRET_GLOBAL      __attribute__((section(".data.secret")))
# define SECRET_GLOBAL_RO   __attribute__((section(".rodata.secret")))
#endif

extern unsigned char read_buf_14[61] SECRET_GLOBAL_RO;
extern unsigned char read_buf_15[5] SECRET_GLOBAL_RO;
extern unsigned char read_buf_16[3] SECRET_GLOBAL_RO;

#endif
