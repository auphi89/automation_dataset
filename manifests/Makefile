CC ?= cc
CFLAGS += -O2 $(shell pkg-config --cflags openssl)
LDLIBS += -lssl -lcrypto

tls_client: tls_client.o
	$(CC) -o $@ $^ $(LDLIBS)
