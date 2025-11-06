#include <fstream>
#include <cstdlib>
#include <iostream>
#include "../include/funciones.h"
using namespace std;

void generarAnimacion() {
    ofstream gp("scripts/animacion.gp");
    
    gp << "set terminal gif animate delay 8 size 800,600\n";
    gp << "set output 'results/caja1D_anim.gif'\n";
    gp << "set title 'Movimiento en Caja 1D - Colisiones Inelásticas'\n";
    gp << "set xlabel 'Tiempo (s)'\n";
    gp << "set ylabel 'Posición (m)'\n";
    gp << "set grid\n\n";
    
    gp << "stats 'results/datos_gif.dat' using 1 nooutput\n";
    gp << "N = STATS_records\n";
    gp << "step = int(N/50) + 1\n\n";
    
    gp << "do for [i=1:N:step] {\n";
    gp << "    plot 'results/datos_gif.dat' every ::1::i using 1:2 with lines lw 2 lc 'blue' title 'Trayectoria'\n";
    gp << "}\n";
    gp << "unset output\n";
    gp.close();
    
    cout << "Generando animación GIF...\n";
    system("gnuplot scripts/animacion.gp");
    cout << "Animación guardada: results/caja1D_anim.gif\n";
}