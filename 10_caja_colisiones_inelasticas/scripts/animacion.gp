set terminal gif animate delay 8 size 800,600
set output 'results/caja1D_anim.gif'
set title 'Movimiento en Caja 1D - Colisiones Inelásticas'
set xlabel 'Tiempo (s)'
set ylabel 'Posición (m)'
set grid

stats 'results/datos_gif.dat' using 1 nooutput
N = STATS_records
step = int(N/50) + 1

do for [i=1:N:step] {
    plot 'results/datos_gif.dat' every ::1::i using 1:2 with lines lw 2 lc 'blue' title 'Trayectoria'
}
unset output
