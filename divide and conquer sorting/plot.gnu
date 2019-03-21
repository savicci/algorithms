#wykres czasu sortowan
set title 'Czas sortowania algorytrmow szybkich w zaleznosci od ilosci elementow'

set xlabel 'Liczba elementow'
set ylabel 'Czas sortowania[s]'

set xrange[10000:300000]

plot 'heap_time.txt' with lines title 'HeapSort' , 'quick_time.txt' with lines title 'QuickSort' , 'merge_time.txt' with lines title 'MergeSort'
