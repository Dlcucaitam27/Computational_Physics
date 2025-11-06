#include <iostream>
#include "../include/funciones.h"
using namespace std;

int main() {
    double w, d, v0, theta, phi, t0, tf, dt;
    int sistema;
    
    const string inercial = "results/inercial.dat";
    const string noinercial = "results/noinercial.dat";
    const string grafico = "results/comparativo.png";
    const string anim = "results/plataforma_anim.gif";

    solicitarDatos(w, d, v0, theta, phi, t0, tf, dt, sistema);
    
    if(sistema == 1 || sistema == 3) {
        simularInercial(w, d, v0, theta, phi, t0, tf, dt, inercial);
    }
    if(sistema == 2 || sistema == 3) {
        simularNoInercial(w, d, v0, theta, phi, t0, tf, dt, noinercial);
    }
    
    if(sistema == 3) {
        graficarComparativo(inercial, noinercial, grafico);
        generarAnimacionPlataforma(inercial, noinercial, w, d, anim);
    }
    
    return 0;
}