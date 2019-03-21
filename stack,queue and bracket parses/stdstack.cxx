//by Grzegorz Koziol
//program symulujacy dzialanie stosu oparty o stos z biblioteki standardowej
#include<iostream>
#include<stack>
#include<vector>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[])
{
    //blok programu
    try{
        std::stack<int> stos;
        
        //czytanie pierwszego znaku
        std::string input;
        cin>>input;
        cout<<"Liczba polecen: "<<input<<endl;

        //wlasciwa petla wykonujaca operacje
        while(cin>>input){

            switch(input[0]){

                case 'A'://poloz liczbe na stos
                cin>>input;
                stos.push(std::stoi(input));
                cout<<"Wstawiono element "<<input<<" na stos\n";
                break;

                case 'D'://zdejmuje element ze stosu
                if(!stos.empty()){
                    cout<<"Zdejmuje ze stosu element "<< stos.top() <<endl;
                    stos.pop();
                }
                else cout<<"EMPTY"<<endl; 
                break;

                case 'S'://wypisuje rozmiar stosu
                cout<<"Rozmiar stosu wynosi "<<stos.size()<<" elementow"<<endl;
                break;

                case 'F': ///wczytaj liczbe i nic z nia nie rob                
                cin>>input;
                break;

                default:
                throw "Nieznane polecenie";
                break;
            }
        }
    }
    catch(std::exception& e){
        std::cerr<<e.what()<<endl;
    }catch(...){
        std::cerr<<"Wystapil niespodziewany blad"<<endl;
    }

    cout<<"Koniec programu"<<endl;
    return 0;
}