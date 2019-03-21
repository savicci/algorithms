//by Grzegorz Koziol
//program symulujacy dzialanie stosu oparty o tablice o ustalonym rozmiarze
#include<iostream>
#include<string>
#include"stack.hxx"
using std::cout;
using std::endl;
using std::cin;

//konstruktory
Stack::Stack(int x)
    :i(0),s(x)
    {
        if(x<1) throw "Zly rozmiar tablicy";
        buf=new int[x];
    }

Stack::~Stack() { delete[] buf; }

// Wstawia element x na stos
void Stack::push(int x){
    if(i==s) throw "Nie ma miejsca na stosie";
    buf[i]=x;
    i++;
}

// Usuwa element ze stosu i zwraca jego wartość
int Stack::pop(){
    if(empty()){
        return -1;
    }
    i--;
    int temp=buf[i];
    buf[i]=0;
    return temp;
} 

// Zwraca referencję do najmłodszego elementu
int& Stack::top(){
    //int* top=&buf[i-1];
    return buf[i-1];
}

// Zwraca liczbę elementów na stosie
int Stack::size(){ return i;}

// Sprawdza czy stos jest pusty
bool Stack::empty(){
    if(i==0) return true;
    else return false;
}

int main(int argc, char*argv[])
{
    if(argc<2){
        cout<<"Prawidlowe wywolanie programu:(nazwa programu) (wielkosc tablicy) < (plik z poleceniami) \n";
        return -1;
    }
 

    //blok programu
    try{
        int size = std::stoi(argv[1]);//rozmiar tablicy
        Stack stos(size);

        //czytanie pierwszego znaku
        std::string input;
        cin>>input;
        cout<<"Liczba polecen: "<<input<<endl;

        //wlasciwa petla wykonujaca operacje
        while(cin>>input){

            switch(input[0]){

                case 'A'://poloz liczbe na stos
                cin>>input;
                stos.push(std::stoi(input));
                cout<<"Wstawiono element "<<input<<" na stos\n";
                break;

                case 'D'://zdejmuje element ze stosu
                if(!stos.empty())
                cout<<"Zdejmuje ze stosu element "<< stos.pop() <<endl;
                else cout<<"EMPTY"<< endl; 
                break;

                case 'S'://wypisuje rozmiar stosu
                cout<<"Rozmiar stosu wynosi "<<stos.size()<<" elementow"<<endl;
                break;

                case 'F': ///wczytaj liczbe i nic z nia nie rob                
                cin>>input;
                break;

                default:
                throw "Nieznane polecenie";
                break;
            }
        }
    }
    catch(std::exception& e){
        std::cerr<<e.what()<<endl;
    }
    catch(const char* msg){
        std::cerr<<msg<<endl;
    }catch(...){
        std::cerr<<"Wystapil niespodziewany blad"<<endl;
    }

    cout<<"Koniec programu"<<endl;
    return 0;
}
