
SOURCES := $(shell find . -name '*.c')

compile: $(SOURCES)
	clang -I../openssl/include -L../openssl $< -lssl -lcrypto -o server
