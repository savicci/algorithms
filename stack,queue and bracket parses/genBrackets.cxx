#include<iostream>
#include<stack>
using std::cout;
using std::endl;
using std::cin;

class Generator{
    public:
    Generator(int l);           //konstruktor; l-dlugosc wyrazenia  -TODO zrobic zeby losowalo pierwszy znak w konsturkorze  
    ~Generator() { delete[] exp;}

    void push();                //dodaje znak do exp i na stos
    void pop();                 //dodaje znak do exp i wyrzuca z stosu
    void print();               //wypisuje exp na std::cout
    void automate_good();       //wykonuje wszystkie operacje-tworzy poprawne wyrazenie
    void automate_bad();        //tworzy bledne wyrazenie( nie zawsze )

    //generuje liczbe parzysta w przedziale [f-l), jesli y!=0 to zaokragla do parzystej
    static int random(int f,int l, bool y=false){
        int x=rand()%(l-f)+f;
        if(x%2 && y==true) return x-1;
        else return x;
    } 

    private:
    void first();         //losuje pierwszy znak
    char* exp;            //wyrazenie
    int pos;              //pozycja w wyrazeniu
    std::stack<char> st;  //stos do przechowywania informacji
    int len;              //dlugosc wyrazenia

};

void Generator::first(){
    if(random(0,100)<50){
        st.push('[');
        exp[pos]='[';
        pos++;
    }else{
        st.push('(');
        exp[pos]='(';
        pos++;
    }
}

Generator::Generator(int l)
:pos(0),len(l)
{
    exp=new char[l];
    first();
}

void Generator::push(){
    int x=random(0,100);
    if(x<50){
        st.push('[');
        exp[pos]='[';
        pos++;
    }
    else{
        st.push('(');
        exp[pos]='(';
        pos++;
    }
}

void Generator::pop(){
    if(st.top()=='['){
        st.pop();
        exp[pos]=']';
        pos++;
    }
    else{
        st.pop();
        exp[pos]=')';
        pos++;
    }
}

void Generator::print(){
    for(int i=0;i<len;i++)
        cout<<exp[i];
    cout<<endl;
}

void Generator::automate_good(){
    for(int i=1;i<len;i++){
        if(st.size()==len-i) pop();
        else push();
    }
    print();
}

void Generator::automate_bad(){
    for(int i=1;i<len;i++){
        int x=random(0,100);
        if(x<25){
            exp[pos]='(';
            pos++;
        }
        else if(x<50){
            exp[pos]=')';
            pos++;
        }
        else if(x<75){
            exp[pos]='[';
            pos++;
        }
        else{
            exp[pos]=']';
            pos++;
        }
    }
    print();
}


int main(int argc, char* argv[])
{
    if(argc!=2){
        std::cerr<<"Podaj liczbe wyrazen do wygenerowania"<<endl;
        return -1;
    }

    int num=std::stoi(argv[1]); // liczba wyrazen

    //glowna petla programu
    for(int i=0;i<num;i++){
        int choose=Generator::random(0,100);
        Generator g(Generator::random(2,12,true)); // obiekt o dlugosc od 2 do 12
        if(choose<50) g.automate_good();           //poprawne
        else g.automate_bad();                     //zle
    }
  
    return 0;
}