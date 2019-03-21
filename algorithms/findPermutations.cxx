#include<iostream>
#include<chrono>
#include<string>
#include"resources/ArrayList.cxx"
#include"resources/MergeSortPerm.cxx"
using std::cout;
using std::endl;
using std::cin;


class KnuthShuffle{
    public:
    KnuthShuffle(int i)
    :sz(i){
        data=new ArrayList<int>(i);
    }


    void fill(){
        std::string input;
        while(cin>>input){
            data->push_back(std::stoi(input));
        }
    }

    //metoda bruteForce O(n*n)
    long double bruteForce(){
        long double inversions=0;

        for(int i=0; i<sz; i++)
            for(int j=i+1; j<sz; j++)
                if(data->buf[i] > data->buf[j]) inversions++;

        return inversions;
    }

    long double algorithm(){
        return mergeSort(data->buf,data->size());
    }


    private:
    ArrayList<int> *data;
    int sz;

};
  

//losuje permutacje zbioru rosnacego od 1 do n 
//i znajduje liczbe inwersji uzywajac metod bruteforce i algorytmu nlogn
int main(int argc, char const *argv[])
{
    //ustawienie losowosci
    srand(time(NULL));

    if(argc!=2){
        cout<<"Podaj ilosc liczb"<<endl;
        exit(-1);
    }

    KnuthShuffle ks(std::stoi(argv[1]));
    ks.fill();
    auto start=std::chrono::high_resolution_clock::now();
    long double bruteInvs=ks.bruteForce();
    auto end=std::chrono::high_resolution_clock::now();
    double bruteTime=std::chrono::duration<double>(end-start).count();


    start=std::chrono::high_resolution_clock::now();
    long double algoInvs=ks.algorithm();
    end=std::chrono::high_resolution_clock::now();
    double algoTime=std::chrono::duration<double>(end-start).count();
    

    cout<<"BruteForce. Czas zliczania inwersji: "<<bruteTime<<", liczba inwersji: "<<bruteInvs<<endl;
    cout<<"Algorytm. Czas zliczania inwersji: "<<algoTime<<", liczba inwersji: "<<algoInvs<<endl;


    return 0;
}
