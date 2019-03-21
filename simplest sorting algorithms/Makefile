.PHONY: all clean tar

all: bubble_sort.x insertion_sort.x counting_sort.x selection_sort.x std_sort.x genRandom.x

bubble_sort.x: bubble_sort.cxx
	g++ -std=c++11 -O2 -o bubble_sort.x bubble_sort.cxx

insertion_sort.x: insertion_sort.cxx
	g++ -std=c++11 -O2 -o insertion_sort.x insertion_sort.cxx

counting_sort.x: counting_sort.cxx
	g++ -std=c++11 -O2 -o counting_sort.x counting_sort.cxx

selection_sort.x: selection_sort.cxx
	g++ -std=c++11 -O2 -o selection_sort.x selection_sort.cxx

std_sort.x: std_sort.cxx
	g++ -std=c++11 -O2 -o std_sort.x std_sort.cxx

genRandom.x: genRandom.cxx
	g++ -std=c++11 -O2 -o genRandom.x genRandom.cxx

clean:
	rm -f *.x data.txt bubble.txt insertion.txt counting.txt selection.txt stdsort.txt sort.txt

tar:
	tar -zcvf ../GrzegorzKoziol_zestaw4.tar.gz ../zestaw4

sort_check: all
	./genRandom.x 100 500000 > data.txt
	./bubble_sort.x 1 < data.txt > bubble.txt
	./insertion_sort.x 1 <data.txt > insertion.txt
	./counting_sort.x 1 < data.txt > counting.txt
	./selection_sort.x 1 < data.txt > selection.txt
	./std_sort.x 1 < data.txt > stdsort.txt 
	sort -n < data.txt > sort.txt
	diff -s bubble.txt stdsort.txt
	diff -s insertion.txt stdsort.txt
	diff -s counting.txt stdsort.txt
	diff -s selection.txt stdsort.txt
	diff -s sort.txt stdsort.txt

measure_time: all
	@(./genRandom.x 10000 1000 > data.txt)
	@(./$(program) 2 < data.txt)
	@(./genRandom.x 20000 1000 > data.txt)
	@(./$(program) 2 < data.txt)
	@(./genRandom.x 40000 1000 > data.txt)
	@(./$(program) 2 < data.txt)
	@(./genRandom.x 80000 1000 > data.txt)
	@(./$(program) 2 < data.txt)
	@(./genRandom.x 160000 1000 > data.txt)
	@(./$(program) 2 < data.txt)
	@(./genRandom.x 300000 1000 > data.txt)
	@(./$(program) 2 < data.txt)
	
measure_all: all
	@(make measure_time program=bubble_sort.x)
	@(make measure_time program=insertion_sort.x)
	@(make measure_time program=counting_sort.x)
	@(make measure_time program=selection_sort.x)
	@(make measure_time program=std_sort.x)