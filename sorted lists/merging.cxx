//by Grzegorz Koziol
#include<iostream>
#include<string>
#include<list>
#include"sortedArrayList.hxx"
#include"SortedLinkedList.hxx"
using std::cout;
using std::cin;
using std::endl;



main(int argc, char const *argv[])
{
    if(argc!=3){
        cout<<"Podaj wielkosci list tablicowych"<<endl;
        exit(-1);
    }

    int num1=std::stoi(argv[1]);
    int num2=std::stoi(argv[2]);

    SortedArrayList arrList1=SortedArrayList(num1);
    SortedArrayList arrList2=SortedArrayList(num2);
    SortedLinkedList linkList1=SortedLinkedList();
    SortedLinkedList linkList2=SortedLinkedList();
    std::list<int> stdList1;
    std::list<int> stdList2;


    std::string input;
    //najpierw arraylist
    cin>>input;
    int ops=std::stoi(input);
    int num;
    for(int i=0;i<ops;i++){
        cin>>input;
        num=std::stoi(input);

        arrList1.push(num);
        linkList1.push(num);
        stdList1.push_back(num);
    }
    //przesortuj liste standardowa
    stdList1.sort();

    cin>>input;
    ops=std::stoi(input);
    for(int i=0;i<ops;i++){
        cin>>input;
        num=std::stoi(input);

        arrList2.push(num);
        linkList2.push(num);
        stdList2.push_back(num);
    }
    //przesortuj liste standardowa
    stdList2.sort();

    //merge
    SortedArrayList newArrList=SortedArrayList::merge(arrList1,arrList2);
    SortedLinkedList newLinkList=SortedLinkedList::merge(linkList1,linkList2);
    stdList1.merge(stdList2);

    //wypisywanie   
    newArrList.print();
    newLinkList.print();

    for(auto i : stdList1)
        cout<<i<<" ";
        cout<<endl;

    newArrList.unique();
    newLinkList.unique();
    stdList1.unique();

    //wypisywanie po unique() 
    cout<<"Po operacji unique()"<<endl;
    newArrList.print();
    newLinkList.print();

    for(auto i : stdList1)
        cout<<i<<" ";
        cout<<endl;   
    
    return 0;
}
