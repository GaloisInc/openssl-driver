
SOURCES := $(shell find . -name '*.c')

compile: $(SOURCES)
	clang -I/usr/local/opt/openssl/include -L/usr/local/opt/openssl/lib -lssl $< -o server
