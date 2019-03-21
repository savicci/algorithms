#include<iostream>
using position_t=int;

class ArrayList {
    public:

    ArrayList(int);
    ~ArrayList();

    void push_front(int);       // Wstawia element na początek listy
    int pop_front();            // Usuwa element z początku listy i zwraca jego wartość
    void push_back(int);        // Wstawia element na koniec listy
    int pop_back();             // Usuwa element z końca listy  i zwraca jego wartość
    position_t find(int);       // Wyszukuje element o wartości `x` i zwraca do niego wskaźnik lub `nullptr` gdy nie element istnieje
    position_t erase(position_t );           // Usuwa element z pozycji pos i zwraca pozycję za usuwanym elementem
    position_t insert(position_t, int);   // Wstawia element x przed pozycję pos i zwraca pozycję x
    static int size();                 // Zwraca liczbę elementów w liście

    bool empty();               //funkcja pomocnicza- sprawdza czy lista jest pusta
    void print();               //drukuje cala liste

    private:
    int* buf;       //bufor danych
    int i;          //indeks ostatniego wolnego elementu w tablicy
    int s;         //rozmiar tablicy
};