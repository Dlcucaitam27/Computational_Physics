#include <iostream>
#include "../include/funciones.h"
using namespace std;

int main() {
    double L, x0, v0, t0, tf, dt, e;
    solicitarDatos(L, x0, v0, t0, tf, dt, e);
    simularMovimiento(L, x0, v0, t0, tf, dt, e);
    generarGraficas();
    generarAnimacion();
    return 0;
}