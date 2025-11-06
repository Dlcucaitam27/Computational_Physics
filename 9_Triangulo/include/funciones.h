#pragma once
#include <string>
using namespace std;

void solicitarDatos(double &L, double &x0, double &y0, double &vx0, double &vy0, 
                    double &t0, double &tf, double &dt);
bool validarTriangulo(double L, double x0, double y0);
void simularMovimiento(double L, double x0, double y0, double vx0, double vy0,
                       double t0, double tf, double dt, const string &archivo);
void graficarTrayectoria(double L, const string &archivo, const string &imagen);
void generarAnimacion(double L, const string &archivo, const string &gifSalida);