
SOURCES := $(shell find . -name '*.c')
OPENSSLDIR := ../openssl
OPENSSLFILES := $(shell find ${OPENSSLDIR}/ssl -name '*.o') $(shell find ${OPENSSLDIR}/crypto -name '*.o')
PICOLIBC_HOME := ../picolibc/build/image/picolibc/x86_64-unknown-fromager
CLANG_DIR=$(shell clang${LLVM_SUFFIX} -print-resource-dir)
CFLAGS=-flto -mprefer-vector-width=1 \
    -nostdinc                         \
    -isystem $(CLANG_DIR)/include     \
    -isystem $(PICOLIBC_HOME)/include \
    -ggdb                             \
    -Os
CC := clang${LLVM_SUFFIX} ${CFLAGS}

all: server server-secret picolib

server:
	$(CC) -I../openssl/include -c src/server.c -o server.o

server-secret:
	$(CC) -I../openssl/include -c src/server-secret.c -o server-secret.o

picolib: $(SOURCES)
	cc_secret_objects=server-secret.o \
	cc_objects="${OPENSSLFILES} server.o" \
	COMPILER_RT_HOME=/home/james/sieve/cheesecloth/llvm-project/compiler-rt/build \
	  $(PICOLIBC_HOME)/lib/fromager-link.sh
#         --override=libavcodec/libavcodec.a


