#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

// Función auxiliar para contar líneas
int contarLineas(const string &archivo) {
    ifstream file(archivo);
    int count = 0;
    string line;
    while (getline(file, line)) {
        count++;
    }
    file.close();
    return count - 1; // Restar 1 si tiene encabezado
}

void generarAnimacion(double L, const string &archivo, const string &gifSalida) {
    // Contar puntos totales
    int totalLineas = contarLineas(archivo);
    cout << "Total de puntos: " << totalLineas << endl;
    
    // Crear archivo con las coordenadas del triángulo
    ofstream triangulo("scripts/triangulo.dat");
    double h = sqrt(3.0)/2.0 * L;
    triangulo << "0 0\n";
    triangulo << L << " 0\n";
    triangulo << L/2 << " " << h << "\n";
    triangulo << "0 0\n";
    triangulo.close();
    
    // Calcular frames para cubrir todos los datos
    int lines_per_frame = 5;  // Menos líneas por frame = más frames = más suave
    int nframes = (totalLineas + lines_per_frame - 1) / lines_per_frame;
    
    cout << "Generando " << nframes << " frames..." << endl;
    
    // Crear el script de Gnuplot
    ofstream gp("scripts/animate_triangulo.gp");
    
    gp << "set terminal gif animate delay 5 size 800,600\n";
    gp << "set output '" << gifSalida << "'\n";
    gp << "set xrange [0:" << L << "]\n";
    gp << "set yrange [0:" << h << "]\n";
    gp << "set size ratio -1\n";
    gp << "set grid\n";
    gp << "set title 'Partícula confinada en un triángulo'\n\n";
    
    gp << "nframes = " << nframes << "\n";
    gp << "lines_per_frame = " << lines_per_frame << "\n";
    gp << "total_lines = " << totalLineas << "\n\n";
    
    gp << "do for [i=1:nframes] {\n";
    gp << "    frame_end = (i * lines_per_frame > total_lines) ? total_lines : i * lines_per_frame\n";
    gp << "    plot '" << archivo << "' every ::1::frame_end using 2:3 with lines lc rgb 'blue' title 'Trayectoria',\\\n";
    gp << "         '" << archivo << "' every ::frame_end::frame_end using 2:3 with points pt 7 ps 2 lc rgb 'red' notitle,\\\n";
    gp << "         'scripts/triangulo.dat' with lines lw 2 lc rgb 'black' notitle\n";
    gp << "}\n\n";
    
    gp << "unset output\n";
    gp.close();
    
    cout << "Generando GIF (puede tardar unos segundos)...\n";
    int result = system("gnuplot scripts/animate_triangulo.gp");
    
    if (result == 0)
        cout << "Animación completada: " << gifSalida << endl;
    else
        cout << "Error al ejecutar Gnuplot. Verifica que esté instalado y en el PATH.\n";
}