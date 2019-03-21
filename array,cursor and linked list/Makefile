.PHONY: all clear tar 

all: ArrayList.x genList.x CursorList.x LinkedList.x stdList.x

ArrayList.x: ArrayList.cxx ArrayList.hxx
	g++ -std=c++11 -O2 -o ArrayList.x ArrayList.cxx

genList.x: genList.cxx
	g++ -std=c++11 -O2 -o genList.x genList.cxx

CursorList.x: CursorList.cxx CursorList.hxx
	g++ -std=c++11 -O2 -o CursorList.x CursorList.cxx
	
LinkedList.x: LinkedList.cxx LinkedList.hxx
	g++ -std=c++11 -O2 -o LinkedList.x LinkedList.cxx

stdList.x: stdList.cxx
	g++ -std=c++11 -O2 -o stdList.x stdList.cxx	


####utility
clean:
	rm -f *.x genList.txt ArrayList.txt CursorList.txt LinkedList.txt stdList.txt

tar:
	tar zcvf ../GrzegorzKoziol_Zestaw2.tar.gz ../zestaw2

ArrayList_checker: ArrayList.x genList.x
	./genList.x 100 > genList.txt
	./ArrayList.x 30 < genList.txt > ArrayList.txt

CursorList_checker: CursorList.x genList.x ArrayList.x
	./genList.x 100 > genList.txt
	./ArrayList.x 30 < genList.txt > ArrayList.txt
	./CursorList.x 30 < genList.txt > CursorList.txt
	diff -s CursorList.txt ArrayList.txt

LinkedList_checker: LinkedList.x genList.x ArrayList.x
	./genList.x 100 > genList.txt
	./ArrayList.x 30 < genList.txt > ArrayList.txt
	./LinkedList.x 30 < genList.txt > LinkedList.txt
	diff -s LinkedList.txt ArrayList.txt

All_checker: genList.x ArrayList.x CursorList.x LinkedList.x stdList.x
	./genList.x 100 > genList.txt
	./ArrayList.x 30 < genList.txt > ArrayList.txt
	./CursorList.x 30 < genList.txt > CursorList.txt
	./LinkedList.x 30 < genList.txt > LinkedList.txt
	./stdList.x 30 < genList.txt > stdList.txt
	diff -s CursorList.txt stdList.txt
	diff -s LinkedList.txt stdList.txt
	diff -s ArrayList.txt stdList.txt