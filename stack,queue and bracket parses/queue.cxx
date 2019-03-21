#include<iostream>
#include<string>
#include"queue.hxx"
using std::cout;
using std::endl;
using std::cin;

//konsturktory
Queue::Queue(int x)
    :h(0),t(0),s(x)
    {
        buf=new int[x];
    }
Queue::~Queue() { delete[] buf; }

// Wstawia element x do kolejki (także enqueue)
void Queue::push(int x){
    if(t==h-1 || (t==s-1 && h==0)) throw "Brak miejsca w pamieci";
    if(t==s-1) t=0;
    buf[t]=x;
    t++;
}

// Usuwa element z kolejki (także dequeue) i zwraca jego wartość
int Queue::pop(){
    if(empty()) return -1;//jak jest pusty to zwroci -1
    int temp=buf[h];
    buf[h]=0;
    if(h==s-1) h=0;
    else h++;
    return temp;
}

// Zwraca liczbę elementów w kolejce
int Queue::size(){
    return t-h;
}

// Sprawdza czy kolejka jest pusta
bool Queue::empty(){
    if(t==h) return true;
    else return false;
}

// Zwraca referencję do najstarszego elementu (także peek)
int& Queue::front(){
    int* front=&buf[h];
    return *front;
}



main(int argc, char* argv[])
{
    if(argc<2){
        cout<<"Prawidlowe wywolanie programu:(nazwa programu) (wielkosc tablicy) < (plik z poleceniami) \n";
        return -1;
    }

    //blok programu  
    try
    {
        int size = std::stoi(argv[1]);//rozmiar tablicy
        Queue kolejka(size);

        //czytanie pierwszego znaku
        std::string input;
        cin>>input;
        cout<<"Liczba polecen: "<<input<<endl;

        while(cin>>input){
            switch(input[0]){
                case 'A'://dodaj liczbe do kolejki
                cin>>input;
                kolejka.push(std::stoi(input));
                cout<<"Wstawiono element "<<input<<" do kolejki\n";
                break;

                case 'D'://zdejmij element z poczatku kolejki
                if(!kolejka.empty()) cout<<"Zdejmuje z kolejki element " <<kolejka.front()<<endl;
                else cout<<"EMPTY"<<endl;
                break;

                case 'S'://wypisuje rozmiar kolejki
                cout<<"Rozmiar kolejki wynosi "<<kolejka.size()<<" elementow"<<endl;
                break;

                case 'F'://wczytaj liczbe i nic z nia nie rob 
                cin>>input;                
                break;

                default:
                throw "Nieznane polecenie";
                break;
            }
        }
    }
    catch(std::exception& e)
    {
        std::cerr<<e.what()<<endl;
    }catch(const char* msg){
        std::cerr<<msg<<endl;
    }catch(...){
        std::cerr<<"Wystapil niespodziewany blad"<<endl;
    }
    
    cout<<"Koniec programu"<<endl;
    return 0;
}
