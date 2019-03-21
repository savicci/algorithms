//by Grzegorz Koziol
//sortowanie przez zliczanie
#include<iostream>
#include<vector>
#include<iterator>
#include<chrono>
#include<string>
#include<algorithm>
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
    int base=*std::min_element(data.begin(),data.end());
    std::vector<int> hist(*std::max_element(data.begin(),data.end())-base+1);
    for(int i : data){
        hist[i-base]+=1;
    }
    auto end=std::chrono::high_resolution_clock::now();

    if(option==1){
        //wypisywanie na stdout
        for(int i=0;i<hist.size();i++){
            while(hist[i]>0){
                cout<<i+base<<endl;
                hist[i]-=1;
            }
        }
    }
    if(option==2){
        //wypisz czas dzialania
        cout<<"Czas dzialania algorytmu counting_sort dla "<<data.size()<<" elementow: "<<std::chrono::duration<double>(end-start).count()<<endl;
    }

    return 0;
}
