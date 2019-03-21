#include<iostream>
#include<string>
#include"binaryTree.h"
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char const *argv[])
{
    binaryTree tree;
    std::string input;

    while(cin>>input)
        tree.insert(std::stoi(input));

    tree.printIterative();

    return 0;
}
