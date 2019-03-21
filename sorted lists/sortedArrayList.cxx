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
        buf[i]=x;
        i++;
        return;
    }else{
        int prev=buf[pos-buf];
        buf[pos-buf]=x;
        int next=buf[pos-buf+1];
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
    SortedArrayList newList(a.size()+b.size()+1);

    for(int i=0;i<a.size();i++){
        newList.push(a.getElem(i));
    }
    for(int b_iter=0;b_iter<b.size();b_iter++){
        newList.push(b.getElem(b_iter));
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


// int main(int argc, char const *argv[])
// {
//     if(argc!=3){
//         cout<<"Przykladowe wywolanie: <wielkosc listy 1> <wielkosc listy 2>"<<endl;
//         exit(-1);
//     }
//     try{
//         SortedArrayList list1= SortedArrayList(std::stoi(argv[1]));
//         SortedArrayList list2= SortedArrayList(std::stoi(argv[2]));
//         std::string input;

//         cin>>input;
//         cout<<"Ilosc liczb do listy1 "<<input<<endl;
//         int ops=std::stoi(input);

//         for(int i=0;i<ops;i++){
//             cin>>input;
//             list1.push(std::stoi(input));
//         }
//         list1.print();

//         cin>>input;
//         cout<<"Ilosc liczb do listy2 "<<input<<endl;
//         ops=std::stoi(input);

//         for(int i=0;i<ops;i++){
//             cin>>input;
//             list2.push(std::stoi(input));
//         }
//         list2.print();

//         //scalanie i operacja unique()
//         SortedArrayList newList=SortedArrayList::merge(list1,list2);
//         newList.print();
//         newList.unique();
//         newList.print();


//     }catch(const char* msg){
//         std::cerr<<msg<<endl;
//         exit(-1);
//     }

//     return 0;
// }
