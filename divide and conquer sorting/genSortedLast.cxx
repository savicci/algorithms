#include<iostream>
#include<string>
using std::cin;
using std::endl;
using std::cout;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    
    if(argc!=2){
        cout<<"Podaj liczbe argumentow"<<endl;
        exit(-1);
    }

    int nums=std::stoi(argv[1]);
    int temp=0;
    for(int i=0;i<nums-1;i++){
        temp+=rand()%5;
        cout<<temp<<endl;
    }
    cout<<rand()%1000000<<endl;

    return 0;
}
