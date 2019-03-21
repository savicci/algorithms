class Heap {
private:
    void heapifyIter(int, double& ops);    // Wersja iteracyjna
    void heapifyRec(int);     // Wersja rekurencyjna
    int* buf;
    int sz;
    int ksz;                 //rozmiar kopca

public:
    Heap(int);
    ~Heap();

    void build(int[], int);
    void push(int x);         // Wstawia element do kopca
    int pop();                // Usuwa element z kopca
    int& top();               // Zwraca referncję do ostatniego elementu
    int size();               // Zwraca liczbę elementów w kopcu
    bool empty();             // Sprawdza czy kopiec jest pusty
    bool check();             // Sprawdza czy właściwość kopca jest zachowana
    void sortRec(int[], int);
    void sortIter(int[], int, double&);

    void print();
    inline int getElem(int x){ return buf[x];}
};