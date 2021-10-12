
Compile driver
==============

Make sure openssl and picolibc are built.
Compile the driver with `clang-9 -flto -O1 -mprefer-vector-width=1  -I../openssl/include -c src/server.c -o server.o`.
Link the driver with `LLVM_SUFFIX=-9 make picolib`.

Run exploit
===========

Run the driver server with `./driver &`.
Run the client with the victim request and the exploit request with `./heartbleed.py --rawoutfile bled.raw`.

Generate certificate
====================

Use the following if you need to generate a self signed certificate for the driver server.

```
openssl req -x509 -newkey rsa:512 -nodes -keyout key.pem -out cert.pem -days 365
xxd -i key.pem
xxd -i cert.pem
```

