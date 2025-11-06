#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "../include/funciones.h"
using namespace std;

void solicitarDatos(double &L, double &x0, double &v0, double &t0, double &tf, double &dt, double &e) {
    cout << "Longitud de la caja L (m): "; cin >> L;
    while (L <= 0.0) { 
        cout << "L debe ser positivo. Ingrese L: "; 
        cin >> L; 
    }

    cout << "Posición inicial x0 (m): "; cin >> x0;
    while (x0 < 0.0 || x0 > L) {
        cout << "x0 debe estar en [0, L]. Ingrese x0: ";
        cin >> x0; 
    }

    cout << "Velocidad inicial v0 (m/s): "; cin >> v0;
    while (v0 == 0.0) {
        cout << "v0 no puede ser 0. Ingrese v0: "; 
        cin >> v0; 
    }

    cout << "Coeficiente de restitución e (0 < e ≤ 1): "; cin >> e;
    while (e <= 0.0 || e > 1.0) { cout << "Ingrese e válido: "; cin >> e; }

    cout << "Tiempo inicial t0 (s): "; cin >> t0;
    while (t0 < 0.0) { 
        cout << "Debe ser positivo. Ingrese t0: "; 
        cin >> t0; 
    }

    cout << "Tiempo final tf (s): "; cin >> tf;
    while (tf <= t0) { 
        cout << "tf debe ser mayor que t0. Ingrese tf: "; 
        cin >> tf; 
    }

    cout << "Paso de tiempo dt (s): "; cin >> dt;
    while (dt <= 0.0 || dt > tf - t0) { 
        cout << "dt debe ser positivo y menor que (tf - t0). Ingrese dt: "; 
        cin >> dt; 
    }
}

void simularMovimiento(double L, double x0, double v0, double t0, double tf, double dt, double e) {
    ofstream gifFile("results/datos_gif.dat");
    ofstream analisis("results/analisis.dat");
    
    gifFile << fixed << setprecision(5) << "t x v\n";
    analisis << fixed << setprecision(5) << "t x v EK\n";

    // Simulación para GIF
    double t = t0, x = x0, v = v0;
    while (t <= tf) {
        gifFile << t << " " << x << " " << v << "\n";

        x += v * dt;
        t += dt;

        if (x < 0.0) {
            x = -x;
            v = -e * v;
        } else if (x > L) {
            x = 2 * L - x;
            v = -e * v;
        }
    }
    gifFile.close();

    // Simulación extendida para análisis
    t = t0; x = x0; v = v0;
    int colisiones = 0;
    const double v_min = 1e-2;

    while (fabs(v) > v_min && t < 1e4) {
        double EK = 0.5 * v * v;
        analisis << t << " " << x << " " << v << " " << EK << "\n";

        x += v * dt;
        t += dt;

        if (x < 0.0) {
            x = -x;
            v = -e * v;
            colisiones++;
        } else if (x > L) {
            x = 2 * L - x;
            v = -e * v;
            colisiones++;
        }
    }
    analisis.close();

    cout << "\nColisiones: " << colisiones << endl;
    cout << "Datos guardados en results/\n";
}