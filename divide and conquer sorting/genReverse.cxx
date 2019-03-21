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
    int temp=nums*10;
    for(int i=0;i<nums;i++){
        temp-=rand()%10;
        cout<<temp<<endl;
    }

    return 0;
}
