#Program rysujacy wykres czasu sortowania w zaleznosci od ilosci elementow
set xlabel "Liczba elementow"
set ylabel "Czas sortowania[ms]"
set title "Wykres czasu sortowania w zaleznosci od ilosci elementow"

set style data lines

plot 'selection_time.txt' title "Selection sort" , 'bubble_time.txt' title "Bubble sort", 'insertion_time.txt' title "Insertion sort",\
'counting_time.txt' title "Counting sort", 'std_time.txt' title "Std::sort" 