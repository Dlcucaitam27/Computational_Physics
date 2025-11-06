set terminal gif animate delay 5 size 800,600
set output 'results/triangulo_anim.gif'
set xrange [0:10]
set yrange [0:8.66025]
set size ratio -1
set grid
set title 'Partícula confinada en un triángulo'

nframes = 401
lines_per_frame = 5
total_lines = 2001

do for [i=1:nframes] {
    frame_end = (i * lines_per_frame > total_lines) ? total_lines : i * lines_per_frame
    plot 'results/trayectoria.dat' every ::1::frame_end using 2:3 with lines lc rgb 'blue' title 'Trayectoria',\
         'results/trayectoria.dat' every ::frame_end::frame_end using 2:3 with points pt 7 ps 2 lc rgb 'red' notitle,\
         'scripts/triangulo.dat' with lines lw 2 lc rgb 'black' notitle
}

unset output
