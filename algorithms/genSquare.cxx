#include<iostream>
#include<random>
using std::cout;
using std::cin;
using std::endl;


//generuje nums punktow na standardowe wyjscie
int main(int argc, char const *argv[])
{   
    if(argc!=2){
        cout<<"Podaj ilosc punktow do wylosowania"<<endl;
        exit(-1);
    }

    int nums=std::stoi(argv[1]);

     //generator
    std::uniform_real_distribution<double> fun(0,1);
    std::default_random_engine eng(time(NULL));

    for(int i=0;i<nums;i++){
        cout<<fun(eng)<<endl;
        cout<<fun(eng)<<endl;
    }


    return 0;
}
