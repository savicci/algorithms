1. Liczba porownan wykonanych przez algorytmy
algorytm                optymistyczny                   pesymistyczny
bubble_sort             n+n-1+n-2+...=(n*n-n)/2         (n*n-n)/2
selection_sort          (n*n-n)/2                       (n*n-2)/2 (jednak wykonuje mniej zamian)
insertion_sort          n(posortowana)                  (n*n-n)/2

n-liczba elementow  k-histogram liczb
counting_sort           1.znalezienie min i max: n
                        2.przejscie tablicy danych: n   dla pesymistycznego identycznie
                        3.przejscie przez histogram: k
                        lacznie 2*n+k

2.srednia liczba porownan w przypadku losowym
bubble_sort- zawsze (n*n-n)/2
selection_sort - zawsze (n*n-n)/2
insertion_sort -  srednio (n*n-n)/2
counting_sort- zawsze 2n+k

3.zlozonosc algorytmów
bubble_sort- O(n*n)
insertion_sort- O(n*n)
selection_sort- O(n*n)
counting_sort-O(n+k)