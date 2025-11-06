#include <fstream>
#include <cstdlib>
#include <iostream>
#include "../include/funciones.h"
using namespace std;

void generarGraficas() {
    ofstream gp("scripts/graficas.gp");
    
    gp << "set terminal pngcairo size 1000,800\n";
    gp << "set output 'results/graficas_comparativas.png'\n";
    gp << "set multiplot layout 2,2 title 'Caja 1D - Colisiones Inelásticas'\n";
    gp << "set grid\n";
    
    gp << "set title 'Posición vs Tiempo'\n";
    gp << "set xlabel 't (s)'\n";
    gp << "set ylabel 'x (m)'\n";
    gp << "plot 'results/analisis.dat' using 1:2 with lines lw 2 lc 'blue' title 'x(t)'\n";
    
    gp << "set title 'Velocidad vs Tiempo'\n";
    gp << "set xlabel 't (s)'\n";
    gp << "set ylabel 'v (m/s)'\n";
    gp << "plot 'results/analisis.dat' using 1:3 with lines lw 2 lc 'red' title 'v(t)'\n";
    
    gp << "set title 'Energía Cinética vs Tiempo'\n";
    gp << "set xlabel 't (s)'\n";
    gp << "set ylabel 'E_k (J)'\n";
    gp << "plot 'results/analisis.dat' using 1:4 with lines lw 2 lc 'green' title 'E_k(t)'\n";
    
    gp << "set title 'Espacio Fase (x vs v)'\n";
    gp << "set xlabel 'x (m)'\n";
    gp << "set ylabel 'v (m/s)'\n";
    gp << "plot 'results/analisis.dat' using 2:3 with lines lw 1 lc 'purple' title 'Espacio fase'\n";
    
    gp << "unset multiplot\n";
    gp.close();
    
    system("gnuplot scripts/graficas.gp");
    cout << "Gráficas generadas: results/graficas_comparativas.png\n";
}