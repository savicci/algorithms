//by Grzegorz Koziol
#include<iostream>
#include"SortedLinkedList.hxx"
using std::endl;
using std::cout;
using std::cin;

SortedLinkedList::Node::Node(int a){
    x=a;
    prev=NULL;
    next=NULL;
}

SortedLinkedList::SortedLinkedList(){
    head=NULL;
    tail=NULL;
    sz=0;
};

bool SortedLinkedList::empty(){
    if(sz==0) return true;
    else return false;
}


void SortedLinkedList::push(int a){
    if(empty()){
        //gdy jest pierwszym elementem
        Node* temp= new Node(a);
        head=temp;
        tail=temp;
        sz++;
        return;
    }
    Node* temp=new Node(a);
    if(temp->x <= head->x){
        //gdy element jest najmniejszy z listy
        head->prev=temp;
        temp->next=head;
        head=temp;
        sz++;
    }else{
        Node* place=head;

    while(temp->x > place->x){
            if(place->next!=NULL && temp->x <= place->next->x){
                //gdy nastepny element jest wiekszy badz rowny a
                temp->next=place->next;
                place->next=temp;
                temp->prev=place;
                temp->next->prev=temp;
                sz++;
                return;
            }
            else if(place->next!=NULL && temp->x > place->next->x)
                //gdy nastepny element jest wiekszy od naszego a
                place=place->next;
            else if(place->next==NULL){
                //gdy nie ma juz elementow== a jest najwieksze z listy
                place->next=temp;
                temp->prev=place;
                tail=temp;
                sz++;
                return;
            }
            
        }
    }
}

void SortedLinkedList::print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->x<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int SortedLinkedList::pop(){
    int temp=head->x;
    head=head->next;
    delete head->prev;
    sz--;
    return temp;
}

int SortedLinkedList::erase(int a){
    if(a<=0 || a>sz) throw "Nieprawidlowa pozycja erase()";

    Node* temp=head;
    int x=head->x;
    int count=1;
    while(count<a){
        temp=temp->next;
        count++;
    }
    if(count==1){
        //gdy usuwamy pierwszy element
        if(head->next!=NULL) head=head->next;
        else head->next=NULL;

        head->prev=NULL;
        x=temp->x;
        delete temp;
        sz--;
        return x;
    }
    else if(count==sz){
        //gdy usuwamy ostatni element
        x=tail->x;
        tail=tail->prev;
        delete tail->next;
        tail->next=NULL;
        sz--;
        return x;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    x=temp->x;
    delete temp;
    sz--;
    return x;
}

int SortedLinkedList::find(int a){
    Node* temp=head;
    int count=1;
    while(temp!=NULL){
        if(temp->x == a) return count;
        temp=temp->next;
        count++;
    }
    return -1;
}

int SortedLinkedList::size(){
    return sz;
}

void SortedLinkedList::remove(int a){
    if(empty()) return;

    Node* temp=head;

    //gdy nie ma takiej wartosci
    if(head->x > a || tail->x < a)return;

    while(temp!=NULL){
        if(temp->x == a){
            if(temp==head){
                //gdy jest pierwszym elementem
                head=head->next;
                temp=temp->next;
                delete head->prev;
                sz--;
                continue;
            }
            else if(temp==tail){
                //gdy jest ostatnim
                tail=tail->prev;
                delete tail->next;
                tail->next=NULL;
                sz--;
                return;
            }
            else{
                Node* toDelete=temp;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                temp=temp->next;
                delete toDelete;
                sz--;
                continue;
            }
        }
        temp=temp->next;
    }
}

void SortedLinkedList::unique(){
    if(empty()|| head==tail) return;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->next==NULL) break;
        if(temp->x!=temp->next->x){
            temp=temp->next;
            continue;
        }
        if(temp->next==tail){
            if(temp->x==tail->x){
                tail=temp;
                delete temp->next;
                tail->next=NULL;
                sz--;
                break;
            }
        }
        Node* toDel=temp->next;
        temp->next=temp->next->next;
        temp->next->prev=temp;
        delete toDel;        
        sz--;
    }

}

SortedLinkedList SortedLinkedList::merge(const SortedLinkedList& a, const SortedLinkedList& b){
    SortedLinkedList newList=SortedLinkedList();
    for(Node* i=a.head;i!=NULL;i=i->next){
        newList.push(i->x);
    }

     for(Node* i=b.head;i!=NULL;i=i->next){
        newList.push(i->x);
    }
    return newList;
}


// int main(int argc, char const *argv[])
// {
//     if(argc!=3){
//         cout<<"Przykladowe wywolanie: <wielkosc listy 1> <wielkosc listy 2>"<<endl;
//         exit(-1);
//     }
//     try{
//         SortedLinkedList list1= SortedLinkedList();
//         SortedLinkedList list2= SortedLinkedList();
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
//         SortedLinkedList newList=SortedLinkedList::merge(list1,list2);
//         newList.print();
//         newList.unique();
//         newList.print();


//     }catch(const char* msg){
//         std::cerr<<msg<<endl;
//         exit(-1);
//     }
//     return 0;
// }
