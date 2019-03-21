//by Grzegorz Koziol
//program symulujacy dzialanie stosu oparty o tablice o ustalonym rozmiarze
#include<iostream>
#include<string>
#include"Stack.hxx"
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

