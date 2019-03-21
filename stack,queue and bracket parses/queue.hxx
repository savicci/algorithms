#include<iostream>
class Queue {
    public:
    //konsturktory
    Queue(int x);
    ~Queue();

    void push(int x);     // Wstawia element x do kolejki (także enqueue)
    int pop();            // Usuwa element z kolejki (także dequeue) i zwraca jego wartość
    int& front();         // Zwraca referencję do najstarszego elementu (także peek)
    int size();           // Zwraca liczbę elementów w kolejce
    bool empty();         // Sprawdza czy kolejka jest pusta

    private:
    int* buf;//bufor danych
    int h;//head-poczatek kolejki
    int t;//tail-koniec kolejki 
    int s;//rozmiar tablicy
};