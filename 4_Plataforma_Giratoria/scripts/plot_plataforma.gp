set terminal pngcairo size 1200,800
set output 'results/comparativo.png'
set multiplot layout 2,2 title 'Disparo desde Plataforma Giratoria'
set grid
set title 'Trayectoria 3D'
splot 'results/inercial.dat' using 2:3:4 with lines lw 2 title 'Inercial',\
      'results/noinercial.dat' using 2:3:4 with lines lw 2 title 'No Inercial'
set title 'Posicion X(t)'
plot 'results/inercial.dat' using 1:2 with lines lw 2 title 'Inercial',\
     'results/noinercial.dat' using 1:2 with lines lw 2 title 'No Inercial'
set title 'Posicion Y(t)'
plot 'results/inercial.dat' using 1:3 with lines lw 2 title 'Inercial',\
     'results/noinercial.dat' using 1:3 with lines lw 2 title 'No Inercial'
set title 'Posicion Z(t)'
plot 'results/inercial.dat' using 1:4 with lines lw 2 title 'Inercial',\
     'results/noinercial.dat' using 1:4 with lines lw 2 title 'No Inercial'
unset multiplot
