#pragma once
#include <string>
using namespace std;

void solicitarDatos(double &w, double &d, double &v0, double &theta, 
                    double &phi, double &t0, double &tf, double &dt, int &sistema);
void simularInercial(double w, double d, double v0, double theta, double phi,
                     double t0, double tf, double dt, const string &archivo);
void simularNoInercial(double w, double d, double v0, double theta, double phi,
                       double t0, double tf, double dt, const string &archivo);
void graficarComparativo(const string &archivo1, const string &archivo2, 
                        const string &imagen);
void generarAnimacionPlataforma(const string &archivo1, const string &archivo2,
                               double w, double d, const string &gifSalida);