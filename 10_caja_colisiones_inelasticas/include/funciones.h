#pragma once
#include <string>
using namespace std;

void solicitarDatos(double &L, double &x0, double &v0, double &t0, double &tf, double &dt, double &e);
void simularMovimiento(double L, double x0, double v0, double t0, double tf, double dt, double e);
void generarGraficas();
void generarAnimacion();