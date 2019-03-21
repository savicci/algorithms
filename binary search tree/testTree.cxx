#include<iostream>
#include<string>
#include"binaryTree.h"
using std::cin;
using std::cout;
using std::endl;



int main(int argc, char const *argv[])
{
    std::string input;
    binaryTree tree;

    int n;
    cin>>input;
    n=std::stoi(input);
    
    //wczytywanie
    for(int i=0;i<n;i++){
        cin>>input;
        tree.insert(std::stoi(input));       
    }
    
    tree.printInorder();

    cout<<tree.size()<<" "<<tree.depth()<<" "<<tree.minimum()<<" "<<tree.maximum()<<endl;
    for(int i=1;i<10;i++){
        if(tree.search(i)==nullptr) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }

    return 0;
}
