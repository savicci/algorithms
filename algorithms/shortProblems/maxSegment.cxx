#include<iostream>
#include<string>
#include"../resources/ArrayList.cxx"
using std::cout;
using std::endl;
using std::cin;

int max(int i, int j){
    return i > j ? i : j ;
}


//szuka segmentu liczb o najwiekszej sumie
int main(int argc, char const *argv[])
{
    if(argc!=2){
        cout<<"Podaj ilosc liczb"<<endl;
        exit(-1);
    }

    std::string input;
    int size=std::stoi(argv[1]);
    ArrayList<int> data(size);

    for(int i=0; i<size; i++){
        cin>>input;
        data.push_back(std::stoi(input));
    }

    //szukanie segmentu
    int sum=0,prev_sum=0;
    for(int i=0; i < data.size(); i++){
        prev_sum=max(data.buf[i]+ prev_sum, 0);
        sum=max(sum,prev_sum);
    }

    cout<<"Najwieksza suma wynosi "<<sum<<endl;
    
    return 0;
}
