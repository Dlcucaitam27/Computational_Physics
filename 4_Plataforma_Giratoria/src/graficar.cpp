#include <fstream>
#include <cstdlib>
#include "../include/funciones.h"
using namespace std;

void graficarComparativo(const string &archivo1, const string &archivo2, 
                        const string &imagen) {
    ofstream gp("scripts/plot_plataforma.gp");
    
    gp << "set terminal pngcairo size 1200,800\n";
    gp << "set output '" << imagen << "'\n";
    gp << "set multiplot layout 2,2 title 'Disparo desde Plataforma Giratoria'\n";
    gp << "set grid\n";
    
    gp << "set title 'Trayectoria 3D'\n";
    gp << "splot '" << archivo1 << "' using 2:3:4 with lines lw 2 title 'Inercial',\\\n";
    gp << "      '" << archivo2 << "' using 2:3:4 with lines lw 2 title 'No Inercial'\n";
    
    gp << "set title 'Posicion X(t)'\n";
    gp << "plot '" << archivo1 << "' using 1:2 with lines lw 2 title 'Inercial',\\\n";
    gp << "     '" << archivo2 << "' using 1:2 with lines lw 2 title 'No Inercial'\n";
    
    gp << "set title 'Posicion Y(t)'\n";
    gp << "plot '" << archivo1 << "' using 1:3 with lines lw 2 title 'Inercial',\\\n";
    gp << "     '" << archivo2 << "' using 1:3 with lines lw 2 title 'No Inercial'\n";
    
    gp << "set title 'Posicion Z(t)'\n";
    gp << "plot '" << archivo1 << "' using 1:4 with lines lw 2 title 'Inercial',\\\n";
    gp << "     '" << archivo2 << "' using 1:4 with lines lw 2 title 'No Inercial'\n";
    
    gp << "unset multiplot\n";
    gp.close();
    
    system("gnuplot scripts/plot_plataforma.gp");
}