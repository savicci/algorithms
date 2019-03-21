#include<iostream>
using position_t=int;

class CursorList {  // Klasa listy
    public:
    CursorList(int);
    ~CursorList();


    void push_front(int x);     // Wstawia element na początek listy
    int pop_front();            // Usuwa element z początku listy i zwraca jego wartość
    void push_back(int x);      // Wstawia element na koniec listy
    int pop_back();             // Usuwa element z końca listy  i zwraca jego wartość
    position_t find(int x);     // Wyszukuje element o wartości `x` i zwraca do niego wskaźnik lub `nullptr` gdy nie element istnieje
    position_t erase(position_t);           // Usuwa element z pozycji pos i zwraca pozycję za usuwanym elementem
    position_t insert(position_t, int );   // Wstawia element x przed pozycję pos i zwraca pozycję x
    int size();                 // Zwraca liczbę elementów w liście
    bool empty();               //pomocnicza funkcja- sprawdza czy lista jest pusta

    int nextFree();             //pomocnicza funkcja- zwraca nastepny wolny indeks
    void print();
 
  private:
        struct node {   // Zagnieżdżona klasa węzła
        node();

        int x;          // Element przechowywany przez węzeł listy
        int next;       // Indeks kolejnego węzła
  };

    node* arr;      // Tablica węzłów
    int head;       // Indeks pierwszego węzła
    int tail;       //koniec listy
    int sz;         //  rozmiar listy
};