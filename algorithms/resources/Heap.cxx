//IMPLEMENTACJA
//by Grzegorz Koziol
#include<iostream>
#include<algorithm>
#include<vector>
using std::cout;
using std::endl;

template<class T>
class Heap {
private:
    void heapifyIter(int i);
    void heapifyRec(int i);
    T* buf;
    int sz;
    int ksz;                 //rozmiar kopca

public:
    Heap(int i);
    Heap();

    void build(T* a, int n);

    void push(T x);         // Wstawia element do kopca
    int pop();                // Usuwa element z kopca
    T& top();               // Zwraca referncję do ostatniego elementu
    int size();
    bool empty();             // Sprawdza czy kopiec jest pusty
    bool check();             // Sprawdza czy właściwość kopca jest zachowana
    T* sortRec(T*&, int);
    T* sortIter(T*&, int);

    void print();
    inline int getElem(int x){ return buf[x];}
};


template<class T>
void Heap<T>::heapifyIter(int i){
    int largest=i;
    int last=i;

    do{
    last=largest;
    if(2*last+1 < ksz && buf[largest] < buf[2*last+1]){
        largest=2*last+1;   
    }
    if(2*last+2 < ksz && buf[largest] < buf[2*last+2]){
        largest=2*last+2;
    }
    if(largest!=last){
        std::swap(buf[last],buf[largest]);   
    }
    }while(largest!=last);
}

template<class T>
void Heap<T>::heapifyRec(int i){
    int largest=i;
    if(2*i+1 < ksz && buf[largest] < buf[2*i+1]){
        largest=2*i+1;   
    }
    if(2*i+2 < ksz && buf[largest] < buf[2*i+2]){
        largest=2*i+2;
    }
    if(largest!=i){
        std::swap(buf[i],buf[largest]);
        heapifyRec(largest);
    }
}

    template<class T>
    Heap<T>::Heap(int i)
    :sz(i),ksz(0){
    buf=new T[i];
}

template<class T>
Heap<T>::Heap(){
    buf=new T;
}

template<class T>
T* Heap<T>::sortIter(T*& a, int n){
    build(a,n);
    for(int i=n-1;i>=0;i--){
        //zmniejszanie rozmiaru kopca
        ksz--;
        std::swap(buf[i],buf[0]);

        //poprawianie kopca
        heapifyIter(0);
    }
    return buf;
}


template<class T>
void Heap<T>::build(T* a, int n){
    delete[]buf;
    sz=n;
    ksz=n;
    buf=new T[n];

    //kopiowanie do wewnetrznego bufora
    for(int i=0;i<n;i++)
        buf[i]=a[i];

    //tworzenie kopca
    for(int i=n/2-1;i>=0;i--)
    //heapifyIter(i);
    heapifyRec(i);
}

template<class T>
void Heap<T>::print(){
    for(int i=0;i<sz;i++){
        std::cout<<buf[i]<<std::endl;
    }
}

template<class T>
T* Heap<T>::sortRec(T*& a, int n){
    build(a,n);

    for(int i=n-1;i>=0;i--){
        //zmniejszanie rozmiaru kopca
        ksz--;
        std::swap(buf[i],buf[0]);

        //poprawianie kopca
        heapifyRec(0);
    }
    ksz=n;
    return buf;
}

template<class T>
void Heap<T>::push(T x){
    if(ksz==sz) throw "Ful heap- cannot call push";

    buf[ksz]=x;
    int temp=ksz;
    ksz++;
    while(temp>0 && buf[temp] > buf[temp/2]){
        std::swap(buf[temp],buf[temp/2]);
        temp=temp/2;
    }
}

template<class T>
int Heap<T>::pop(){
    if(empty()) throw"Empty heap-cannot call pop";

    //przestawiamy ostatni element na miejsce korzenia
    T ret=buf[0];
    buf[0]=buf[ksz-1];
    ksz--;
    //ustawiamy pierwszy element na dobre miejsce
    heapifyRec(0);

    return ret;
}

template<class T>
T& Heap<T>::top(){
    if(empty()) throw "Empty heap-cannot call top";
    return buf[ksz-1];
}


template<class T>
bool Heap<T>::check(){
    if(empty()) throw"Empty heap-cannot call check()";

    int temp;
    for(int i=0;i<sz/2-1;i++){
        temp=i;
        if(buf[temp] < buf[temp*2+1] && temp*2+1 < ksz) return false;
        else if(buf[temp] < buf[temp*2+2] && temp*2+2 < ksz) return false;
    }
    return true;
}

template<class T>
bool Heap<T>::empty(){
    if(ksz==0) return true;
    else return false;
}