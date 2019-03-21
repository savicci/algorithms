#include<iostream>
#include<string>
#include<queue>
using std::cout;
using std::endl;
using std::cin;


int main(int argc, char* argv[])
{
        //blok programu  
    try
    {
        std::queue<int> kolejka;

        //czytanie pierwszego znaku
        std::string input;
        cin>>input;
        cout<<"Liczba polecen: "<<input<<endl;

        while(cin>>input){
            switch(input[0]){
                case 'A'://dodaj liczbe do kolejki
                cin>>input;
                kolejka.push(std::stoi(input));
                cout<<"Wstawiono element "<<input<<" do kolejki\n";
                break;

                case 'D'://zdejmij element z poczatku kolejki
                if(!kolejka.empty()) cout<<"Zdejmuje z kolejki element " <<kolejka.front()<<endl;
                else cout<<"EMPTY"<<endl;
                break;

                case 'S'://wypisuje rozmiar kolejki
                cout<<"Rozmiar kolejki wynosi "<<kolejka.size()<<" elementow"<<endl;
                break;

                case 'F'://wczytaj liczbe i nic z nia nie rob 
                cin>>input;                
                break;

                default:
                throw "Nieznane polecenie";
                break;
            }
        }
    }
    catch(std::exception& e)
    {
        std::cerr<<e.what()<<endl;
    }catch(const char* msg){
        std::cerr<<msg<<endl;
    }catch(...){
        std::cerr<<"Wystapil niespodziewany blad"<<endl;
    }
    
    cout<<"Koniec programu"<<endl;

    return 0;
}