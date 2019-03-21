//by Grzzegorz Koziol
//sortowanie s biblioteki standardowej
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<chrono>
#include<iterator>
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
    std::sort(data.begin(),data.end());
    auto end=std::chrono::high_resolution_clock::now();

    if(option==1){
        //wypisywanie na stdout
        for(int k : data)
            cout<<k<<endl;
        }
    if(option==2){
        //wypisz czas dzialania
        cout<<"Czas dzialania algorytmu std::sort(...) dla "<<data.size()<<" elementow: "<<std::chrono::duration<double>(end-start).count()<<endl;
    }
    return 0;
}
