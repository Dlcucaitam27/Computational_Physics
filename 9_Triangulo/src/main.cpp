#include <iostream>
#include <cmath>
#include "../include/funciones.h"
using namespace std;

int main() {
    double L, x0, y0, vx0, vy0, t0, tf, dt;
    
    const string datos = "results/trayectoria.dat";
    const string grafico = "results/triangulo_grafico.png";
    const string anim = "results/triangulo_anim.gif";

    solicitarDatos(L, x0, y0, vx0, vy0, t0, tf, dt);
    
    if (!validarTriangulo(L, x0, y0)) {
        cerr << "ERROR: Posición inicial fuera del triángulo\n";
        return 1;
    }

    simularMovimiento(L, x0, y0, vx0, vy0, t0, tf, dt, datos);
    // Después de simularMovimiento()
cout << "Verificando archivo de datos...\n";
system("head -5 results/trayectoria.dat");
system("wc -l results/trayectoria.dat");
    graficarTrayectoria(L, datos, grafico);
    generarAnimacion(L, datos, anim);
    
    return 0;
}