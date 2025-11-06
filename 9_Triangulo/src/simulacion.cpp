#include <iostream>
#include <fstream>
#include <cmath>
#include "../include/funciones.h"
using namespace std;

void solicitarDatos(double &L, double &x0, double &y0, double &vx0, double &vy0, 
                    double &t0, double &tf, double &dt) {
    cout << "Lado del triángulo L (m): "; cin >> L;
    cout << "Posición inicial x0 (m): "; cin >> x0;
    cout << "Posición inicial y0 (m): "; cin >> y0;
    cout << "Velocidad inicial vx0 (m/s): "; cin >> vx0;
    cout << "Velocidad inicial vy0 (m/s): "; cin >> vy0;
    cout << "Tiempo final tf (s): "; cin >> tf;
    cout << "Paso dt (s): "; cin >> dt;
    t0 = 0.0;
}

bool validarTriangulo(double L, double x0, double y0) {
    double h = sqrt(3.0)/2.0 * L;
    return (y0 >= 0) && (y0 <= sqrt(3)*x0) && (y0 <= -sqrt(3)*(x0 - L)) && (y0 <= h);
}

void rebotar(double &x, double &y, double &vx, double &vy, double L) {
    double h = sqrt(3.0)/2.0 * L;
    
    // Rebote con base (y = 0)
    if (y < 0) {
        y = -y;
        vy = -vy;
        return;
    }
    
    // Rebote con lado izquierdo (y = √3x)
    if (y > sqrt(3)*x) {
        double nx = -sqrt(3)/2.0, ny = 0.5;
        double dot = vx*nx + vy*ny;
        vx -= 2*dot*nx;
        vy -= 2*dot*ny;
        return;
    }
    
    // Rebote con lado derecho (y = -√3(x - L))
    if (y > -sqrt(3)*(x - L)) {
        double nx = sqrt(3)/2.0, ny = 0.5;
        double dot = vx*nx + vy*ny;
        vx -= 2*dot*nx;
        vy -= 2*dot*ny;
        return;
    }
}

void simularMovimiento(double L, double x0, double y0, double vx0, double vy0,
                       double t0, double tf, double dt, const string &archivo) {
    ofstream file(archivo);
    ofstream rebotes("results/rebotes.dat");
    file << "t x y\n";
    rebotes << "t lado x y vx vy\n";
    
    double t = t0, x = x0, y = y0, vx = vx0, vy = vy0;
    double h = sqrt(3.0)/2.0 * L;
    int i = 0;
    
    while (t <= tf) {
        file << t << " " << x << " " << y << "\n";
        
        // Verificar colisión antes de mover (similar al nuevo código)
        double new_x = x + vx * dt;
        double new_y = y + vy * dt;
        
        // Detección de colisiones con los tres lados
        bool rebote = false;
        int lado = -1;
        
        // Base (y = 0)
        if (new_y < 0) {
            new_y = -new_y;
            vy = -vy;
            rebote = true;
            lado = 0;
        }
        // Lado izquierdo (y = √3x)
        else if (new_y > sqrt(3)*new_x) {
            double nx = -sqrt(3)/2.0, ny = 0.5;
            double dot = vx*nx + vy*ny;
            vx -= 2*dot*nx;
            vy -= 2*dot*ny;
            rebote = true;
            lado = 1;
        }
        // Lado derecho (y = -√3(x - L))
        else if (new_y > -sqrt(3)*(new_x - L)) {
            double nx = sqrt(3)/2.0, ny = 0.5;
            double dot = vx*nx + vy*ny;
            vx -= 2*dot*nx;
            vy -= 2*dot*ny;
            rebote = true;
            lado = 2;
        }
        
        if (rebote) {
            rebotes << t << " " << lado << " " << new_x << " " << new_y << " " << vx << " " << vy << "\n";
        }
        
        x = new_x;
        y = new_y;
        i++;
        t = t0 + i * dt;
    }
    
    file.close();
    rebotes.close();
    cout << "Datos guardados en: " << archivo << " y results/rebotes.dat" << endl;
}