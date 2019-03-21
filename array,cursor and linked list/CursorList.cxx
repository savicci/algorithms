//by Grzegorz Koziol
#include<iostream>
#include"CursorList.hxx"
using namespace std;

#define END -2

CursorList::node::node()
:x(0),next(-1){}

CursorList::CursorList(int a)
:head(0),tail(0),sz(a){
    arr=new node[a];
}
CursorList::~CursorList() { delete[] arr; }

int CursorList::nextFree(){
    for(int i=0;i<sz;i++){
        if(arr[i].next==-1) return i;
    }
    throw "Nie ma miejsca";
}

void CursorList::push_back(int a){
    if(head==tail && arr[head].next==-1){
        arr[head].x=a;
        arr[head].next=END;
        return;
    }

    int temp=nextFree();
    arr[temp].x=a;
    arr[tail].next=temp;
    arr[temp].next=END;
    tail=temp;
}

void CursorList::push_front(int a){
    
    int temp=nextFree();
    arr[temp].x=a;

    //sprawdzamy czy jest to pierwszy element w liscie
    if(arr[head].next!=-1 ){
        arr[temp].next=head;
        head=temp;
    }
    else{
        //jesli nie to wykonujemy ta czesc
        arr[head].x=a;
        arr[head].next=END;
    };
}

int CursorList::pop_back(){
    //najpierw sprawdz czy lista jest pusta
    if((head==tail)&& arr[tail].next==-1) return -1;

    //jesli lista zawiera jeden element
    if(head==tail && arr[tail].next==END){
        arr[tail].next=-1;
        tail=head;
        return arr[tail].x;
    }

    int temp=arr[tail].x;
    arr[tail].next=-1;
    //teraz musimy znalezc element ktory wskazuje na tail
    //nie da sie inaczej jak przez petle
    int last=head;
    while(true){
        if(arr[last].next==tail){
            
            tail=last;
            arr[last].next=END;
            break;
        }
        last=arr[last].next;
    }
    return temp;
}

int CursorList::pop_front(){
    //najpierw sprawdz czy lista jest pusta
    if((head==tail)&& arr[tail].next==-1) return -1;

    //jesli lista ma jeden element
    if(head==tail && arr[head].next==END){
        arr[head].next=-1;
        head=tail;
        return arr[head].x;
    }
    //pozostale przypadki
    if((tail==-2)&& arr[tail].next==-1){
        tail=0;
        return -1;
    }
   

    int temp=arr[head].x;
    int x=head;//pomocnicza zmienna do zapisu pozycji head zanim ja usuniemy
    head=arr[head].next;
    arr[x].next=-1;

    return temp;
}

position_t CursorList::find(int x){
    if(empty()) return -1;

    for(int i=head;i!=END;i=arr[i].next){
        if(arr[i].x==x) return arr[i].x;
    }
    return -1;
}

position_t CursorList::erase(position_t a){
    if(a<0 || a>size()) throw "Poza tablica";
    int i=head;
    int prev=head;
    int count=0;

    //znajdz element ktory ma byc wymazany
    while(count<a-1){
        prev=i;
        i=arr[i].next;
        count++;
    }//jesli jest to pierwszy badz ostatni to lepiej uzyc funkcji
    if(i==head){
        pop_front();
    }else if(i==tail){
        pop_back();
    }else{
        arr[prev].next=arr[i].next;
        arr[i].next=-1;   
    } 

    if(head==tail ) return -1;//nie mozna zwrocic elementu z pustej listy
    return arr[a+1].x;
}

 position_t CursorList::insert(position_t pos, int x){
    if(pos>size() || pos<0 ) throw "Nieprawidlowy indeks";
    if(pos==1){
        push_front(x);
        return arr[head].x;
    }
    if(pos==size()+1){
        push_back(x);
        return arr[tail].x;
    }

    int temp=nextFree();
    int prev=head;
    int nxt=head;
    for(int i=0;i<pos-1;i++){
        prev=arr[nxt].next;
        nxt=arr[nxt].next;
    }
    nxt=arr[nxt].next;
    arr[prev].next=temp;
    arr[temp].next=nxt;

    return arr[arr[temp].next].x;
 }


int CursorList::size(){
    int size=0;
    int i=head;
    if(head==tail && arr[head].next==-1) return 0;//jak jest pusta

    do{
        size++;
        i=arr[i].next;
    }while(i!=END);
    return size;
}

bool CursorList::empty(){
    if(head==tail && arr[head].next==-1) return true;
    else return false;
}

//funkcja pomocnicza, rysuje liste
void CursorList::print(){
    if(head==tail && arr[head].next==-1) return;
    for(int i=head;i!=END;i=arr[i].next)
        cout<<arr[i].x<<" ";
        cout<<endl;
}

int main(int argc, char const *argv[])
{
     if(argc!=2){
        std::cerr<<"Podaj rozmiar tablicy do listy\n";
        exit(-1);
    }
    //utworzenie listy
    CursorList list(std::stoi(argv[1]));
    int temp;

        try{
        std::string input;
        cin>>input;
        cout<<"Liczba polecen: "<<input<<endl;
        //wlasciwa petla wykonujaca operacje
        while(cin>>input){

            switch(input[0]){
                
                case 'B'://dodaj liczbe na koniec listy
                cin>>input;
                list.push_back(std::stoi(input));
                cout<<"Klade liczbe "<<input<<" na koniec listy"<<endl;
                break;

                case 'f'://usun pierwszy element, jak jest puste wypisz EMPTY
                if(list.empty()){
                    cout<<"EMPTY"<<endl;
                    break;
                }
                temp=list.pop_front();
                cout<<"Sciagam "<<temp<<" z poczatku listy"<<endl;
                break;

                case 'b'://usun ostatni element
                if(list.empty()){
                cout<<"EMPTY"<<endl;
                    break;
                }
                temp=list.pop_back();
                cout<<"Sciagam "<<temp<<" z konca listy"<<endl;
                break;

                case 'S'://wypisz rozmiar listy            
                cout<<"Rozmiar listy to "<<list.size()<<" elementow"<<endl;
                break;

                case 'F': //dodaj liczbe na poczatek tablicy  
                cin>>input;
                list.push_front(std::stoi(input));
                cout<<"Klade liczbe "<<input<<" na poczatek listy"<<endl;
                break;

                case 'C'://wypisz TRUE jak jest obecne w liscie, FALSE jak nie
                cin>>input;
                temp=list.find(std::stoi(input));
                if(temp==-1) cout<<"FALSE"<<endl;
                else cout<<"TRUE"<<endl;
                break;

                default:
                throw "Nieznane polecenie";
                break;
            }
        }
        }catch(std::exception& e){
        std::cerr<<e.what()<<endl;
        }
        catch(const char* msg){
        std::cerr<<msg<<endl;
        }
        catch(...){
        std::cerr<<"Wystapil niespodziewany blad"<<endl;
        }

    return 0;
}
