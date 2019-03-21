#include<iostream>
using position_t=int*;

class LinkedList {  // Klasa listy
    public:
    LinkedList();

    void push_front(int);     // Wstawia element na początek listy
    int pop_front();            // Usuwa element z początku listy i zwraca jego wartość
    void push_back(int);      // Wstawia element na koniec listy
    int pop_back();             // Usuwa element z końca listy  i zwraca jego wartość
    position_t find(int);     // Wyszukuje element o wartości `x` i zwraca do niego wskaźnik lub `nullptr` gdy nie element istnieje
    position_t erase(int);           // Usuwa element z pozycji pos i zwraca pozycję za usuwanym elementem
    position_t insert(int, int );   // Wstawia element x przed pozycję pos i zwraca pozycję x
    int size();                 // Zwraca liczbę elementów w liście
    bool empty();               //pomocnicza funkcja-sprawdza czy lista jest pusta

    void print();

    private:
    struct Node {           // Zagnieżdżona klasa węzła
        Node();
        Node(int);

        int x;              // Element przechowywany przez węzeł listy
        Node* prev;         // Wskaźnik do poprzedniego węzła
        Node* next;         // Wskaźnik do kolejnego węzła
    };
    Node* head;             // Wskaźnik do pierwszego węzła
    Node* tail;             // Wskaźnik do ostatniego węzła
    int sz;               // Ew. rozmiar listy
};