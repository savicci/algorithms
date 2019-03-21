//by Grzegorz Koziol
#include<iostream>
#include"LinkedList.hxx"
using position_t=int*;
using std::cout;
using std::endl;
using std::cin;

//konstruktory wezla
LinkedList::Node::Node()
:x(0),prev(NULL),next(NULL){}

LinkedList::Node::Node(int a)
:x(a),prev(NULL),next(NULL){}


//konstruktory list->
LinkedList::LinkedList()
:sz(0){
    head=NULL;
    tail=NULL;
}

void LinkedList::push_back(int a){
    Node* temp=new Node(a);

    if(tail==NULL){
        head=temp;
        tail=temp;
        sz++;
    }else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
        sz++;
    }
}

void LinkedList::push_front(int a){
    Node* temp=new Node(a);

    if(head==NULL){
        head=temp;
        tail=temp;
        sz++;
    }else{
        temp->next=head;
        head->prev=temp;
        head=temp;
        sz++;
    }
}

int LinkedList::pop_back(){
    if(empty()) return -1;
    Node* temp=new Node();
    int val=tail->x;
    temp=tail->prev;
    if(head==tail){
        head=NULL;
        tail=NULL;
        sz--;
        delete temp;
    }else{
        temp->next=NULL;
        delete tail;
        tail=temp;
        sz--;
    }
    return val;
}

int LinkedList::pop_front(){
    if(empty()) return -1;
    Node *temp=new Node();
    int val=head->x;
    temp=head->next;
    if(head==tail){
        head=NULL;
        tail=NULL;
        sz--;
        delete temp;
    }else{
        temp->prev=NULL;
        delete head;
        head=temp;
        sz--;
    }
    return val;
}

position_t LinkedList::find(int a){
    if(empty()) return NULL;
    Node* temp=new Node();
    temp=head;

    do{
        if(temp->x==a) return &temp->x;
        temp=temp->next;
    }while(temp!=NULL);
    
    return NULL;
}


position_t LinkedList::erase(int a){
    if(a<0 || a> size()) throw "Niewlasciwy indeks";
    Node* temp=new Node();
    temp=head;
    int count=1;

    //dojscie do odpowiedniego elementu
    while(count<a){
        temp=temp->next;
        count++;
    }

    if(temp==head){
        pop_front();
        sz--;
    }else if(temp==tail){
        pop_back();
        sz--;
    }else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        sz--;
    }
    return &temp->next->x;
}

position_t LinkedList::insert(int pos, int s){
    if(pos<0 || pos>size()) throw "Nie mozna wstawic na ta pozycje";
    if(pos==1){
        push_front(s);
        Node* temp=head->next;
        return &temp->x;
    } 
    if(pos==size()+1){
        push_back(s);
        Node* temp=tail;
        return &temp->x;
    } 
    Node* temp=head;
    Node *newNode= new Node(s);

    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    temp->prev->next=newNode;
    newNode->prev=temp->prev;
    newNode->next=temp;
    temp->prev=newNode;
    sz++;

    return &temp->x;
}

bool LinkedList::empty(){
    if(sz==0) return true;
    else return false;
}

int LinkedList::size(){
    return sz;
}

//pomocnicze
void LinkedList::print(){
    Node* temp=new Node();
    temp=head;

    while(temp!=NULL){
        cout<<temp->x<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



int main(int argc, char const *argv[])
{
    if(argc!=2){
        std::cerr<<"Podaj rozmiar tablicy do list->\n";
        exit(-1);
    }
    //utworzenie list->
    LinkedList* list=new LinkedList();
    int temp;
    int* f;//find

        try{
        std::string input;
        cin>>input;
        cout<<"Liczba polecen: "<<input<<endl;
        //wlasciwa petla wykonujaca operacje
        while(cin>>input){

            switch(input[0]){
                
                case 'B'://dodaj liczbe na koniec list->
                cin>>input;
                list->push_back(std::stoi(input));
                cout<<"Klade liczbe "<<input<<" na koniec listy"<<endl;
                break;

                case 'f'://usun pierwszy element, jak jest puste wypisz EMPTY
                if(list->empty()){
                    cout<<"EMPTY"<<endl;
                    break;
                }
                temp=list->pop_front();
                cout<<"Sciagam "<<temp<<" z poczatku listy"<<endl;
                break;

                case 'b'://usun ostatni element
                if(list->empty()){
                cout<<"EMPTY"<<endl;
                    break;
                }
                temp=list->pop_back();
                cout<<"Sciagam "<<temp<<" z konca listy"<<endl;
                break;

                case 'S'://wypisz rozmiar list->            
                cout<<"Rozmiar listy to "<<list->size()<<" elementow"<<endl;
                break;

                case 'F': //dodaj liczbe na poczatek tablicy  
                cin>>input;
                list->push_front(std::stoi(input));
                cout<<"Klade liczbe "<<input<<" na poczatek listy"<<endl;
                break;

                case 'C'://wypisz TRUE jak jest obecne w liscie, FALSE jak nie
                cin>>input;
                f=list->find(std::stoi(input));
                if(f==NULL) cout<<"FALSE"<<endl;
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
