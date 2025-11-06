#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "../include/funciones.h"
using namespace std;

void graficarTrayectoria(double L, const string &archivo, const string &imagen) {
    ofstream gp("scripts/plot_triangulo.gp");
    double h = sqrt(3.0)/2.0 * L;
    
    gp << "set terminal pngcairo size 1200,800\n";
    gp << "set output '" << imagen << "'\n";
    gp << "set multiplot layout 2,2 title 'Partícula en Triángulo Equilátero'\n";
    gp << "set grid\n";
    
    // Trayectoria 2D con rebotes (como en el nuevo código)
    gp << "set title 'Trayectoria y puntos de rebote'\n";
    gp << "set xlabel 'x (m)'\n";
    gp << "set ylabel 'y (m)'\n";
    gp << "set size ratio -1\n";
    gp << "plot '" << archivo << "' using 2:3 with lines lw 2 lc 'blue' title 'Trayectoria',\\\n";
    gp << "     'results/rebotes.dat' using 3:4 with points pt 7 ps 1.5 lc 'red' title 'Puntos de rebote',\\\n";
    gp << "     '-' with lines lw 3 lc 'black' title 'Triángulo'\n";
    gp << "0 0\n" << L << " 0\n" << L/2 << " " << h << "\n0 0\n";
    gp << "e\n";
    
    // x(t) - posición vs tiempo
    gp << "set title 'Evolución temporal de x(t)'\n";
    gp << "set xlabel 't (s)'\n";
    gp << "set ylabel 'x (m)'\n";
    gp << "plot '" << archivo << "' using 1:2 with lines lw 2 lc 'red' title 'x(t)'\n";
    
    // y(t) - posición vs tiempo  
    gp << "set title 'Evolución temporal de y(t)'\n";
    gp << "set xlabel 't (s)'\n";
    gp << "set ylabel 'y (m)'\n";
    gp << "plot '" << archivo << "' using 1:3 with lines lw 2 lc 'green' title 'y(t)'\n";
    
    // Velocidades (si están disponibles)
    gp << "set title 'Energía y dinámica'\n";
    gp << "set xlabel 't (s)'\n";
    gp << "set ylabel 'Valor'\n";
    gp << "plot '" << archivo << "' using 1:2 with lines lw 1 lc 'orange' title 'x(t)',\\\n";
    gp << "     '" << archivo << "' using 1:3 with lines lw 1 lc 'purple' title 'y(t)'\n";
    
    gp << "unset multiplot\n";
    gp.close();
    
    system("gnuplot scripts/plot_triangulo.gp");
    cout << "Gráfico generado: " << imagen << endl;
}