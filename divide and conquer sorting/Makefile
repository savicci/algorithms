.PHONY: all clean tar

all: HeapCheck.x QuickSort.x MergeSort.x genSet.x genSorted.x genReverse.x genSortedFirst.x genSortedLast.x 

sort: qSort.x stdSort.x genSorted.x genReverse.x genSortedFirst.x genSortedLast.x

HeapCheck.x: HeapCheck.cxx Heap.cxx Heap.hxx
	g++ -O2 -std=c++11 -o HeapCheck.x HeapCheck.cxx Heap.cxx

QuickSort.x: QuickSort.cxx
	g++ -O2 -std=c++11 -o QuickSort.x QuickSort.cxx

MergeSort.x: MergeSort.cxx
	g++ -O2 -std=c++11 -o MergeSort.x MergeSort.cxx

genSet.x: genSet.cxx
	g++ -O2 -std=c++11 -o genSet.x genSet.cxx

genSorted.x: genSorted.cxx
	g++ -O2 -std=c++11 -o genSorted.x genSorted.cxx

genReverse.x: genReverse.cxx
	g++ -O2 -std=c++11 -o genReverse.x genReverse.cxx

genSortedFirst.x: genSortedFirst.cxx
	g++ -O2 -std=c++11 -o genSortedFirst.x genSortedFirst.cxx

genSortedLast.x: genSortedLast.cxx
	g++ -O2 -std=c++11 -o genSortedLast.x genSortedLast.cxx

qSort.x: qSort.c
	time gcc -O3 -march=native -o qSort.x qSort.c

stdSort.x: stdSort.cxx
	time g++ -O3 -march=native -o stdSort.x stdSort.cxx


clean:
	rm -f *.x data.txt quick.txt heap.txt merge.txt sort.txt

tar:
	tar -zcvf ../GrzegorzKoziol_zestaw5.tar.gz ../zestaw5


checkSort: all
	./genSet.x $(amount) > data.txt
	./HeapCheck.x 2 < data.txt > heap.txt
	./QuickSort.x 2 < data.txt > quick.txt
	./MergeSort.x 2 < data.txt > merge.txt
	sort -n < data.txt > sort.txt
	diff -s sort.txt heap.txt
	diff -s sort.txt quick.txt
	diff -s sort.txt merge.txt


measure_time: all
	@(./$(generator) 10000 > data.txt)
	@(./$(program) 1 < data.txt)
	@(./$(generator) 20000 > data.txt)
	@(./$(program) 1 < data.txt)
	@(./$(generator) 40000 > data.txt)
	@(./$(program) 1 < data.txt)
	@(./$(generator) 80000 > data.txt)
	@(./$(program) 1 < data.txt)
	@(./$(generator) 160000 > data.txt)
	@(./$(program) 1 < data.txt)

measure_all: all
	@(make measure_time program=HeapCheck.x)
	@(make measure_time program=QuickSort.x)
	@(make measure_time program=MergeSort.x)


checkTime: sort
	@(./$(generator) $(amount) > data.txt)
	time ./qSort.x $(amount) < data.txt
	time ./stdSort.x $(amount) < data.txt