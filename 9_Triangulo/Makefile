.PHONY: all build run clean

all: run

build:
	mkdir -p bin results scripts
	g++ src/main.cpp src/simulacion.cpp src/graficar.cpp src/animacion.cpp -Iinclude -o bin/triangulo

run: build
	./bin/triangulo

clean:
	rm -f bin/triangulo results/* scripts/*.gp