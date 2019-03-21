#include"Heap.hxx"
#include<iostream>
#include<vector>
#include<string>
#include<chrono>
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char const *argv[])
{
 if(argc!=2){
        cout<<"Opcje programu\n1.Pokaz czas sortowania\n2.Pokaz elementy posortowane"<<endl;
        exit(-1);
    }

    try{
    std::string input;
    std::vector<int> data;
    int option=std::stoi(argv[1]);
    double ops=0;

    while(cin>>input){
        data.push_back(std::stoi(input));
    }
    Heap h(1);
    //zmiana wektora na tablice
    int* d=data.data();

    
    auto start=std::chrono::high_resolution_clock::now();
    h.sortIter(d,data.size(),ops);
    //h.sortRec(d,data.size());
    auto end=std::chrono::high_resolution_clock::now();

    if(option==1){
        cout<<"HeapSort Czas sortowania iteracyjnie "<<data.size()<<" elementow: "<<std::chrono::duration<double>(end-start).count()<<endl;
        cout<<"Liczba operacji "<<ops<<endl;
    }

    if(option==2){
    for(int i=0;i<h.size();i++)
        cout<<h.getElem(i)<<endl;
    }

    }catch(const char* msg){
        std::cerr<<msg<<endl;
        exit(-1);
    }

    return 0;
}
