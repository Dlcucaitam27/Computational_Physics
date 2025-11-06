set terminal pngcairo size 1200,800
set output 'results/triangulo_grafico.png'
set multiplot layout 2,2 title 'Partícula en Triángulo Equilátero'
set grid
set title 'Trayectoria y puntos de rebote'
set xlabel 'x (m)'
set ylabel 'y (m)'
set size ratio -1
plot 'results/trayectoria.dat' using 2:3 with lines lw 2 lc 'blue' title 'Trayectoria',\
     'results/rebotes.dat' using 3:4 with points pt 7 ps 1.5 lc 'red' title 'Puntos de rebote',\
     '-' with lines lw 3 lc 'black' title 'Triángulo'
0 0
10 0
5 8.66025
0 0
e
set title 'Evolución temporal de x(t)'
set xlabel 't (s)'
set ylabel 'x (m)'
plot 'results/trayectoria.dat' using 1:2 with lines lw 2 lc 'red' title 'x(t)'
set title 'Evolución temporal de y(t)'
set xlabel 't (s)'
set ylabel 'y (m)'
plot 'results/trayectoria.dat' using 1:3 with lines lw 2 lc 'green' title 'y(t)'
set title 'Energía y dinámica'
set xlabel 't (s)'
set ylabel 'Valor'
plot 'results/trayectoria.dat' using 1:2 with lines lw 1 lc 'orange' title 'x(t)',\
     'results/trayectoria.dat' using 1:3 with lines lw 1 lc 'purple' title 'y(t)'
unset multiplot
