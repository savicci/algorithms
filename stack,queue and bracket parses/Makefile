.PHONY: all clean tar stack_checker queue_checker

all: stack.x stdstack.x genList.x queue.x genBrackets.x brackets.x

#program symulujacy stos
stack.x: stack.cxx stack.hxx
	g++ -std=c++11 -O2 -o stack.x stack.cxx

#program generujacy listy polecen
genList.x: genList.cxx
	g++ -std=c++11 -O2 -o genList.x genList.cxx

#program uzywajacy stosu z biblioteki standardowej
stdstack.x: stdstack.cxx
	g++ -std=c++11 -O2 -o stdstack.x stdstack.cxx

#program symulujacy kolejke
queue.x: queue.cxx queue.hxx
	g++ -std=c++11 -O2 -o queue.x queue.cxx

#program uzywajacy kolejki z biblioteki standardowej
stdqueue.x: stdqueue.cxx
	g++ -std=c++11 -O2 -o stdqueue.x stdqueue.cxx	

#program do generowania wyrazen nawiasowych
genBrackets.x: genBrackets.cxx
	g++ -std=c++11 -O2 -o genBrackets.x genBrackets.cxx

#program do sprawdzania wyrazen nawiasowych
brackets.x: brackets.cxx
	g++ -std=c++11 -O2 -o brackets.x brackets.cxx



#skrypt do sprawdzania poprawnosci dzialania programu stack.x
stack_checker: genList.x stdstack.x stack.x
	./genList.x 100 > stack.txt
	./stack.x 100 < stack.txt > outstack.txt
	./stdstack.x < stack.txt > outstdstack.txt
	diff -s outstack.txt outstdstack.txt 

#skrypt do sprawdzania poprawnosci dzialania programu stack.x
queue_checker: genList.x queue.x stdqueue.x
	./genList.x 100 > queue.txt
	./queue.x 100 < queue.txt > outqueue.txt
	./stdqueue.x < queue.txt > outstdqueue.txt
	diff -s outqueue.txt outstdqueue.txt

brackets_checker: genBrackets.x brackets.x
	./genBrackets.x 100 > brackets.txt
	./brackets.x < brackets.txt > bracket_result.txt

##################
clean:
	rm -f *.x stack.txt outstack.txt outstdstack.txt queue.txt outqueue.txt outstdqueue.txt brackets.txt bracket_result.txt

tar:
	tar zcvf ../GrzegorzKoziol_Zestaw1.tar.gz ../zestaw1