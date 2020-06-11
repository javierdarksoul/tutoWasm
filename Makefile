all:
	gcc matmul.c -o prog
matmul:
	emcc -O3  matmul.c -s EXPORTED_FUNCTIONS='["_main"]' -o Matmul.html
covid:
	em++ -O3 Covid.cpp -s ALLOW_MEMORY_GROWTH=1 -s EXPORTED_FUNCTIONS='["_main"]'  -o covid.html --preload-file input

