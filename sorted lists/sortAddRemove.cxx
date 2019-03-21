//by Grzegorz Koziol
#include<iostream>
#include<vector>//wektor
#include<chrono>//czas
#include"sortedArrayList.hxx"
#include"SortedLinkedList.hxx"
using std::cout;
using std::cin;
using std::endl;



main(int argc, char const *argv[])
{
    try{

    if(argc!=2){
        cout<<"Przykladowe wywolanie: <liczba operacji>"<<endl;
        exit(-1);
    }

    SortedArrayList arrList=SortedArrayList(std::stoi(argv[1]));
    SortedLinkedList linkList=SortedLinkedList();

    //generowanie tablicy roznych liczb
    auto begin = std::chrono::high_resolution_clock::now();
    std::vector<int> numbers;
    for(int i=0;i<std::stoi(argv[1]);i++)
        numbers.push_back(rand()%100);
    auto end = std::chrono::high_resolution_clock::now();
    cout<<"Czas wygenerowania liczb: "<<std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count()<<" ms"<<endl;


    //wykonanie operacji push dla ArrayList
    begin = std::chrono::high_resolution_clock::now();
    for(auto num : numbers)
        arrList.push(num);
    end = std::chrono::high_resolution_clock::now();
    cout<<"Czas operacji push() dla ArrayList: "<<std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count()<<" ms"<<endl;
    

    //wykonanie operacji push dla LinkedList
    begin = std::chrono::high_resolution_clock::now();
    for(auto num : numbers)
        linkList.push(num);
    end = std::chrono::high_resolution_clock::now();
    cout<<"Czas operacji push() dla LinkedList: "<<std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count()<<" ms"<<endl;


    //wykonanie operacji erase dla ArrayList
    begin = std::chrono::high_resolution_clock::now();
    for(auto num : numbers)
        arrList.erase(rand()%arrList.size()+1);
    end = std::chrono::high_resolution_clock::now();
    cout<<"Czas operacje erase() dla ArrayList: "<<std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count()<<" ms"<<endl;

    //wykonanie operacji erase dla LinkedList
    begin = std::chrono::high_resolution_clock::now();
    for(auto num : numbers)
        linkList.erase(rand()%linkList.size()+1);
    end = std::chrono::high_resolution_clock::now();   
    cout<<"Czas operacji erase() dla LinkedList: "<<std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count()<<" ms"<<endl;

    }catch(const char* msg){
        std::cerr<<msg<<endl;
        exit(-1);
    }

    return 0;
}
