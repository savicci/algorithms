#include<iostream>
#include<stack>
#include<string>
using std::cin;
using std::cout;




int main(int argc, char* argv[])
{
    std::string input;

    while(cin>>input){
        std::stack<char> stos;
        for(int i=0;i<input.length();i++){
            //dodawanie znakow otwierajacych
            if(input[i]=='('){
                stos.push('(');
                continue;
                }
            else if(input[i]=='['){
                stos.push('[');
                continue;
            }


            if(input[i]==')' && !stos.empty() && stos.top()=='('){
                stos.pop();
                continue;
            }
            else if(input[i]==']' && !stos.empty() && stos.top()=='['){
                stos.pop();
                continue;
            }
            else{
                cout<<input<<" BAD"<<std::endl;
                break;
            }  
        }
            if(stos.empty()) cout<<input<<" GOOD"<<std::endl;
    }    

    return 0;
}