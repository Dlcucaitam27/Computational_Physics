.PHONY: all build run clean

all: run


build:
	mkdir -p bin results scripts
	g++ src/main.cpp src/simulacion.cpp src/graficar.cpp src/animacion.cpp -Iinclude -o bin/ejecutar

run: build
	./bin/ejecutar

clean:
	rm -f bin/ejecutar results/* scripts/*.gp"
