#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    
    if(argc!=2){
        cout<<"Podaj ilosc liczb do wygenerowania"<<endl;
        exit(-1);
    }

    int nums=std::stoi(argv[1]);

    for(int i=0;i<nums;i++)
        cout<<rand()%100000+1<<endl;
    return 0;
}
