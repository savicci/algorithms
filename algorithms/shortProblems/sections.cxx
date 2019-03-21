#include<iostream>
#include<string>
#include"../resources/ArrayList.cxx"
using std::cout;
using std::endl;
using std::cin;


int max(int i, int j){
    return i > j ? i : j;
}

//znajduje maksymalna sume dlugosci odcinkow
int main(int argc, char const *argv[])
{
    if(argc!=2){
        cout<<"Podaj ilosc liczb"<<endl;
        exit(-1);
    }

    int size=std::stoi(argv[1]);
    ArrayList<int> data(size);
    std::string input;

    for(int i=0; i<size; i++){
        cin>>input;
        data.push_back(std::stoi(input));
    }

    int withLast=0;
    int withoutLast=0;
    int tempWithLast,tempWithoutLast;
    for(int i=1; i<size; i++){
        tempWithoutLast=max(withLast, withoutLast);
        tempWithLast=withoutLast+data.buf[i]-data.buf[i-1];

        withoutLast=tempWithoutLast;
        withLast=tempWithLast;
    }
    int maxOdcinek=max(withLast,withoutLast);

    cout<<"Maksymalna suma dlugosci rozlacznych odcinkow wynosi "<<maxOdcinek<<endl;

    return 0;
}
