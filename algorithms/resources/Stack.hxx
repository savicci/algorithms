#include<iostream>

class Stack{
    public:
    //konstruktory
    Stack(int x);
    ~Stack();

 
    void push(int x); // Wstawia element x na stos
    int pop();        // Usuwa element ze stosu i zwraca jego wartość
    int& top();       // Zwraca referencję do najmłodszego elementu
    int size();       // Zwraca liczbę elementów na stosie
    bool empty();     // Sprawdza czy stos jest pusty

    private:
    int* buf; //bufor danych
    int i;    //indeks
    int s;    //rozmiar tablicy

};