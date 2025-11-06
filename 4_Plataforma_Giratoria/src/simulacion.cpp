#include <iostream>
#include <fstream>
#include <cmath>
#include "../include/funciones.h"
using namespace std;

void solicitarDatos(double &w, double &d, double &v0, double &theta, 
                    double &phi, double &t0, double &tf, double &dt, int &sistema) {
    cout << "Velocidad angular w (rad/s): "; cin >> w;
    cout << "Distancia al centro d (m): "; cin >> d;
    cout << "Velocidad inicial v0 (m/s): "; cin >> v0;
    cout << "Angulo theta (grados): "; cin >> theta;
    cout << "Angulo phi (grados): "; cin >> phi;
    cout << "Tiempo final tf (s): "; cin >> tf;
    cout << "Paso dt (s): "; cin >> dt;
    cout << "Sistema (1=Inercial, 2=NoInercial, 3=Ambos): "; cin >> sistema;
    
    theta *= M_PI/180.0;
    phi *= M_PI/180.0;
    t0 = 0.0;
}

void simularInercial(double w, double d, double v0, double theta, double phi,
                     double t0, double tf, double dt, const string &archivo) {
    ofstream file(archivo);
    file << "t x y z\n";
    
    double t = t0;
    double x = d, y = 0, z = 0;
    double vx = v0 * cos(theta) * cos(phi);
    double vy = v0 * cos(theta) * sin(phi) + w*d;
    double vz = v0 * sin(theta);
    double g = 9.81;
    
    while(t <= tf && z >= 0) {
        file << t << " " << x << " " << y << " " << z << "\n";
        
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        vz -= g * dt;
        t += dt;
    }
    file.close();
}

void simularNoInercial(double w, double d, double v0, double theta, double phi,
                       double t0, double tf, double dt, const string &archivo) {
    ofstream file(archivo);
    file << "t x y z\n";
    
    double t = t0;
    double x = d, y = 0, z = 0;
    double vx = v0 * cos(theta) * cos(phi);
    double vy = v0 * cos(theta) * sin(phi);
    double vz = v0 * sin(theta);
    double g = 9.81;
    
    while(t <= tf && z >= 0) {
        file << t << " " << x << " " << y << " " << z << "\n";
        
        double ax = 2*w*vy + w*w*x;
        double ay = -2*w*vx + w*w*y;
        double az = -g;
        
        vx += ax * dt;
        vy += ay * dt;
        vz += az * dt;
        
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        t += dt;
    }
    file.close();
}