.PHONY:all clean tar shortProblems checkFirst checkPermutations

all: findTwoClosest.x genSquare.x genRandomPerm.x findPermutations.x biggestSquare.x shortProblems



#zadanie1
findTwoClosest.x: findTwoClosest.cxx resources/Heap.cxx resources/ArrayList.cxx
	g++ -O2 -std=c++11 -o findTwoClosest.x  findTwoClosest.cxx

genSquare.x: genSquare.cxx
	g++ -O2 -std=c++11 -o genSquare.x genSquare.cxx

#skrypt do sprawdzania pierwszego zadania
checkFirst: findTwoClosest.x genSquare.x
	./genSquare.x $(amount) > points.txt
	./findTwoClosest.x $(amount) < points.txt

#zadanie2
genRandomPerm.x: genRandomPerm.cxx
	g++ -O2 -std=c++11 -o genRandomPerm.x genRandomPerm.cxx

findPermutations.x: findPermutations.cxx
	g++ -O2 -std=c++11 -o findPermutations.x findPermutations.cxx

#skrypt do sprawdzania drugiego zadania
checkPermutations: findPermutations.x genRandomPerm.x
	./genRandomPerm.x $(amount) > perms.txt
	./findPermutations.x $(amount) < perms.txt

#zadanie3
biggestSquare.x: biggestSquare.cxx
	g++ -O2 -std=c++11 -o biggestSquare.x biggestSquare.cxx resources/Stack.cxx


#zadanie 4 - krotkie algorytmy w folderze shortProblems
shortProblems: findLeader.x findSum.x maxSegment.x sections.x

findLeader.x: shortProblems/findLeader.cxx
	g++ -O2 -std=c++11 -o shortProblems/findLeader.x shortProblems/findLeader.cxx

findSum.x: shortProblems/findSum.cxx 
	g++ -O2 -std=c++11 -o shortProblems/findSum.x shortProblems/findSum.cxx resources/sortedArrayList.cxx

maxSegment.x: shortProblems/maxSegment.cxx 
	g++ -O2 -std=c++11 -o shortProblems/maxSegment.x shortProblems/maxSegment.cxx 

sections.x: shortProblems/sections.cxx
	g++ -O2 -std=c++11 -o shortProblems/sections.x shortProblems/sections.cxx


clean:
	rm -f *.x
	rm shortProblems/*.x

tar:
	tar -zcvf ../GrzegorzKoziol_zestaw6.tar.gz ../zestaw6