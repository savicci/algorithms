#include<iostream>
#include<string>
#include<vector>
#include<chrono>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;

//robi merge "dwoch podtablic" [l,m] i [m+1,h]
//i wpisuje do a[]
void merge(int *a, int l, int m, int h, double& ops){
    //tablice do kopii
    int lSize=m-l+1;
    int rSize=h-m;
    int left[lSize];
    int right[rSize];

    //kopiowanie elementow do tablic tymczasowych
    for(int i=0;i<lSize;i++){
        left[i]=a[l+i];
        ops++;
    }

    for(int i=0;i<rSize;i++){
        right[i]=a[m+1+i];
        ops++;
    }

    //merge dwoch tablic
    int i=0,j=0; //indeksy tablic left i right
    int k=l;     //indeks tablicy a
    while(i< lSize && j < rSize){
        ops++;
        if(left[i] > right[j]){
            a[k]=right[j];
            j++;
            k++;
        }
        else{
            a[k]=left[i];
            i++;
            k++;
        }
    }

    //kopiowanie pozostalych elementow
    while(i<lSize){
        a[k]=left[i];
        i++;
        k++;
        ops++;
    }

    while(i<rSize){
        a[k]=right[j];
        j++;
        k++;
        ops++;
    }
}

//wykonuje sortowanie
void mergeSort(int* a, int l, int h, double& ops){
    //tworzy podtablice o rozmiarze 1,2,4,...,h-l
    for(int arrSize=1;arrSize<=h;arrSize*=2){
        for(int leftI=0; leftI<h; leftI+=2*arrSize){
            //znajdujemy punkt tablicy dzielacy dwie podtablice
            int mid=leftI+arrSize-1;
            ops++;

            //znajdujemy indeks prawej tablicy
            int rightI=std::min(leftI+2*arrSize-1,h);
            merge(a,leftI,mid,rightI,ops);
        }
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
    mergeSort(d,0,data.size()-1,ops);
    auto end=std::chrono::high_resolution_clock::now();
    if(option==1){
        cout<<"MergeSort Czas sortowania "<<data.size()<<" elementow: "<<std::chrono::duration<double>(end-start).count()<<endl;  
        cout<<"Liczba operacji "<<ops<<endl;
    }

    if(option==2){
        for(int k : data){
            std::cout<<k<<endl;
        }
    }
    return 0;
}
