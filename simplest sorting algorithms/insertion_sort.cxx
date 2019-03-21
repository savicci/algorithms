//by Grzegorz Koziol
//sortowanie przez wstawianie
#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<chrono>
using std::cin;
using std::cout;
using std::endl;


main(int argc, char const *argv[])
{
    if(argc!=2){
        cout<<"Opcje wywolania programu:\n1.Wypisz posortowana liste\n2.Wypisz czas dzialania\nWpisz 1 lub 2"<<endl;
        exit(-1);
    }
    int option=std::stoi(argv[1]);

    //wczytywanie
    std::string input;
    std::vector<int> data(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());

    auto start=std::chrono::high_resolution_clock::now();
    //algorytm
    for(int i=1;i<data.size();i++){
        int x=data[i];
        int j=i;
        for(;x<data[j-1];j--){
            data[j]=data[j-1];
        }
        data[j]=x;
    }
    auto end=std::chrono::high_resolution_clock::now();

    if(option==1){
        //wypisywanie na stdout
        for(int k : data)
            cout<<k<<endl;
        }
    if(option==2){
        //wypisz czas dzialania
        cout<<"Czas dzialania algorytmu insertion_sort dla "<<data.size()<<" elementow: "<<std::chrono::duration<double>(end-start).count()<<endl;
    }
    return 0;
}
