
Compile driver
==============

Make sure openssl and picolibc are built.
Compile the driver with `clang-9 -flto -O1 -mprefer-vector-width=1  -I../openssl/include -c src/server.c -o server.o`.
Link the driver with `LLVM_SUFFIX=-9 make picolib`.

Run exploit
===========

Run the driver server with `./driver &`.
Run the client with the victim request and the exploit request with `./heartbleed.py --rawoutfile bled.raw`.

