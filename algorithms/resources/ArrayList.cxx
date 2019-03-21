
template<class T>
class ArrayList {
    public:

    ArrayList(int);
    ArrayList();
    ~ArrayList();

    void push_front(T x);       // Wstawia element na początek listy
    void pop_front();            // Usuwa element z początku listy i zwraca jego wartość
    void push_back(T x);        // Wstawia element na koniec listy
    void pop_back();             // Usuwa element z końca listy  i zwraca jego wartość

    //position_t find(int);       // Wyszukuje element o wartości `x` i zwraca do niego wskaźnik lub `nullptr` gdy nie element istnieje
    //position_t erase(position_t );           // Usuwa element z pozycji pos i zwraca pozycję za usuwanym elementem
    //position_t insert(position_t, int);   // Wstawia element x przed pozycję pos i zwraca pozycję x
    
    int size();              // Zwraca liczbę elementów w liście

    bool empty();               //funkcja pomocnicza- sprawdza czy lista jest pusta
    void print();               //drukuje cala liste
    void swap(int, int);

    T* buf;       //bufor danych
    private:
    int k;          //indeks ostatniego wolnego elementu w tablicy
    int s;         //rozmiar tablicy
};


//IMPLEMENTACJA

//by Grzegorz Koziol
#include<iostream>
#include<string>
using position_t=int;
using std::endl;
using std::cout;
using std::cin;


template<class T>
ArrayList<T>::ArrayList(int x)
:k(0),s(x){
    buf=new T[x];
}

template<class T>
int ArrayList<T>::size(){
    return s;
}

template<class T>
ArrayList<T>::ArrayList()
:k(0),s(1){
    buf=new T;
}

template<class T>
ArrayList<T>::~ArrayList() { delete[] buf; }


template<class T>
void ArrayList<T>::push_front(T x){
    if(k==s) throw "Nie ma miejsca na dodatkowy element";

    T prev,next;//indeksy potrzebne do "shuffle" tablicy
    prev=buf[0];
    buf[0]=x;
    for(int j=0;j<k;j++){
        next=buf[j+1];
        buf[j+1]=prev;
        prev=next; 
    }
    k++;
}

template<class T>
void ArrayList<T>::push_back(T x){
    if(k==s) throw "Nie ma miejsca na dodatkowy element";
    buf[k]=x;
    k++;
}

template<class T>
void ArrayList<T>::pop_front(){
    T ret=buf[0];
    for(int j=0;j<size();j++){
        buf[j]=buf[j+1];
    }
    k--;
}

template<class T>
void ArrayList<T>::pop_back(){
    k--;
}

template<class T>
bool ArrayList<T>::empty(){
    if(k==0) return true;
    else return false;
}

//funkcja pomocnicza, rysuje liste
template<class T>
void ArrayList<T>::print(){
    if(empty()) return;
    for(int j=0;j<k;j++)
        cout<<buf[j]<<endl;
}

template<class T>
void ArrayList<T>::swap(int x, int y){
    if(x>=k || y>=k || x<0 || y<0) throw "Poza tablica";

    T temp=buf[x];
    buf[x]=buf[y];
    buf[y]=temp;
}