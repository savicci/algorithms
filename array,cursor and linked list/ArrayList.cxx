//by Grzegorz Koziol
#include<iostream>
#include<string>
#include"ArrayList.hxx"
using position_t=int;
using std::endl;
using std::cout;
using std::cin;

ArrayList::ArrayList(int x)
:i(0),s(x){
    buf=new int[x];
}

ArrayList::~ArrayList() { delete[] buf; }


void ArrayList::push_front(int x){
    if(i==s-1) throw "Nie ma miejsca na dodatkowy element";

    int prev,next;//indeksy potrzebne do "shuffle" tablicy
    prev=buf[0];
    buf[0]=x;
    for(int j=0;j<i;j++){
        next=buf[j+1];
        buf[j+1]=prev;
        prev=next; 
    }
    i++;
}

void ArrayList::push_back(int x){
    if(i==s-1) throw "Nie ma miejsca na dodatkowy element";
    buf[i]=x;
    i++;
}

int ArrayList::pop_front(){
    int ret=buf[0];
    for(int j=0;j<size();j++){
        buf[j]=buf[j+1];
    }
    i--;
    return ret;
}

int ArrayList::pop_back(){
    i--;
    return buf[i];
}


position_t ArrayList::find(int x){
    for(int j=0;j<i;j++){
        if(buf[j]==x) return buf[j];
    }
    return -1;
}

//nie dziala O(1) tylko raczej O(n)
position_t ArrayList::erase(position_t x){
    if(x<0 || x>size()) throw "Nieprawidlowa pozycja w tablicy";
    
    if(x==s-1) throw "Nie mozna zwrocic nastepnego elementu";
    int temp=buf[x+1];   

    for(int j=x-1;j<i;j++){
        buf[j]=buf[j+1];
    }
    i--;
    return temp;
}

position_t ArrayList::insert(position_t pos, int x){
    if(pos==0) throw "Nieprawidlowa pozycja";
    if(i==s-1) throw "Nie ma miejsca";

    int next=x;
    for(int j=pos;j<i+1;j++){
        int prev=buf[pos];
        buf[pos]=next;
        next=prev;
    }   
    i++;
    return pos;
}

static int ArrayList::size(){
    return i;
}

bool ArrayList::empty(){
    if(i==0) return true;
    else return false;
}

//funkcja pomocnicza, rysuje liste
void ArrayList::print(){
    if(empty()) return;
    for(int j=0;j<i;j++)
        cout<<buf[j]<<" ";
        cout<<endl;
}

//MAIN
int main(int argc, char* argv[]){

    if(argc!=2){
        std::cerr<<"Podaj rozmiar tablicy do listy\n";
        exit(-1);
    }
    //utworzenie listy
    ArrayList list(std::stoi(argv[1]));
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