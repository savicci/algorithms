//by Grzegorz Koziol
#include<iostream>
using std::cout;
using std::cin;
using std::endl;


main(int argc, char const *argv[])
{
    if(argc!=3){
        cout<<"Podaj dwie liczby bedace wielkosciami zestawu danych"<<endl;
        exit(-1);
    }

    srand(time(NULL));
    
    int num1=std::stoi(argv[1]);
    int num2=std::stoi(argv[2]);

    cout<<num1<<endl;
    for(int i=0;i<num1;i++)
        cout<<rand()%15<<" ";
    cout<<endl;
    cout<<num2<<endl;
    for(int i=0;i<num2;i++)
        cout<<rand()%15<<" ";
    cout<<endl;

    return 0;
}
