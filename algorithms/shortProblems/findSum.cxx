#include<iostream>
#include<string>
#include"../resources/sortedArrayList.hxx"
using std::cout;
using std::endl;
using std::cin;

//szuka sumy dwoch wartosci z dwoch posortowanych tablic
//takiej ze a+b=x
int main(int argc, char const *argv[])
{
    if(argc!=4){
        cout<<"Podaj ilosc liczb do pierwszej i drugiej tablicy oraz liczbe jakie x chcesz znalezc takie ze x=A[i]+B[j]"<<endl;
        exit(-1);
    }
    int size1=std::stoi(argv[1]);
    int size2=std::stoi(argv[2]);

    int toFind=std::stoi(argv[3]);

    std::string input;

    SortedArrayList A(size1);
    SortedArrayList B(size2);

    for(int i=0; i<size1; i++){
        cin>>input;
        A.push(std::stoi(input));
        
    }

    for(int i=0; i<size2; i++){
        cin>>input;
        B.push(std::stoi(input));
    }

    //drukowanie dla sprawdzenia
    for(int i=0;i<A.size();i++)
        cout<<A.getElem(i)<<" ";
    cout<<endl;

    for(int i=0;i<B.size();i++)
        cout<<B.getElem(i)<<" ";
    cout<<endl;



    //szukanie sumy posortowanych
    int i=0,j=B.size()-1,sum;
    while(i<A.size() && j>=0){
        sum=A.getElem(i)+B.getElem(j);

        if(sum==toFind){
            cout<<"Znaleziono sume "<<toFind<<" jako A["<<i<<"] = "<<A.getElem(i)<<" i B["<<j<<"] = "<<B.getElem(j)<<endl;
            return 0;
        }

        if(sum<toFind) i++;
        else j--;
    }
    cout<<"Nie udalo sie znalezc takiej pary liczb ktora sumuje sie do "<<toFind<<endl;

    return 0;
}


