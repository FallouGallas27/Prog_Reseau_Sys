set title "Courbes issues des résultats des threads"
set xlabel "Indice"
set ylabel "Valeur"
set grid
set style data linespoints

plot "pthread.txt" using 1 title "Thread 1 (10 à 0)" with linespoints lw 2, \
     "pthread.txt" using 2 title "Thread 2 (0 à 10)" with linespoints lw 2
