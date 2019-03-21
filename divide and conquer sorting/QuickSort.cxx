#include"Heap.hxx"
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<chrono>
using std::endl;
using std::cout;
using std::cin;
//quick sort rekurencyjnie


//funkcja pomocnicza
int podzial (int* a, int l, int h, double& ops) 
{ 
    //temp ustawiony na element jeden ponizej
    //pivot ustawiony na koniec tablicy
    int temp = (l - 1);   
    int pivot = a[h]; 

    for (int i = l; i <= h-1; i++) 
    {  
        ops++;
        if (a[i] <= pivot) 
        { 
            temp++; 
            std::swap(a[temp], a[i]); 
        } 
    } 
    ops++;
    std::swap(a[temp + 1], a[h]); 
    //po lewej znajduja sie elementy mniejsze badz rowne pivot
    //po prawej wieksze
    return (temp + 1); 
} 
  

void quickSort(int* a, int l, int h, double& ops) 
{ 
    if (l < h) 
    {   
        ops++;
        int p = podzial(a, l, h, ops); 
        //sortowanie lewej strony
        quickSort(a, l, p - 1, ops); 
        //sortowanie prawej strony
        quickSort(a, p + 1, h, ops); 
    } 
} 

int main(int argc, char const *argv[])
{
     if(argc!=2){
        cout<<"Opcje programu\n1.Pokaz czas sortowania\n2.Pokaz elementy posortowane"<<endl;
        exit(-1);
    }
    std::string input;
    std::vector<int> data;
    int option=std::stoi(argv[1]);

    while(cin>>input){
        data.push_back(std::stoi(input));
    }
    
    //zmiana wektora na tablice
    int* d=data.data();
    double ops=0;
   
    auto start=std::chrono::high_resolution_clock::now();
    quickSort(d,0,data.size()-1,ops);
    auto end=std::chrono::high_resolution_clock::now();
    
    if(option==1){
        cout<<"QuickSort Czas sortowania "<<data.size()<<" elementow: "<<std::chrono::duration<double>(end-start).count()<<endl;  
        cout<<"Liczba operacji "<<ops<<endl;
    }

    if(option==2){
    for(int k : data){
        std::cout<<k<<endl;
    }
    }

    return 0;
}
