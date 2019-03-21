.PHONY: all clean tar merge_checker

all: sortAddRemove.x genSet.x merging.x

#pliki obiektowe
sortedArrayList.o: sortedArrayList.cxx sortedArrayList.hxx
	g++ -c sortedArrayList.cxx

SortedLinkedList.o: SortedLinkedList.cxx SortedLinkedList.hxx
	g++ -c SortedLinkedList.cxx

sortAddRemove.o: sortAddRemove.cxx
	g++ -c sortAddRemove.cxx

merging.o: merging.cxx
	g++ -c merging.cxx

#linkowanie
sortAddRemove.x: sortAddRemove.o SortedLinkedList.o sortedArrayList.o
	g++ -std=c++11 -O2 -o sortAddRemove.x sortAddRemove.o SortedLinkedList.o sortedArrayList.o

genSet.x: genSet.cxx
	g++ -std=c++11 -O2 -o genSet.x genSet.cxx

merging.x: merging.o SortedLinkedList.o sortedArrayList.o
	g++ -std=c++11 -O2 -o merging.x merging.o SortedLinkedList.o sortedArrayList.o

##############
clean:
	rm -f *.x *.o  genSet.txt

tar:
	tar -zcvf ../GrzegorzKoziol_zestaw3.tar.gz ../zestaw3


merge: genSet.x merging.x
	./genSet.x 15 20 > genSet.txt
	./merging.x 15 20 < genSet.txt