all:
	gcc matmul.c -o prog
wasm:
	emcc -O3  matmul.c -s EXPORTED_FUNCTIONS='["_main"]' -o Matmul.html
	emrun Matmul.html

