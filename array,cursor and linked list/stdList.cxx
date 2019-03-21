//by Grzegorz Koziol
#include<iostream>
#include<list>
#include<string>
using std::cin;
using std::cout;
using std::endl;


void find(std::list<int>& l,std::string s){
    int val=std::stoi(s);
    for(int i : l){
        if(i==val){
            cout<<"TRUE"<<endl;
            return;
        }
    }
    cout<<"FALSE"<<endl;
}

int main(int argc, char* argv[]){

    if(argc!=2){
        std::cerr<<"Podaj rozmiar tablicy do listy\n";
        exit(-1);
    }
    //utworzenie listy
    std::list<int> list;
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
                temp=list.front();
                list.pop_front();
                cout<<"Sciagam "<<temp<<" z poczatku listy"<<endl;
                break;

                case 'b'://usun ostatni element
                if(list.empty()){
                cout<<"EMPTY"<<endl;
                    break;
                }
                temp=list.back();
                list.pop_back();
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
                find(list,input);//lepiej bylo upchnac to w funkcje
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