.PHONY: all build run clean

all: run

build:
	mkdir -p bin results scripts
	g++ src/main.cpp src/simulacion.cpp src/graficar.cpp src/animacion.cpp -Iinclude -o bin/plataforma

run: build
	./bin/plataforma

clean:
	rm -f bin/plataforma results/* scripts/*.gp