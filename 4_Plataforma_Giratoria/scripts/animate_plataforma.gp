data1='results/inercial.dat'
data2='results/noinercial.dat'
giffile='results/plataforma_anim.gif'

set terminal gif animate delay 30 size 1200,900
set output giffile
set title 'Plataforma Giratoria - Trayectorias 3D'
set grid
set xlabel 'X (m)'
set ylabel 'Y (m)'
set zlabel 'Z (m)'
set xrange [-15:15]
set yrange [-15:15]
set zrange [0:20]

N1 = int(system(sprintf("wc -l < %s", data1))) - 1
N2 = int(system(sprintf("wc -l < %s", data2))) - 1
N = (N1 > N2) ? N1 : N2
step = int(N/80) + 1

R = 5

do for [i=1:N:step] {
    # Vista desde arriba y ladeada para ver la parábola en Z
    set view 45, 30, 1, 1
    set parametric
    set urange [0:2*pi]
    splot R*cos(u), R*sin(u)-9, 0 with lines lc 'gray' lw 1 title 'Plataforma', \
          data1 every ::1::i using 2:(3-11.5):4 with lines lc 'blue' lw 3 title 'Inercial', \
          data2 every ::1::i using 2:(3-11.5):4 with lines lc 'red' lw 3 title 'No Inercial', \
          data1 every ::i::i using 2:(3-11.5):4 with points pt 7 ps 2 lc 'blue' title '', \
          data2 every ::i::i using 2:(3-11.5):4 with points pt 7 ps 2 lc 'red' title ''
}
unset output
