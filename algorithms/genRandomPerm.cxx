#include<iostream>
#include"resources/ArrayList.cxx"
using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{
    if(argc!=2){
        cout<<"Podaj ilosc liczb do permutacji"<<endl;
        exit(-1);
    }

    int size=std::stoi(argv[1]);
    ArrayList<int> data(size);

    for(int i=0; i< size; i++)
        data.push_back(i+1);

    //permutowanie Knutha zbioru 
    int j;
    for(int i=data.size()-1; i>=0; i--){
        j=rand()%size;
        data.swap(i,j);
    }

    data.print();
    
    return 0;
}
