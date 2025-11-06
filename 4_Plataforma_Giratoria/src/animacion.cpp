#include <fstream>
#include <cstdlib>
#include <iostream>
#include "../include/funciones.h"
using namespace std;

void generarAnimacionPlataforma(const string &archivo1, const string &archivo2,
                               double w, double d, const string &gifSalida) {
    ofstream gp("scripts/animate_plataforma.gp");
    
    gp << "data1='" << archivo1 << "'\n";
    gp << "data2='" << archivo2 << "'\n";
    gp << "giffile='" << gifSalida << "'\n\n";
    
    gp << "set terminal gif animate delay 30 size 1200,900\n";
    gp << "set output giffile\n";
    gp << "set title 'Plataforma Giratoria - Trayectorias 3D'\n";
    gp << "set grid\n";
    gp << "set xlabel 'X (m)'\n";
    gp << "set ylabel 'Y (m)'\n";
    gp << "set zlabel 'Z (m)'\n";
    
    // Rangos más amplios para ver las parábolas
    gp << "set xrange [-15:15]\n";
    gp << "set yrange [-15:15]\n";
    gp << "set zrange [0:20]\n\n";
    
    gp << "N1 = int(system(sprintf(\"wc -l < %s\", data1))) - 1\n";
    gp << "N2 = int(system(sprintf(\"wc -l < %s\", data2))) - 1\n";
    gp << "N = (N1 > N2) ? N1 : N2\n";
    gp << "step = int(N/80) + 1\n\n";
    
    gp << "R = " << d << "\n\n";
    
    gp << "do for [i=1:N:step] {\n";
    gp << "    # Vista desde arriba y ladeada para ver la parábola en Z\n";
    gp << "    set view 45, 30, 1, 1\n";
    gp << "    set parametric\n";
    gp << "    set urange [0:2*pi]\n";
    gp << "    splot R*cos(u), R*sin(u)-9, 0 with lines lc 'gray' lw 1 title 'Plataforma', \\\n";
    gp << "          data1 every ::1::i using 2:(3-11.5):4 with lines lc 'blue' lw 3 title 'Inercial', \\\n";
    gp << "          data2 every ::1::i using 2:(3-11.5):4 with lines lc 'red' lw 3 title 'No Inercial', \\\n";
    gp << "          data1 every ::i::i using 2:(3-11.5):4 with points pt 7 ps 2 lc 'blue' title '', \\\n";
    gp << "          data2 every ::i::i using 2:(3-11.5):4 with points pt 7 ps 2 lc 'red' title ''\n";
    gp << "}\n";
    gp << "unset output\n";
    gp.close();
    
    cout << "Generando animación...\n";
    system("gnuplot scripts/animate_plataforma.gp");
    cout << "Animación guardada en: " << gifSalida << endl;
}