//by Grzegorz Koziol
#include<iostream>
#include<algorithm>
#include<string>
#include"sortedArrayList.hxx"
using std::cout;
using std::endl;
using std::cin;

SortedArrayList::SortedArrayList(int x)
:sz(x),i(0){
    buf=new int[x];
}
SortedArrayList::~SortedArrayList(){delete[]buf;}

bool SortedArrayList::empty(){
    if(i==0) return true;
    else return false;    
}

void SortedArrayList::print(){
    for(int j=0;j<i;j++)
        cout<<buf[j]<<" ";
        cout<<endl;
        
}

void SortedArrayList::push(int x){
    if(empty()){
        buf[0]=x;
        i++;
        return;
    }
    if(i==sz) throw "Pelna lista";

    int *pos=std::lower_bound(&buf[0],&buf[i-1],x);
    if(pos==buf+i-1 && *pos<=x){
        //gdy bedzie najwieksze lub rowne z najwiekszym
        buf[i]=x;
        i++;
        return;
    }else{
        //gdy jest gdzies w srodku tablicy
        int prev=buf[pos-buf];
        buf[pos-buf]=x;
        int next;
        for(int j=pos-buf;j<i;j++){
            next=buf[j+1];
            buf[j+1]=prev;
            prev=next;
        }
        i++;
    }
}

int SortedArrayList::pop(){
    if(empty()) return -1;

    int temp=buf[0];
    for(int j=1;j<i;j++){
        buf[j-1]=buf[j];
    }
    i--;
    return temp;
}

int SortedArrayList::erase(int x){
    if(x<=0|| x>i) throw "Nieprawidlowa pozycja erase()";
    int temp=buf[x-1];
    for(int j=x-1;j<i-1;j++){
        buf[j]=buf[j+1];
    }
    i--;
    return temp;
}

int SortedArrayList::find(int x){
    //skoro temp=buf+i to i=temp-buf
    //a dodajemy 1 bo nie chcemy wskazywac
    //na przyklad pozycji 0 dla pierwszego elementu
    int *temp=std::lower_bound(&buf[0],&buf[i-1],x);
    if(*temp!=x) return -1;
    return temp-buf+1;
}

int SortedArrayList::size () const {
    return i;
}

void SortedArrayList::remove(int x){
    //rekurencyjnie
    int *temp=std::lower_bound(&buf[0],&buf[i-1],x);
    if(*temp!=x) return;
    erase(temp-buf+1);
    remove(x);
    
}

SortedArrayList SortedArrayList::merge(const SortedArrayList& a, const SortedArrayList& b){
    SortedArrayList newList(a.size()+b.size());
    
    for(int i=0,j=0,k=0;i!=a.i && j!=b.i;){
        //gdy jedna z list jest juz wykorzystana
        if(i==a.i){
            while(j!=b.i){
                newList.buf[k]=b.buf[j];
                newList.i++;
                k++;
                j++;
            }
            break;
        }
        if(j==b.i){
            while(i!=a.i){
                newList.buf[k]=a.buf[i];
                newList.i++;
                k++;
                i++;
            }
            break;
        }

        if(a.buf[i]>b.buf[j]){
            newList.buf[k]=b.buf[j];
            newList.i++;
            j++;
        }else{
            newList.buf[k]=a.buf[i]; 
            newList.i++;    
            i++;
        }
    k++;  
    } 
    return newList;
}

void SortedArrayList::unique(){
    int last=buf[0];
    for(int j=1;j<i;j++){
        if(buf[j]==last){
            erase(j+1);
            j--;
        }else{
            last=buf[j];
        }
    }
}
