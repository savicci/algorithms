.PHONY: all clean tar treeChecker checkSamples

all: testTree.x treeIterative.x

testTree.x: testTree.cxx binaryTree.h
	g++ -O2 -std=c++11 -o testTree.x testTree.cxx

treeChecker: testTree.x
	./testTree.x < treeChecker/input$(input).txt > treeChecker/mineoutput$(input).txt
	diff -s treeChecker/output$(input).txt treeChecker/mineoutput$(input).txt

checkSamples: testTree.x
	make treeChecker input=10k
	make treeChecker input=15a
	make treeChecker input=15b
	make treeChecker input=100
	@(echo UDALO SIE :O)

treeIterative.x: treeIterative.cxx
	g++ -O2 -std=c++11 -o treeIterative.x treeIterative.cxx


clean:
	rm -f *.x

tar:
	tar -zcvf ../GrzegorzKoziol_zestaw7.tar.gz ../zestaw7