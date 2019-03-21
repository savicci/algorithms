#include"Heap.hxx"
#include<iostream>
#include<algorithm>
#include<vector>
using std::cout;
using std::endl;


Heap::Heap(int x)
:sz(x),ksz(0){
    buf=new int[x];
}

Heap::~Heap(){
    if(buf!=nullptr) delete[] buf;
}

void Heap::print(){
    for(int i=0;i<sz;i++)
        cout<<buf[i]<<" ";
    cout<<endl;
}

void Heap::build(int* a, int n){
    delete[]buf;
    sz=n;
    ksz=n;
    buf=new int[n];

    //kopiowanie do wewnetrznego bufora
    for(int i=0;i<n;i++)
        buf[i]=a[i];

    //tworzenie kopca
    for(int i=n/2-1;i>=0;i--)
        //heapifyIter(i);
        heapifyRec(i);
}

void Heap::heapifyRec(int i){
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

void Heap::sortRec(int* a, int n){
    build(a,n);

    for(int i=n-1;i>=0;i--){
        //zmniejszanie rozmiaru kopca
        ksz--;
        std::swap(buf[i],buf[0]);

        //poprawianie kopca
        heapifyRec(0);
    }
    ksz=n;
}

void Heap::heapifyIter(int i, double& ops){
    int largest=i;
    int last=i;

    do{
    last=largest;
    if(2*last+1 < ksz && buf[largest] < buf[2*last+1]){
        largest=2*last+1;   
        ops++;
    }
    if(2*last+2 < ksz && buf[largest] < buf[2*last+2]){
        largest=2*last+2;
        ops++;
    }
    if(largest!=last){
        std::swap(buf[last],buf[largest]);   
        ops++;
    }
    }while(largest!=last);
}

void Heap::sortIter(int* a, int n, double& ops){
    build(a,n);

    for(int i=n-1;i>=0;i--){
        //zmniejszanie rozmiaru kopca
        ksz--;
        ops++;
        std::swap(buf[i],buf[0]);

        //poprawianie kopca
        heapifyIter(0,ops);
    }
    ksz=n;
}

void Heap::push(int x){
    if(ksz==sz) throw "Ful heap- cannot call push";

    buf[ksz]=x;
    int temp=ksz;
    ksz++;
    while(temp>0 && buf[temp] > buf[temp/2]){
        std::swap(buf[temp],buf[temp/2]);
        temp=temp/2;
    }
}

int Heap::pop(){
    if(empty()) throw"Empty heap-cannot call pop";

    //przestawiamy ostatni element na miejsce korzenia
    int ret=buf[0];
    buf[0]=buf[ksz-1];
    ksz--;
    //ustawiamy pierwszy element na dobre miejsce
    heapifyRec(0);

    return ret;
}

int& Heap::top(){
    if(empty()) throw "Empty heap-cannot call top";
    return buf[ksz-1];
}

int Heap::size(){
    return ksz;
}

bool Heap::check(){
    if(empty()) throw"Empty heap-cannot call check()";

    int temp;
    for(int i=0;i<sz/2-1;i++){
        temp=i;
        if(buf[temp] < buf[temp*2+1] && temp*2+1 < ksz) return false;
        else if(buf[temp] < buf[temp*2+2] && temp*2+2 < ksz) return false;
    }
    return true;
}

bool Heap::empty(){
    if(ksz==0) return true;
    else return false;
}