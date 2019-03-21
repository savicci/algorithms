#include<iostream>

class SortedArrayList {
    public:
    SortedArrayList(int);
    ~SortedArrayList();


    void push(int);   // Wstawia element 'x'
    int pop();          // Zwraca i usuwa pierwszy (najmniejszy) element
    int erase(int);   // Usuwa element na pozycji 'i' i zwraca jego wartość
    int find(int);    // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
    int size () const ;         // Zwraca liczbę elementów w liście
    void remove(int x); // Usuwa wszystkie elementy równe 'x'
    void unique();      // Usuwa sąsiadujące duplikaty
    void print();       // Wypisuje elementy listy w porządku rosnącym
    bool empty();       //sprawdza czy lista jest pusta i zwraca true jesli jest    

    // Scala dwie posortowane listy i zwraca posortowaną listę
    static SortedArrayList merge(const SortedArrayList& a, const SortedArrayList& b);

    //tworzymy funkcje pomocnicza niemodyfikujaca
    int getElem(int j) const { return buf[j];}

    private:
    int *buf;           //bufor danych
    int i;              //indeks ostatniego wolnego elementu
    int sz;             //rozmiar tablicy
};
