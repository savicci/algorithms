#include<iostream>
#include<string>
#include"../resources/ArrayList.cxx"
using std::cout;
using std::endl;
using std::cin;


//szuka przywodcy ciagu 
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

    //szukanie przywodcy
    int count=0;
    int j;
    for(int i=0; i<size; i++){
        if(count==0){
            count++;
            j=i;
        }
        else if(data.buf[i]==data.buf[j]) count++;
        else count--;
    }
    
    cout<<"Przywodca wczytanego ciagu to "<<data.buf[j]<<endl;
    
    return 0;
}
