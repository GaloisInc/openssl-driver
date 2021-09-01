
SOURCES := $(shell find . -name '*.c')
OPENSSLDIR := ../openssl
OPENSSLFILES := $(shell find ${OPENSSLDIR}/ssl -name '*.o') $(shell find ${OPENSSLDIR}/crypto -name '*.o')
CC := clang${LLVM_SUFFIX} -flto -O1 -mprefer-vector-width=1 $(CFLAGS)
PICOLIBC_HOME := ../picolibc/build/image/picolibc/x86_64-unknown-fromager

# Instructions:
# clang-9 -flto -O1 -mprefer-vector-width=1  -I../openssl/include -c src/server.c -o server.o
# llvm-link-9 $(find ../openssl/{ssl,crypto} -name '*.o') server.o -o server.bc
# opt-9 --internalize --internalize-public-api-list=main --strip-debug --force-vector-width=1 -O3 --scalarizer -O1 server.bc -o server-opt.bc
# llvm-dis-9 server-opt.bc -o server.ll
# sed -i -e 's/nofree//g' server.ll

# fromager: $(SOURCES)
# 	$(CC) -I$(OPENSSLDIR)/include -c src/server.c -o server.o
# 	# llvm-link${LLVM_SUFFIX} ../openssl/*/*.o server.o -o server.bc
# 	llvm-link${LLVM_SUFFIX} -L$(OPENSSLDIR) -lssl -lcrypto server.o -o server.bc
# 	opt${LLVM_SUFFIX} --internalize --internalize-public-api-list=main --strip-debug --force-vector-width=1 -O3 --scalarizer -O1 server.bc -o server-opt.bc
# 	llvm-dis${LLVM_SUFFIX} server-opt.bc -o server.ll

compile: $(SOURCES)
	$(CC) -I$(OPENSSLDIR)/include -L$(OPENSSLDIR) $< -lssl -lcrypto -o server

llvm: $(SOURCES)
	$(CC) -I$(OPENSSLDIR)/include $< -S -emit-llvm -o server.c.ll

picolib: $(SOURCES)
	cc_objects="${OPENSSLFILES} server.o" \
	  $(PICOLIBC_HOME)/lib/fromager-link.sh
#         --override=libavcodec/libavcodec.a
#	cc_secret_objects=build/fromager/driver_secret.bc \

